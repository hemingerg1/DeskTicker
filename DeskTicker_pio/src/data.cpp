#include "data.hpp"

#include "myUtils.hpp"

#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Time.h>
#include <FS.h>
#include <SD.h>
#include <DatabaseOnSD.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#include "esp_log.h"
#include "esp32-hal-log.h"

#define PRINT_HEADERS false
#define SC_Request_Delay 2000
#define FAIL_COUNT_LIMIT 5

static const char *myTAG = "data.cpp";

static const String DATA_DIRECTORY = "/data";
MyTable listTable(tickerListFilePath);

ushort updateInterval = 5; // in minutes
bool eodUpdate = false;
bool gotEOD = false;
bool gotNightlyCheck = false;
ushort failCount = 0;

const char *scURLBase = "stockcharts.com";
const char *scHistURLPath = "/quotebrain/history/d"; // d = daily, 5 = 5min
const char *scTodayURLPath = "/quotebrain/quote";
const char *userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:132.0) Gecko/20100101 Firefox/132.0";

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void dataTask(void *parameters)
{
    // Serial.println("Starting dataTask");

    // check if the market is open
    isMarketOpen();

    unsigned long lastUpdate = 0;

    loadTickers();

    // check if csv files are up to date and get todays price
    for (int i = 0; i < numTickers; i++)
    {
        if (!isCsvFileDataUpToDate(tickerList[i].symbol))
        {
            ESP_LOGI(myTAG, "%s.csv is outdated. Updating now...", tickerList[i].symbol);
            updateCsvFile(i);
            vTaskDelay(SC_Request_Delay);
        }
        getTodayData(i);
        vTaskDelay(SC_Request_Delay);
    }
    lastUpdate = millis();

    while (1)
    {
        // check if the market is open
        isMarketOpen();

        // updates data if ticker list is changed from web page
        if (updateTickerList)
        {
            ESP_LOGD(myTAG, "Updating ticker list and data");
            dataDirUpdate();
            for (int i = 0; i < numTickers; i++)
            {
                getTodayData(i);
                vTaskDelay(SC_Request_Delay);
            }
            updateTickerList = false;
        }

        if (updateHistLength)
        {
            ESP_LOGD(myTAG, "Updating CSV files with new historic data length");
            updateAllCsvFiles();
            updateHistLength = false;
        }

        if (marketOpen)
        {
            // updates the current price every <updateInterval> minutes
            if (millis() - lastUpdate > updateInterval * 60000 || millis() < lastUpdate)
            {
                for (int i = 0; i < numTickers; i++)
                {
                    getTodayData(i);
                    vTaskDelay(SC_Request_Delay);
                }
                lastUpdate = millis();
            }
        }
        else if (eodUpdate)
        {
            // update csv files at the end of the day
            updateAllCsvFiles();
            eodUpdate = false;
            gotEOD = true;
        }

        // check if any data downloads needs to be retried
        checkRetryFlags();

        vTaskDelay(5000);
    }
}

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/

// function to load tickerList from SD card csv file
void loadTickers(void)
{
    xSemaphoreTake(SDmutex, 10000);
    if (listTable.countCols() == tickerListColNum)
    {
        numTickers = listTable.countRows() - 1;
        ESP_LOGV(myTAG, "Number of Tickers: %d", numTickers);
        xSemaphoreTake(TickListmutex, portMAX_DELAY);
        ESP_LOGV(myTAG, "Ticker List:");
        for (int row = 0; row < numTickers; row++)
        {
            tickerList[row].id = listTable.readCell(row + 1, 0).toInt();
            tickerList[row].symbol = listTable.readCell(row + 1, 1);
            tickerList[row].disc = listTable.readCell(row + 1, 2);
            ESP_LOGV(myTAG, "%d, %s, %s", tickerList[row].id, tickerList[row].symbol.c_str(), tickerList[row].disc.c_str());
            tickerList[row].csvRetry = false;
            tickerList[row].curPricRetry = false;
            tickerList[row].RetryCount = 0;
        }
        xSemaphoreGive(TickListmutex);
    }
    else
    {
        ESP_LOGE(myTAG, "ERROR: Ticker list CSV file was not parsed correctly.");
    }
    xSemaphoreGive(SDmutex);
}

