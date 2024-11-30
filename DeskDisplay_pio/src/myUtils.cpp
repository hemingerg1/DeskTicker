
#include "myUtils.h"

#include "secrets.h"

#include <Arduino.h>
#include <WiFi.h>
#include <FS.h>
#include <SD.h>

/***********************************************************************/
/*****************************  ESP Utils  *****************************/
/***********************************************************************/
ESP32Time rtc(0);

void wificon(void)
{
    Serial.print("Connecting to WiFi...");
    WiFi.disconnect(true);
    delay(1000);
    WiFi.setHostname(HOSTNAME);
    WiFi.mode(WIFI_STA);
    if (SIM)
    {
        Serial.println("Using Wokwi WIFI");
        WiFi.begin("Wokwi-GUEST", "", 6);
    }
    else
    {
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    }
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

void timeSync(const char *tzInfo, const char *ntpServer1, const char *ntpServer2)
{
    configTzTime(tzInfo, ntpServer1, ntpServer2);

    // Wait till time is synced
    Serial.print("Syncing time");
    int i = 0;
    while (time(nullptr) < 1000000000l && i < 40)
    {
        Serial.print(".");
        delay(500);
        i++;
    }
    Serial.println();

    // Show time
    time_t tnow = time(nullptr);
    Serial.print("Synchronized time: ");
    Serial.println(ctime(&tnow));
}

void reboot(void)
{
    Serial.println(F("Rebooting..."));
    delay(2000);
    ESP.restart();
}

/***********************************************************************/
/*****************************  SD card Utils  *************************/
/***********************************************************************/
SemaphoreHandle_t SDmutex = NULL;

const char *htmlFilePath = "/index.html";
const char *tickerListFilePath = "/tickerList.csv";

String
listDir(fs::FS &fs, const char *dirname)
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
    return result;
}

void printSdUssage(void)
{
    Serial.println("-------- SD Card usage --------");
    xSemaphoreTake(SDmutex, portMAX_DELAY);
    float totalMBytes = SD.totalBytes() / (1024 * 1024);
    float usedKBytes = SD.usedBytes() / (1024);
    Serial.printf("SD Card Total Size (MB): %.2f\n", totalMBytes);
    Serial.printf("SD Card Used Space (kB): %.2f\n", usedKBytes);
    xSemaphoreGive(SDmutex);
    Serial.println("--------------------------------");
}

/***********************************************************************/
/*****************************  Data Utils  ****************************/
/***********************************************************************/
SemaphoreHandle_t TickListmutex = NULL;
const ushort maxTickers = 30;
const ushort tickerListColNum = 3;
bool updateTickerList = true;
ushort numTickers = 0;
bool marketOpen = false;
ticker tickerList[maxTickers];
