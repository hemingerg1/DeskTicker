
#include "myUtils.h"

#include <Arduino.h>
#include <lvgl.h>
#include <WiFi.h>
#include <FS.h>
#include <SD.h>
#include <Preferences.h>

#include "uiFiles/ui.h"

/***********************************************************************/
/*****************************  Basic Utils  ***************************/
/***********************************************************************/
TaskHandle_t uiTaskHandle = NULL;
TaskHandle_t dataTaskHandle = NULL;
TaskHandle_t webTaskHandle = NULL;

SemaphoreHandle_t prefsmutex = NULL;
ESP32Time rtc(0);
Preferences prefs;
short int screenTimeout = 5;     // in minutes
short int symbolChangeTime = 10; // in seconds
short int priceHistLen = 60;     // in days
bool noWifiInit = true;

// function to get settings from NVS storage
void settingsInit()
{
    xSemaphoreTake(prefsmutex, portMAX_DELAY);
    if (prefs.begin("settings", false))
    {
        symbolChangeTime = prefs.getShort("symChT", 10);
        screenTimeout = prefs.getShort("slpT", 5);
        priceHistLen = prefs.getShort("histLen", 60);
        prefs.end();
    }
    else
    {
        Serial.println("*********Error opening NVS storage*********");
    }
    xSemaphoreGive(prefsmutex);
}

// function to connect to wifi
void wificon(void)
{
    WiFi.disconnect(true);
    delay(500);
    WiFi.setHostname("DeskDisplay");
    WiFi.mode(WIFI_STA);

    // get SSID and PASSWORD from NVS storage
    String SSID = "";
    String PASSWORD = "";
    Serial.print("Getting SSID and PASSWORD from NVS storage...");
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
            vTaskDelay(5000);
        }
    }
    noWifiInit = false;

    // connect to wifi
    Serial.print("\nConnecting to WiFi...");
    WiFi.begin(SSID, PASSWORD);
    vTaskDelay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        Serial.print('.');
        vTaskDelay(500);
        if (t > 20)
        {
            Serial.println("Unable to connect to WiFi.");
            reboot();
        }
    }

    lv_label_set_text_fmt(ui_labWebAddress, "http://%s", WiFi.localIP().toString().c_str());
    lv_textarea_set_text(ui_taWifiSsid, SSID.c_str());

    Serial.println("WiFi connected. IP = " + WiFi.localIP().toString());
}

// function to sync the ESP32's rtc with NTP server
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

    // Show time
    time_t tnow = time(nullptr);
    Serial.print("Synchronized time: ");
    Serial.println(ctime(&tnow));

    // if time synce failed, reboot
    if (rtc.getYear() < 2020)
    {
        reboot();
    }
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

// Function to return a list of all files in the SD card
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

// Serial print the SD card usage
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
bool updateTickerList = false;
bool updateHistLength = false;
ushort numTickers = 0;
bool marketOpen = false;
ticker tickerList[maxTickers];

/***********************************************************************/
/*****************************  Logging Utils  *************************/
/***********************************************************************/
ushort logFileNum = 0;
const char *logFileDir = "/logs";
const size_t logBuf_size = 1024;
char logBuf[logBuf_size];

// fucntion to init log file number at start up
void logFilesInit()
{
    xSemaphoreTake(SDmutex, portMAX_DELAY);

    // check if logs directory exists and create it if not
    if (!SD.exists(logFileDir))
    {
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

    deleteOldLogFiles();

    xSemaphoreGive(SDmutex);
}

// function to add log message to buffer
int handleNewLogMessage(const char *format, va_list args)
{
    Serial.println("Log message callback running");

    // format message in a temp buffer
    char tempBuf[128] = "";
    int ret = vsnprintf(tempBuf, sizeof(tempBuf), format, args);

    // Check the length of the current buffer and the formatted message
    size_t currentLength = strlen(logBuf);
    size_t messageLength = strlen(tempBuf);

    // Check if the message will fit in the remaining buffer space
    if (currentLength + messageLength + 1 >= logBuf_size)
    {
        saveLogToSD();
        currentLength = strlen(logBuf);
    }

    strncat(logBuf, tempBuf, logBuf_size - currentLength - 1);

    return ret;
}

// function to save log buffer to sd card then empty buffer
void saveLogToSD()
{
    Serial.println("Saving log buffer to SD card");

    xSemaphoreTake(SDmutex, portMAX_DELAY);

    // Write buffer to file
    File file = SD.open(String(logFileDir) + "/" + String(logFileNum) + ".txt", FILE_APPEND);
    file.print(logBuf);

    // If log file is too large create a new file
    if (file.size() > 100000)
    {
        logFileNum++;
        File newFile = SD.open(String(logFileDir) + "/" + String(logFileNum) + ".txt", FILE_WRITE);
        newFile.close();
        deleteOldLogFiles();
    }

    file.close();

    // reset the buffer
    logBuf[0] = '\0';

    xSemaphoreGive(SDmutex);
}

// function to delete old log files
void deleteOldLogFiles()
{
    Serial.println("Checking for old log files to delete");

    File dir = SD.open(logFileDir);
    while (File file = dir.openNextFile())
    {
        String filename = file.name();
        ushort fileNum = filename.substring(0, filename.length() - 4).toInt();

        if (fileNum < logFileNum - 1 && logFileNum > 1)
        {
            file.close();
            Serial.println("Deleting log file " + filename);
            SD.remove(String(logFileDir) + "/" + filename);
        }
        else
        {
            file.close();
        }
    }
    dir.rewindDirectory();
    dir.close();
}