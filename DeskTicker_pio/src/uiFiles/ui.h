// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DeskDisplay_SquareLine_Project

#ifndef _DESKDISPLAY_SQUARELINE_PROJECT_UI_H
#define _DESKDISPLAY_SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
#include "ui_theme_manager.h"
#include "ui_themes.h"


// SCREEN: ui_ScrHome
void ui_ScrHome_screen_init(void);
extern lv_obj_t * ui_ScrHome;
extern lv_obj_t * ui_conFullScreen;
extern lv_obj_t * ui_conHeader;
extern lv_obj_t * ui_conSym;
extern lv_obj_t * ui_labSYMBOL;
extern lv_obj_t * ui_labDESC;
extern lv_obj_t * ui_conPrice;
extern lv_obj_t * ui_labPERCENT;
extern lv_obj_t * ui_labPRICE;
extern lv_obj_t * ui_conChart;
extern lv_obj_t * ui_Chart1;
extern lv_obj_t * ui_Chart1_Xaxis;
extern lv_obj_t * ui_Chart1_Yaxis1;
extern lv_obj_t * ui_Chart1_Yaxis2;
void ui_event_imgSettingsBut(lv_event_t * e);
extern lv_obj_t * ui_imgSettingsBut;
extern lv_obj_t * ui_panOldData;
extern lv_obj_t * ui_labOldDataWarn;
extern lv_obj_t * ui_labOldDataDate;
extern lv_obj_t * ui_labStartDate;
extern lv_obj_t * ui_labEndDate;
// CUSTOM VARIABLES

// SCREEN: ui_ScrSleep
void ui_ScrSleep_screen_init(void);
extern lv_obj_t * ui_ScrSleep;
extern lv_obj_t * ui_labTimeSleep;
// CUSTOM VARIABLES

// SCREEN: ui_ScrSettings
void ui_ScrSettings_screen_init(void);
extern lv_obj_t * ui_ScrSettings;
void ui_event_Image2(lv_event_t * e);
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_conWebAddress;
extern lv_obj_t * ui_labWPTitle;
extern lv_obj_t * ui_labWebAddress;
void ui_event_keyboard(lv_event_t * e);
extern lv_obj_t * ui_keyboard;
extern lv_obj_t * ui_Container4;
extern lv_obj_t * ui_Container5;
extern lv_obj_t * ui_Container7;
extern lv_obj_t * ui_Label5;
void ui_event_taTickerSwitchT(lv_event_t * e);
extern lv_obj_t * ui_taTickerSwitchT;
extern lv_obj_t * ui_Container8;
extern lv_obj_t * ui_Label6;
void ui_event_taSleepT(lv_event_t * e);
extern lv_obj_t * ui_taSleepT;
extern lv_obj_t * ui_Container6;
extern lv_obj_t * ui_Label7;
extern lv_obj_t * ui_Container9;
extern lv_obj_t * ui_Label8;
void ui_event_taWifiSsid(lv_event_t * e);
extern lv_obj_t * ui_taWifiSsid;
extern lv_obj_t * ui_Container10;
extern lv_obj_t * ui_Label9;
void ui_event_taWifiPass(lv_event_t * e);
extern lv_obj_t * ui_taWifiPass;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_1471171794);    // assets/icons8-settings-48.png
LV_IMG_DECLARE(ui_img_home_png);    // assets/home.png

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