// Function to synce csv files on SD card with ticker list
void dataDirUpdate(void)
{
    loadTickers();
    xSemaphoreTake(SDmutex, portMAX_DELAY);

    // check if data directory exists and create it if not
    if (!SD.exists(DATA_DIRECTORY))
    {
        Serial.println("Data files directory does not exist. Creating it now.");
        SD.mkdir(DATA_DIRECTORY);
    }
    // open the data directory
    File dir = SD.open(DATA_DIRECTORY);
    if (!dir)
    {
        xSemaphoreGive(SDmutex);
        ESP_LOGE(myTAG, "Could not open %s directory.", DATA_DIRECTORY);
        return;
    }
    // check if files exist for tickers not in ticker list and delete them
    xSemaphoreTake(TickListmutex, portMAX_DELAY);
    while (File entry = dir.openNextFile())
    {
        String filename = entry.name();
        String symbol = filename.substring(0, filename.length() - 4); // Remove the .csv extension

        // Check if this symbol is in the tickerList
        bool found = false;
        for (int i = 0; i < numTickers; i++)
        {
            if (tickerList[i].symbol == symbol)
            {
                found = true;
                break;
            }
        }
        entry.close();
        // If the symbol is not in the tickerList, delete the CSV file
        if (!found)
        {
            ESP_LOGI(myTAG, "Deleting file: %s", filename);
            SD.remove(DATA_DIRECTORY + "/" + filename);
        }
    }
    dir.rewindDirectory();

    // Check if any symbols in the tickerList do not have an associated CSV file
    for (int i = 0; i < numTickers; i++)
    {
        bool fileExists = false;

        while (File entry = dir.openNextFile())
        {
            String filename = entry.name();
            if (filename.endsWith(".csv") && filename.substring(0, filename.length() - 4) == tickerList[i].symbol)
            {
                fileExists = true;
                ESP_LOGD(myTAG, "Found CSV file for symbol: %s", tickerList[i].symbol);
                break;
            }

            entry.close(); // Close the file to avoid memory issues
        }
        dir.rewindDirectory();
        if (!fileExists)
        {
            // If no CSV file exists for this symbol, call getData()
            ESP_LOGI(myTAG, "No CSV found for symbol: %s", tickerList[i].symbol);
            String csvData = "";
            csvData = getHistoricData(i, priceHistLen);
            if (csvData != "")
            {
                File file = SD.open(DATA_DIRECTORY + "/" + tickerList[i].symbol + ".csv", FILE_WRITE);
                if (!file)
                {
                    ESP_LOGW(myTAG, "Failed to open file for writing");
                }
                else
                {
                    // Write the received CSV data to the file
                    file.print(csvData);
                    file.close();
                    ESP_LOGI(myTAG, "Data saved to %s/%s.csv", DATA_DIRECTORY, tickerList[i].symbol);
                }
            }
            vTaskDelay(SC_Request_Delay); // Delay to avoid sending too many requests at once
        }
    }
    dir.close();
    xSemaphoreGive(TickListmutex);
    xSemaphoreGive(SDmutex);
}

// Function to calculate the date N days ago in YYYYMMDD format
String getStartDate(const int length)
{
    // Get the current time
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // Subtract N days (30 * 24 * 60 * 60 seconds)
    now -= (length * 24 * 60 * 60);
    localtime_r(&now, &timeinfo);

    // Format the date as YYYYMMDD
    char dateBuffer[9];
    snprintf(dateBuffer, sizeof(dateBuffer), "%04d%02d%02d",
             timeinfo.tm_year + 1900,
             timeinfo.tm_mon + 1,
             timeinfo.tm_mday);
    ESP_LOGV(myTAG, "Start date: %s", String(dateBuffer));
    return String(dateBuffer);
}

