
#ifndef MYUTILS_H
#define MYUTILS_H

#include <Arduino.h>
#include <FS.h>

/********* ESP Utils *********/
void wificon(void);
void reboot(void);

/********* SD Card Utils **********/
static SemaphoreHandle_t SDmutex;
// Path to files on the SD card
#define htmlFilePath "/index.html"
#define tickerListFilePath "/tickerList.csv"

String listDir(fs::FS &fs, const char *dirname);
void printSdUssage(void);

/********* Data Utils *********/
extern bool updateTickerList;
struct ticker
{
    unsigned short id;
    String symbol;
    String disc;
    unsigned short source;

    String describeTicker()
    {
        return String(id) + "," + symbol + "," + disc + "," + source;
    }
} extern tickerList[20];

#endif
