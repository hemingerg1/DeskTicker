
#include "myUtils.hpp"

#include <Arduino.h>
#include <lvgl.h>
#include <WiFi.h>
#include <FS.h>
#include <SD.h>
#include <Preferences.h>

#include "uiFiles/ui.h"

static const char *myTAG = "myUtils.cpp";

/***********************************************************************/
/*****************************  Basic Utils  ***************************/
/***********************************************************************/
TaskHandle_t uiTaskHandle = NULL;
TaskHandle_t dataTaskHandle = NULL;
TaskHandle_t webTaskHandle = NULL;

TimerHandle_t timeoutTimer;

SemaphoreHandle_t prefsmutex = NULL;
ESP32Time rtc(0);
Preferences prefs;
short int screenTimeout = 5;     // in minutes
short int symbolChangeTime = 10; // in seconds
short int priceHistLen = 60;     // in days
bool noWifiInit = true;

// wrapper function to call settingsInit() from a task
void settingsInitTask(void *parameters)
{
    settingsInit();

    // stop the timeout if task completed
    if (timeoutTimer != NULL)
    {
        xTimerStop(timeoutTimer, 0);
    }

    vTaskDelete(NULL);
}

// function to get settings from NVS storage
void settingsInit()
{
    ESP_LOGD(myTAG, "Getting settings from NVS storage...");

    xSemaphoreTake(prefsmutex, portMAX_DELAY);
    if (prefs.begin("settings", false))
    {
        symbolChangeTime = prefs.getShort("symChT", 10);
        screenTimeout = prefs.getShort("slpT", 5);
        priceHistLen = prefs.getShort("histLen", 60);
        prefs.end();
        ESP_LOGI(myTAG, "Got settings from NVS storage.");
    }
    else
    {
        ESP_LOGE(myTAG, "*********Error opening NVS storage*********");
    }
    xSemaphoreGive(prefsmutex);
}

// function to connect to wifi
void wificon(void)
{
    WiFi.disconnect(true);
    delay(500);
    WiFi.setHostname("DeskTicker");
    WiFi.mode(WIFI_STA);

    // get SSID and PASSWORD from NVS storage
    String SSID = "";
    String PASSWORD = "";
    ESP_LOGD(myTAG, "Getting SSID and PASSWORD from NVS storage...");
    int i = 0;
    while (SSID == "" || PASSWORD == "")
    {
        xSemaphoreTake(prefsmutex, portMAX_DELAY);
        prefs.begin("settings", false);
        SSID = prefs.getString("SSID", "");
        PASSWORD = prefs.getString("PASS", "");
        prefs.end();
        xSemaphoreGive(prefsmutex);

        if (SSID == "" || PASSWORD == "")
        {
            if (i == 0)
            {
                ESP_LOGI(myTAG, "WIFI credentials not found");
            }
            i++;
            vTaskDelay(5000);
        }
    }
    noWifiInit = false;

    // connect to wifi
    ESP_LOGD(myTAG, "Connecting to WiFi...");
    WiFi.begin(SSID, PASSWORD);
    vTaskDelay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        vTaskDelay(500);
        if (t > 20)
        {
            ESP_LOGW(myTAG, "Unable to connect to WiFi.");
            reboot();
        }
    }

    lv_label_set_text_fmt(ui_labWebAddress, "http://%s", WiFi.localIP().toString().c_str());
    lv_textarea_set_text(ui_taWifiSsid, SSID.c_str());

    ESP_LOGI(myTAG, "WiFi connected. IP = %s", WiFi.localIP().toString());
}

