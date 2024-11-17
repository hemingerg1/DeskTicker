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