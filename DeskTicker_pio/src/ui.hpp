#ifndef UI_HPP
#define UI_HPP

#include <lvgl.h>

#include "myUtils.h"

extern int32_t chartDataArray[];

extern bool screenSleep;

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void uiTask(void *parameters);

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/
void updateHomeScreen(ticker tic);
void updateChart(ticker tic);
bool isDateOlderThan3Days(const String &dateString);
static void draw_event_cb(lv_event_t *e);
void displaySleep();
void updateSleepScreen();
// void keyboardEnter(lv_event_t *e); // in uiFiles/ui

#endif