// function to sync the ESP32's rtc with NTP server
void timeSync(const char *tzInfo, const char *ntpServer1, const char *ntpServer2)
{
    configTzTime(tzInfo, ntpServer1, ntpServer2);

    // Wait till time is synced
    ESP_LOGD(myTAG, "Syncing time");
    int i = 0;
    while (time(nullptr) < 1000000000l && i < 40)
    {
        delay(500);
        i++;
    }

    // Show time
    time_t tnow = time(nullptr);
    ESP_LOGI(myTAG, "Synchronized time: %s", ctime(&tnow));

    // if time synce failed, reboot
    if (rtc.getYear() < 2020)
    {
        ESP_LOGE(myTAG, "Time sync failed, rebooting...");
        reboot();
    }
}

void reboot(void)
{
    ESP_LOGW(myTAG, "Rebooting...");
    saveLogToSD();
    vTaskDelay(2000);
    ESP.restart();
}

void timeoutReboot(TimerHandle_t xTimer)
{
    ESP_LOGE(myTAG, "Settings init timer expired. Rebooting...");
    reboot();
}

/***********************************************************************/
/*****************************  SD card Utils  *************************/
/***********************************************************************/
SemaphoreHandle_t SDmutex = NULL;

const char *htmlFilePath = "/index.htm";
const char *tickerListFilePath = "/tickerList.csv";

// Function to return a list of all files in the SD card
String listDir(fs::FS &fs, const char *dirname)
{
    ESP_LOGD(myTAG, "Listing directory: %s", dirname);
    String result;
    if (xSemaphoreTake(SDmutex, 5000) == pdTRUE)
    {
        File root = fs.open(dirname, "r");
        if (!root)
        {
            result = "Failed to open directory";
            xSemaphoreGive(SDmutex);
            return result;
        }
        if (!root.isDirectory())
        {
            result = "Not a directory";
            xSemaphoreGive(SDmutex);
            return result;
        }

        result += "[\n";
        while (File entry = root.openNextFile())
        {
            if (String(entry.name()) == "System Volume Information")
            {
                continue;
            }
            if (entry.isDirectory())
            {
                char buffer[24];
                time_t t = entry.getLastWrite();
                struct tm *writeTime = localtime(&t);
                strftime(buffer, 24, "%F %T", writeTime);

                result += " {";
                result += "\"type\": \"dir\", ";
                result += "\"name\": \"" + String(entry.name()) + "\", ";
                result += "\"last write\": " + String(buffer);
                result += "}\n";
                while (File entry2 = entry.openNextFile())
                {
                    char buffer2[24];
                    time_t t2 = entry2.getLastWrite();
                    struct tm *writeTime2 = localtime(&t2);
                    strftime(buffer2, 24, "%F %T", writeTime2);

                    result += "    {";
                    result += "\"type\": \"file\", ";
                    result += "\"name\": \"" + String(entry2.name()) + "\", ";
                    result += "\"size\": " + String(entry2.size()) + ", ";
                    result += "\"last write\": " + String(buffer2);
                    result += "}\n";
                    entry2.close();
                }
                entry.close();
            }
            else
            {
                char buffer[24];
                time_t t = entry.getLastWrite();
                struct tm *writeTime = localtime(&t);
                strftime(buffer, 24, "%F %T", writeTime);

                result += " {";
                result += "\"type\": \"file\", ";
                result += "\"name\": \"" + String(entry.name()) + "\", ";
                result += "\"size\": " + String(entry.size()) + ", ";
                result += "\"last write\": " + String(buffer);
                result += "}\n";
                entry.close();
            }
        }
        result += "]";
        root.close();
        xSemaphoreGive(SDmutex);
    }
    else
    {
        result = "SD card busy trying again later.";
    }
    return result;
}

// print the SD card usage
void printSdUssage(void)
{
    float totalMBytes = SD.totalBytes() / (1024 * 1024);
    float usedKBytes = SD.usedBytes() / (1024);
    ESP_LOGD(myTAG, "SD Card Total Size (MB): %.2f", totalMBytes);
    ESP_LOGD(myTAG, "SD Card Used Space (kB): %.2f", usedKBytes);
}