// Function to get price data from StockCharts.com and save to CSV file
String getHistoricData(const int tickerNum, const int length)
{
    bool success = false;
    String symbol = tickerList[tickerNum].symbol;
    ESP_LOGV(myTAG, "Downloading data for %s, length = %d", symbol, length);
    String csvData = "";
    for (int j = 0; j < 2; j++)
    {
        if (j > 0)
        {
            ESP_LOGW(myTAG, "Attempt %d failed to get todays price for %s", j, symbol);
            ESP_LOGD(myTAG, "Waiting %ds before retry...", SC_Request_Delay * j / 1000);
        }
        vTaskDelay(SC_Request_Delay * j);
        WiFiClientSecure client;
        client.setInsecure();
        client.setTimeout(30);
        if (!client.connect(scURLBase, 443))
        {
            char err_buf[100];
            if (client.lastError(err_buf, 100) < 0)
            {
                ESP_LOGW(myTAG, "SC connect failed: %s", err_buf);
            }
            else
            {
                ESP_LOGW(myTAG, "SC connection error");
            }
            client.stop();
            continue;
        }

        //  build query string
        String queryParams = String("?symbol=") + symbol + "&start=" + getStartDate(length);

        // Construct the HTTP request
        String request = String("GET ") + scHistURLPath + queryParams + " HTTP/1.0\r\n" +
                         "Host: " + scURLBase + "\r\n" +
                         "User-Agent: " + userAgent + "\r\n" +
                         "Connection: close\r\n\r\n";

        // Send the request
        client.print(request);

        // Use to print out headers
        while (client.connected() || client.available())
        {
            if (client.available())
            {
                String line = client.readStringUntil('\n');
                if (PRINT_HEADERS)
                {
                    Serial.println(line);
                }
                if (line == "\r")
                {
                    // Headers received, break to read body
                    break;
                }
            }
        }

        /*
        // Print HTTP status
        char status[32] = {0};
        client.readBytesUntil('\r', status, sizeof(status));
        Serial.print("Status: ");
        Serial.println(status);

        // Skip HTTP headers
        char endOfHeaders[] = "\r\n\r\n";
        if (!client.find(endOfHeaders))
        {
            Serial.println(F("Invalid response"));
            client.stop();
            continue;
        }
        */

        // Create a filter to extract the desired fields
        JsonDocument filter;
        filter["intervals"][0]["end"]["time"] = true;
        filter["intervals"][0]["close"] = true;
        // Parse the JSON response
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, client, DeserializationOption::Filter(filter));

        client.stop();

        if (error)
        {
            ESP_LOGW(myTAG, "Failed to parse JSON: %s", error.c_str());
            continue;
        }
        // Print the JSON document
        // serializeJsonPretty(doc, Serial);

        // parse data to CSV
        csvData += "Date,Close\n";
        JsonArray intervals = doc["intervals"];
        for (JsonObject interval : intervals)
        {
            csvData += interval["end"]["time"].as<String>().substring(0, 10) + "," + interval["close"].as<String>() + "\n";
        }
        success = true;
        // Serial.println("CSV Data:");
        // Serial.println(csvData);
        break;
    }
    if (!success)
    {
        tickerList[tickerNum].csvRetry = true;
        ESP_LOGW(myTAG, "Failed to get historic data for %s", symbol);
        failCount++;
        if (failCount > FAIL_COUNT_LIMIT)
        {
            ESP_LOGE(myTAG, "Too many failed attempts to get data. Rebooting...");
            reboot();
        }
        return "";
    }

    return csvData;
}

