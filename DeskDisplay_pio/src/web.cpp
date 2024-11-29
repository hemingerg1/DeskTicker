#include "web.hpp"

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SD.h>

#include "myUtils.h"

AsyncWebServer server(80);

// Function to serve the HTML file from SD card
void handleRoot(AsyncWebServerRequest *request)
{

    xSemaphoreTake(SDmutex, portMAX_DELAY);
    if (!SD.exists(htmlFilePath))
    {
        request->send(500, "text/plain", "Failed to read HTML file from SD card.");
        xSemaphoreGive(SDmutex);
        return;
    }
    Serial.println("Webserver: Sending index.html");
    request->send(SD, htmlFilePath, "text/html");
    xSemaphoreGive(SDmutex);
}

// Function to get the ticker list (GET /api/tickerlist)
void handleApiGet(AsyncWebServerRequest *request)
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    if (!SD.exists(tickerListFilePath))
    {
        request->send(500, "text/plain", "Failed to open ticker list CSV file.");
        xSemaphoreGive(SDmutex);
        return;
    }
    Serial.println("Webserver: Sending tickerList.csv");
    request->send(SD, tickerListFilePath, "text/csv");
    xSemaphoreGive(SDmutex);
}

// Function to handle POST requests (POST /api/tickerlist)
void handleApiPost(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
    Serial.println("Webserver: Received POST request for /api/tickerlist");

    if (request->method() != HTTP_POST)
    {
        request->send(405, "text/plain", "Method Not Allowed");
        return;
    }
    // Read the incoming CSV data from the POST request
    String csvData = "";
    // Append the received chunk to the buffer
    for (size_t i = 0; i < len; i++)
    {
        csvData += (char)data[i];
    }
    // Check if all data has been received
    if (index + len == total)
    {
        Serial.println("Webserver: Received CSV data");
        Serial.println(csvData);
        // Create or open the CSV file for writing
        xSemaphoreTake(SDmutex, portMAX_DELAY);
        File file = SD.open(tickerListFilePath, FILE_WRITE);
        if (!file)
        {
            request->send(500, "text/plain", "Failed to open CSV file for writing.");
            xSemaphoreGive(SDmutex);
            return;
        }
        // Write the received CSV data to the file
        file.print(csvData);
        file.close();
        xSemaphoreGive(SDmutex);
        request->send(200, "text/plain", "CSV data saved successfully.");
        updateTickerList = true;
    }
    else
    {
        request->send(500, "text/plain", "Error receiving CSV data.");
    }
}

// Called when the WebServer was requested to list all existing files in the filesystem. JSON array with file information is returned.
void handleListFiles(AsyncWebServerRequest *request)
{
    Serial.println("Webserver: Sending files list");
    AsyncWebServerResponse *response = request->beginResponse(200, "text/javascript; charset=utf-8", listDir(SD, "/"));
    response->addHeader("Cache-Control", "no-cache");
    request->send(response);
}

// This function is called when the sysInfo service was requested.
void handleSysInfo(AsyncWebServerRequest *request)
{
    Serial.println("Webserver: Sending system info");
    String result;
    result += "{\n";
    result += "  \"Chip Model\": " + String(ESP.getChipModel()) + ",\n";
    result += "  \"Chip Cores\": " + String(ESP.getChipCores()) + ",\n";
    result += "  \"Chip Revision\": " + String(ESP.getChipRevision()) + ",\n";
    result += "  \"flashSize\": " + String(ESP.getFlashChipSize()) + ",\n";
    result += "  \"freeHeap\": " + String(ESP.getFreeHeap()) + ",\n";
    result += "  \"minimumFreeHeap\": " + String(ESP.getMinFreeHeap()) + ",\n";
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    result += "  \"sdTotalKBytes\": " + String(SD.totalBytes() / 1024) + ",\n";
    result += "  \"sdUsedKBytes\": " + String(SD.usedBytes() / 1024) + ",\n";
    xSemaphoreGive(SDmutex);
    result += "}";

    AsyncWebServerResponse *response = request->beginResponse(200, "text/javascript; charset=utf-8", result);
    response->addHeader("Cache-Control", "no-cache");
    request->send(response);
}

// used for url not found
static const char notFoundContent[] PROGMEM = R""""(
<html>
<head>
  <title>Resource not found</title>
</head>
<body>
  <p>The page was not found.</p>
  <p><a href="/">Home</a></p>
</body>
)"""";

void webTask(void *parameters)
{
    Serial.println("Starting webserver task.....");

    server.on("/", HTTP_GET, handleRoot);                 // Serve the HTML file
    server.on("/api/tickerlist", HTTP_GET, handleApiGet); // Get the ticker list file
    // server.on("/api/tickerlist", HTTP_POST, handleApiPost); // Save new ticker list data
    server.onRequestBody([](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
                         {if (request->url() == "/api/tickerlist")
                            {
                                handleApiPost(request, data, len, index, total);
                            } });

    server.on("/api/list", HTTP_GET, handleListFiles);  // List all files in the filesystem
    server.on("/api/sysinfo", HTTP_GET, handleSysInfo); // Get system information

    // web page not found
    server.onNotFound([](AsyncWebServerRequest *request)
                      { request->send(404, "text/html", FPSTR(notFoundContent)); });

    server.begin();
    Serial.printf("**** Webserver started at <http://%s> or <http://%s> ****\n", WiFi.getHostname(), WiFi.localIP().toString().c_str());

    while (1)
    {
        vTaskDelay(1000);
    }
}