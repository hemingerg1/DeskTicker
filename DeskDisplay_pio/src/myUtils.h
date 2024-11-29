
#ifndef MYUTILS_H
#define MYUTILS_H

#include <Arduino.h>
#include <FS.h>
#include <ESP32Time.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

/********* ESP Utils *********/
extern ESP32Time rtc;
void wificon(void);
void timeSync(const char *tzInfo, const char *ntpServer1, const char *ntpServer2);
void reboot(void);

/********* SD Card Utils **********/
extern SemaphoreHandle_t SDmutex; // SemaphoreHandle_t
// Path to files on the SD card
#define htmlFilePath "/index.html"
#define tickerListFilePath "/tickerList.csv"

String listDir(fs::FS &fs, const char *dirname);
void printSdUssage(void);

/********* Data Utils *********/
#define maxTickers 25
extern int numTickers;
#define tickerListColNum 3
extern bool updateTickerList;
struct ticker
{
    unsigned short id;
    String symbol;
    String disc;

    String describeTicker()
    {
        return String(id) + "," + symbol + "," + disc;
    }
} extern tickerList[maxTickers];

#endif
