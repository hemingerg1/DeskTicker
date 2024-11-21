#include "data.hpp"

#include "myUtils.h"
#include "secrets.h"

#include <Arduino.h>
#include <WiFi.h>
#include <FS.h>
#include <SD.h>
#include <CSV_Parser.h>

void loadTickerList(void)
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    File file = SD.open(tickerListFilePath);
    if (!file)
    {
        Serial.println("Failed to open ticker list");
        xSemaphoreGive(SDmutex);
        return;
    }
    CSV_Parser cp(/*format*/ "ucssuc", /*has_header*/ true, /*delimiter*/ ',');
    if (cp.readSDfile(tickerListFilePath))
    {
        cp.print();
        uint8_t *ids = (uint8_t *)cp["id"];
        char **symbols = (char **)cp["symbol"];
        char **discs = (char **)cp["disc"];
        uint8_t *sources = (uint8_t *)cp["source"];

        if (ids && symbols) // check if the arrays are not null
        {
            for (int row = 0; row < cp.getRowsCount(); row++)
            {
                tickerList[row].id = ids[row];
                tickerList[row].symbol = symbols[row];
                tickerList[row].disc = discs[row];
                tickerList[row].source = sources[row];
            }
        }
        else
        {
            Serial.println("ERROR: Ticker list CSV file was not parsed correctly.");
        }
    }
}

void tickerListUpdate(void)
{
    loadTickerList();
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    File dir = fs.open("/data/");
    if (!dir)
    {
        Serial.println("Could not open /data directory.");
        xSemaphoreGive(SDmutex);
        return;
    }
    // check if files exist in ticker list
    while (File entry = dir.openNextFile())
    {
        tickerList[row].symbol;
        String filename = entry.name();
        String symbol = filename.substring(0, filename.length() - 4); // Remove the .csv extension

        // Check if this symbol is in the tickerList
        bool found = false;
        for (int i = 0; i < maxTickers; i++)
        {
            if (tickerList[i].symbol == symbol)
            {
                found = true;
                break;
            }
        }
        // If the symbol is not in the tickerList, delete the CSV file
        if (!found)
        {
            Serial.print("Deleting file: ");
            Serial.println(filename);
            SD.remove(filename);
        }
    }
    entry.close();

    // Check if any symbols in the tickerList do not have an associated CSV file
    for (int i = 0; i < maxTickers; i++)
    {
        bool fileExists = false;

        while (File entry = dir.openNextFile())
        {
            String filename = entry.name();
            if (filename.endsWith(".csv") && filename.substring(0, filename.length() - 4) == tickerList[i].symbol)
            {
                fileExists = true;
                break;
            }

            entry.close(); // Close the file to avoid memory issues
        }
        if (!fileExists)
        {
            // If no CSV file exists for this symbol, call getData()
            Serial.print("No CSV found for symbol: ");
            Serial.println(tickerList[i].symbol);
            getData(tickerList[i]);
        }
    }
    dir.close();
}

void dataTask(void *parameters)
{
    for (;;)
    {
        if (updateTickerList)
        {
            Serial.println("Updating ticker list");
            loadTickerList();
        }

        Serial.println("Running dataTask");
        vTaskDelay(1000);
    }
}