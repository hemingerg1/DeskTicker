#include "web.hpp"

#include <Arduino.h>
#include <WiFi.h>
// #include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SD.h>

#include "myUtils.h"

AsyncWebServer server(80);

// Function to serve the HTML file from SD card
void handleRoot(AsyncWebServerRequest *request)
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    File file = SD.open(htmlFilePath);
    if (!file)
    {
        request->send(500, "text/plain", "Failed to read HTML file from SD card.");
        xSemaphoreGive(SDmutex);
        return;
    }
    request->send(file, "text/html");
    file.close();
    xSemaphoreGive(SDmutex);
}

// Function to get the ticker list (GET /api/tickerlist)
void handleApiGet(AsyncWebServerRequest *request)
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    File file = SD.open(tickerListFilePath);
    if (!file)
    {
        request->send(500, "text/plain", "Failed to open ticker list CSV file.");
        xSemaphoreGive(SDmutex);
        return;
    }
    // Send the CSV data
    request->send(file, "text/csv");
    file.close();
    xSemaphoreGive(SDmutex);
}

// Function to handle POST requests (POST /api/tickerlist)
void handleApiPost(AsyncWebServerRequest *request)
{
    if (request->method() != HTTP_POST)
    {
        request->send(405, "text/plain", "Method Not Allowed");
        return;
    }
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    // Create or open the CSV file for writing
    File file = SD.open(tickerListFilePath, FILE_WRITE);
    if (!file)
    {
        request->send(500, "text/plain", "Failed to open CSV file for writing.");
        xSemaphoreGive(SDmutex);
        return;
    }
    // Read the incoming CSV data from the POST request
    String csvData = request->arg("plain");
    // Write the received CSV data to the file
    file.print(csvData);
    file.close();
    xSemaphoreGive(SDmutex);
    request->send(200, "text/plain", "CSV data saved successfully.");
}

// Called when the WebServer was requested to list all existing files in the filesystem. JSON array with file information is returned.
void handleListFiles(AsyncWebServerRequest *request)
{
    AsyncWebServerResponse *response = request->beginResponse(200, "text/javascript; charset=utf-8", listDir(SD, "/"));
    response->addHeader("Cache-Control", "no-cache");
    request->send(response);
}

// This function is called when the sysInfo service was requested.
void handleSysInfo(AsyncWebServerRequest *request)
{
    String result;

    result += "{\n";
    result += "  \"Chip Model\": " + String(ESP.getChipModel()) + ",\n";
    result += "  \"Chip Cores\": " + String(ESP.getChipCores()) + ",\n";
    result += "  \"Chip Revision\": " + String(ESP.getChipRevision()) + ",\n";
    result += "  \"flashSize\": " + String(ESP.getFlashChipSize()) + ",\n";
    result += "  \"freeHeap\": " + String(ESP.getFreeHeap()) + ",\n";
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    result += "  \"sdTotalBytes\": " + String(SD.totalBytes()) + ",\n";
    result += "  \"sdUsedBytes\": " + String(SD.usedBytes()) + ",\n";
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
  <p>The resource was not found.</p>
  <p><a href="/">Start again</a></p>
</body>
)"""";

void webTask(void *parameters)
{
    Serial.println("Starting webserver task.....");

    server.on("/", HTTP_GET, handleRoot);                   // Serve the HTML file
    server.on("/api/tickerlist", HTTP_GET, handleApiGet);   // Get the ticker list file
    server.on("/api/tickerlist", HTTP_POST, handleApiPost); // Save new ticker list data
    server.on("/api/list", HTTP_GET, handleListFiles);      // List all files in the filesystem
    server.on("/api/sysinfo", HTTP_GET, handleSysInfo);     // Get system information

    // web page not found
    server.onNotFound([](AsyncWebServerRequest *request)
                      { request->send(404, "text/html", FPSTR(notFoundContent)); });

    // server.enableCORS(false);

    server.begin();
    Serial.printf("Webserver started at <http://%s> or <http://%s>", WiFi.getHostname(), WiFi.localIP().toString().c_str());

    for (;;)
    {
        vTaskDelay(100);
    }
}