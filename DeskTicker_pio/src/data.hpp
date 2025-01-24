#ifndef DATA_HPP
#define DATA_HPP

#include "myUtils.hpp"

extern ushort updateInterval; // in minutes
extern bool eodUpdate;

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void dataTask(void *parameters);

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/

void dataDirUpdate(void);
String getStartDate(const int length);
String getHistoricData(const int tickerNum, const int length);
void getTodayData(const int tickerNum);
void isMarketOpen(void);
void updateAllCsvFiles(void);
bool updateCsvFile(const int tickerIndex);
bool isCsvFileDataUpToDate(const String &symbol);
void checkRetryFlags(void);

#endif