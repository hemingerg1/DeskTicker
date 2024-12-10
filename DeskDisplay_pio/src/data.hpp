#ifndef DATA_HPP
#define DATA_HPP

#include "myUtils.h"

extern ushort priceHistLen;   // in days
extern ushort updateInterval; // in minutes
extern bool eodUpdate;

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void dataTask(void *parameters);

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/
void loadTickers(void);
void tickerListUpdate(void);
String getStartDate(int length);
String getHistoricData(const String symbol, int length);
void getTodayData(int tickerNum);
void isMarketOpen(void);
void getEODData(void);
bool updateCsvFile(const int tickerIndex);
bool isCsvFileDataUpToDate(const String symbol);

#endif