// Function to get todays price data from StockCharts.com
void getTodayData(const int tickerNum)
{
    bool success = false;
    xSemaphoreTake(TickListmutex, portMAX_DELAY);
    ESP_LOGV(myTAG, "Getting todays price for %s", tickerList[tickerNum].symbol);
    for (int j = 0; j < 2; j++)
    {
        if (j > 0)
        {
            ESP_LOGW(myTAG, "Attempt %d to get todays price for %s failed", j + 1, tickerList[tickerNum].symbol);
            ESP_LOGD(myTAG, "Waiting %ds before retry...", SC_Request_Delay * j / 1000);
        }
        vTaskDelay(SC_Request_Delay * j);
        WiFiClientSecure client;
        client.setInsecure();
        client.setTimeout(30);
        if (!client.connect(scURLBase, 443))
        {
            char err_buf[100];
            if (client.lastError(err_buf, 100) < 0)
            {
                ESP_LOGW(myTAG, "SC connect failed: %s", err_buf);
            }
            else
            {
                ESP_LOGW(myTAG, "SC connection error");
            }
            client.stop();
            continue;
        }

        //  build query string
        String queryParams = String("?symbol=") + tickerList[tickerNum].symbol + "&format=json";

        // Construct the HTTP request
        String request = String("GET ") + scTodayURLPath + queryParams + " HTTP/1.0\r\n" +
                         "Host: " + scURLBase + "\r\n" +
                         "User-Agent: " + userAgent + "\r\n" +
                         "Connection: close\r\n\r\n";

        // Send the request
        client.print(request);

        // Use to print out headers
        while (client.connected() || client.available())
        {
            if (client.available())
            {
                String line = client.readStringUntil('\n');
                if (PRINT_HEADERS)
                {
                    Serial.println(line);
                }
                if (line == "\r")
                {
                    // Headers received, break to read body
                    break;
                }
            }
        }

        /*
        // Print HTTP status
        char status[32] = {0};
        client.readBytesUntil('\r', status, sizeof(status));
        // Serial.print("Status: ");
        // Serial.println(status);

        // Skip HTTP headers
        char endOfHeaders[] = "\r\n\r\n";
        if (!client.find(endOfHeaders))
        {
            Serial.println(F("Invalid response"));
            client.stop();
            continue;
        }
        */

        // Create a filter to extract the desired fields
        JsonDocument filter;
        filter[0]["close"] = true;
        filter[0]["closeYesterday"] = true;
        // Parse the JSON response
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, client, DeserializationOption::Filter(filter));

        client.stop();

        if (error)
        {
            ESP_LOGW(myTAG, "Failed to parse JSON: %s", error.c_str());
            continue;
        }
        // Print the JSON document
        // serializeJson(doc, Serial);

        float todaysClose = doc[0]["close"].as<float>();
        float CloseYesterday = doc[0]["closeYesterday"].as<float>();
        if (todaysClose != 0 && CloseYesterday != 0)
        {
            tickerList[tickerNum].price = todaysClose;
            tickerList[tickerNum].change = todaysClose - CloseYesterday;
            tickerList[tickerNum].changePct = (tickerList[tickerNum].change / CloseYesterday) * 100;
            ESP_LOGD(myTAG, "Ticker: %s, Price: %.2f, Change: %.2f, ChangePct: %.2f%%", tickerList[tickerNum].symbol.c_str(), tickerList[tickerNum].price, tickerList[tickerNum].change, tickerList[tickerNum].changePct);
            success = true;
        }
        else
        {
            continue;
        }
        break;
    }
    xSemaphoreGive(TickListmutex);

    if (!success)
    {
        tickerList[tickerNum].curPricRetry = true;
        ESP_LOGW(myTAG, "Failed to get todays price for %s", tickerList[tickerNum].symbol);
        failCount++;
        if (failCount > FAIL_COUNT_LIMIT)
        {
            ESP_LOGE(myTAG, "Too many failed attempts to get data. Rebooting...");
            reboot();
        }
    }
    else
    {
        tickerList[tickerNum].curPricRetry = false;
    }
}

