
#include "myUtils.h"

#include "secrets.h"

#include <Arduino.h>
#include <WiFi.h>
#include <FS.h>
#include <SD.h>

void wificon(void)
{
    Serial.println("Connecting to WiFi.");
    WiFi.disconnect(true);
    delay(1000);
    WiFi.setHostname(HOSTNAME);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi...");
    delay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        Serial.print('.');
        delay(500);
        if (t > 20)
        {
            Serial.println("Unable to connect to WiFi.");
            reboot();
        }
    }
    Serial.println("WiFi connected. IP: " + WiFi.localIP().toString());
}

void reboot(void)
{
    Serial.println(F("Rebooting..."));
    delay(2000);
    ESP.restart();
}

/********* SD Card Utils **********/

String listDir(fs::FS &fs, const char *dirname)
{
    Serial.printf("Listing directory: %s\n", dirname);
    String result;
    xSemaphoreTake(SDmutex, portMAX_DELAY);
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
        if (result.length() > 4)
        {
            result += ",\n";
        }
        result += "  {";
        result += "\"type\": \"file\", ";
        result += "\"name\": \"" + String(entry.name()) + "\", ";
        result += "\"size\": " + String(entry.size()) + ", ";
        result += "\"time\": " + String(entry.getLastWrite());
        result += "}";
    }
    result += "\n]";
    root.close();
    xSemaphoreGive(SDmutex);
    return result;
}

void printSdUssage(void)
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    float totalMBytes = SD.totalBytes() / (1024 * 1024);
    float usedMBytes = SD.usedBytes() / (1024 * 1024);
    Serial.printf("SD Card Total Size (MB): %.2f\n", totalMBytes);
    Serial.printf("SD Card Used Space (MB): %.2f\n", usedMBytes);
    xSemaphoreGive(SDmutex);
}

/********* Data Utils *********/
bool updateTickerList = true;
ticker tickerList[20];
