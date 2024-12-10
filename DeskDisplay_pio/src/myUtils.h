
#ifndef MYUTILS_H
#define MYUTILS_H

#include <Arduino.h>
#include <FS.h>
#include <ESP32Time.h>
#include <Preferences.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

/***********************************************************************/
/*****************************  ESP Utils  *****************************/
/***********************************************************************/
extern SemaphoreHandle_t prefsmutex;
extern ESP32Time rtc;
extern Preferences prefs;
extern short int screenTimeout;    // in minutes
extern short int symbolChangeTime; // in seconds
extern bool noWifiInit;

void settingsInit();
void wificon(void);
void timeSync(const char *tzInfo, const char *ntpServer1, const char *ntpServer2);
void reboot(void);

/***********************************************************************/
/*****************************  SD card Utils  *************************/
/***********************************************************************/
extern SemaphoreHandle_t SDmutex;

// Path to files on the SD card
extern const char *htmlFilePath;
extern const char *tickerListFilePath;

String listDir(fs::FS &fs, const char *dirname);
void printSdUssage(void);

/***********************************************************************/
/*****************************  Data Utils  ****************************/
/***********************************************************************/
extern SemaphoreHandle_t TickListmutex;
extern const ushort maxTickers;
extern ushort numTickers;
extern const ushort tickerListColNum;
extern bool updateTickerList;
extern bool marketOpen;
struct ticker
{
    ushort id;
    String symbol;
    String disc;
    float price;
    float change;
    float changePct;

    String describeTicker()
    {
        return String(id) + "," + symbol + "," + disc;
    }
} extern tickerList[];

#endif