/***********************************************************************/
/*****************************  Data Utils  ****************************/
/***********************************************************************/
SemaphoreHandle_t TickListmutex = NULL;
const ushort maxTickers = 30;
const ushort tickerListColNum = 3;
bool updateTickerList = false;
bool updateHistLength = false;
ushort numTickers = 0;
bool marketOpen = false;
ticker tickerList[maxTickers];

/***********************************************************************/
/*****************************  Logging Utils  *************************/
/***********************************************************************/
SemaphoreHandle_t logmutex;
ushort logFileNum = 0;
bool needNewLogFile = false;
const char *logFileDir = "/logs";
char logTempBuf[256] = "";
const size_t logBuf_size = 1024;
char logBuf[logBuf_size];

// fucntion to init log file number at start up
void logFilesInit()
{
    // check if logs directory exists and create it if not
    if (!SD.exists(logFileDir))
    {
        Serial.println("Log files directory does not exist. Creating it now.");
        SD.mkdir(logFileDir);
    }

    // get the largest file name
    File dir = SD.open(logFileDir);
    while (File file = dir.openNextFile())
    {
        String filename = file.name();
        ushort fileNum = filename.substring(0, filename.length() - 4).toInt();

        if (fileNum > logFileNum)
        {
            logFileNum = fileNum;
        }
        file.close();
    }
    dir.rewindDirectory();
    dir.close();
}

// function to add log message to buffer
int handleNewLogMessage(const char *format, va_list args)
{
    // format message in a temp buffer
    int ret = vsnprintf(logTempBuf, sizeof(logTempBuf), format, args);
    Serial.print(logTempBuf);

    if (xSemaphoreTake(logmutex, 5000) == pdTRUE)
    {
        // Check the length of the current buffer and the formatted message
        size_t currentLength = strlen(logBuf);
        size_t messageLength = strlen(logTempBuf);

        // Check if the message will fit in the remaining buffer space
        if (currentLength + messageLength + 1 >= logBuf_size)
        {
            Serial.println("Saving log buffer to file.");
            saveLogToSD();
            currentLength = strlen(logBuf);
        }
        // Append the formatted message to the buffer
        strncat(logBuf, logTempBuf, logBuf_size - currentLength - 1);

        xSemaphoreGive(logmutex);
    }
    else
    {
        Serial.println("Failed to take log mutex. Above message not saved");
    }

    // reset the temp buffer
    logTempBuf[0] = '\0';

    return ret;
}

// function to save log buffer to sd card then empty buffer
void saveLogToSD()
{
    // Write buffer to file
    File file = SD.open(String(logFileDir) + "/" + String(logFileNum) + ".txt", FILE_APPEND);
    if (!file)
    {
        Serial.println("Failed to open log file for writing");
        return;
    }
    file.print(logBuf);
    file.printf("Buffer Saved: %s\n", rtc.getTime("%D %T").c_str());

    // If log file is too large set flag to create a new file
    if (file.size() > 100000)
    {
        needNewLogFile = true;
    }

    file.close();

    // reset the buffer
    logBuf[0] = '\0';
}

// function to create a new log file
void createNewLogFile()
{
    logFileNum++;

    // create new log file
    File newFile = SD.open(String(logFileDir) + "/" + String(logFileNum) + ".txt", FILE_WRITE);
    newFile.printf("File Created: %s\n", rtc.getTime("%D %T").c_str());
    newFile.close();

    // delete old log files
    File dir = SD.open(logFileDir);
    while (File file = dir.openNextFile())
    {
        String filename = file.name();
        ushort fileNum = filename.substring(0, filename.length() - 4).toInt();

        if (fileNum < logFileNum - 1 && logFileNum > 1)
        {
            file.close();
            ESP_LOGD(myTAG, "Deleting log file %s", filename);
            SD.remove(String(logFileDir) + "/" + filename);
        }
        else
        {
            file.close();
        }
    }
    dir.rewindDirectory();
    dir.close();

    needNewLogFile = false;
}