// Function to check if market is open
void isMarketOpen(void)
{
    const int dow = rtc.getDayofWeek();
    const int h = rtc.getHour(true);
    const int m = rtc.getMinute();

    if (dow >= 1 && dow <= 5)
    {
        if (h == 9 && m >= 30)
        {
            marketOpen = true;
            gotEOD = false;
            gotNightlyCheck = false;
        }
        else if (h == 16 && m <= 15)
        {
            marketOpen = true;
        }
        else if (h == 16 && m > 15 and !gotEOD)
        {
            marketOpen = false;
            eodUpdate = true;
        }
        else if (h > 9 && h < 16)
        {
            marketOpen = true;
        }
        else if (h == 23 && !gotNightlyCheck)
        {
            failCount = 0;
            for (int i = 0; i < numTickers; i++)
            {
                if (!isCsvFileDataUpToDate(tickerList[i].symbol))
                {
                    ESP_LOGI(myTAG, "%s.csv is outdated. Updating now...", tickerList[i].symbol);
                    updateCsvFile(i);
                    vTaskDelay(SC_Request_Delay);
                }
            }
            gotNightlyCheck = true;
        }
        else
        {
            marketOpen = false;
        }
    }
    else
    {
        marketOpen = false;
    }
}

// Function to update data csv files at end of day
void updateAllCsvFiles(void)
{
    ESP_LOGI(myTAG, "Updating all CSV data files");
    for (int i = 0; i < numTickers; i++)
    {
        updateCsvFile(i);
        vTaskDelay(SC_Request_Delay); // Delay to avoid sending too many requests
    }
}

// Function to update a CSV data file
bool updateCsvFile(const int tickerIndex)
{
    bool success = false;

    String symbol = tickerList[tickerIndex].symbol;

    String csvData = "";
    ESP_LOGD(myTAG, "Updating %s.csv l=%d", symbol, priceHistLen);
    csvData = getHistoricData(tickerIndex, priceHistLen);
    if (csvData != "")
    {
        File file = SD.open(DATA_DIRECTORY + "/" + symbol + ".csv", FILE_WRITE);
        if (!file)
        {
            ESP_LOGW(myTAG, "Failed to open %s/%s.csv for writing", DATA_DIRECTORY, symbol);
        }
        else
        {
            // Write the received CSV data to the file
            file.print(csvData);
            file.close();
            ESP_LOGI(myTAG, "Data successfully saved to %s/%s.csv", DATA_DIRECTORY, symbol);
            success = true;
        }
    }

    return success;
}

// Function to check if CSV data files are up todate
bool isCsvFileDataUpToDate(const String &symbol)
{
    MyTable table(DATA_DIRECTORY + "/" + symbol + ".csv");
    bool dataUpToDate = false;
    int rows = 0;
    rows = table.countRows();
    String lastDate;

    if (rows != 0)
    {
        lastDate = table.readCell(rows - 1, 0);
        int month = lastDate.substring(5, 7).toInt();
        int day = lastDate.substring(8, 10).toInt();
        ESP_LOGD(myTAG, "Last date in %s.csv: %d/%d", symbol, month, day);
        if (month == rtc.getMonth() + 1 && day == rtc.getDay())
        {
            dataUpToDate = true;
        }
        else if (rtc.getDayofWeek() == 0 || rtc.getDayofWeek() == 6) // if it is a weekend
        {
            if (abs(rtc.getDay() - day) < 3 || rtc.getDay() <= 2)
            {
                dataUpToDate = true;
            }
        }
    }

    return dataUpToDate;
}

// function to check for any retry flags in tickerList and retry getting data
void checkRetryFlags(void)
{
    // Check all tickers
    for (int i = 0; i < numTickers; i++)
    {
        // If ticker retry fails more than 3 times, only retry every 10th time
        if (tickerList[i].RetryCount < 3 || tickerList[i].RetryCount % 10 == 0)
        {
            if (tickerList[i].curPricRetry)
            {
                ESP_LOGW(myTAG, "[Out of norm] Retrying to get current price for %s", tickerList[i].symbol);
                getTodayData(i);
                vTaskDelay(SC_Request_Delay);
            }

            if (tickerList[i].csvRetry)
            {
                ESP_LOGW(myTAG, "[Out of norm] Retrying to update %s.csv", tickerList[i].symbol);
                if (updateCsvFile(i))
                {
                    tickerList[i].csvRetry = false;
                    tickerList[i].RetryCount = 0;
                }
                else
                {
                    tickerList[i].RetryCount++;
                }
                vTaskDelay(SC_Request_Delay);
            }
        }
        else
        {
            tickerList[i].RetryCount++;
        }
    }
}