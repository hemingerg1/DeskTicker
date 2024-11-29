#ifndef DATA_HPP
#define DATA_HPP

#include "myUtils.h"

extern uint priceHistLen;

void loadTickers(void);
void tickerListUpdate(void);
String getStartDate(int length);
String getCSVData(ticker ticker, int length);

void dataTask(void *parameters);

#endif