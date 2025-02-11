// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DeskDisplay_SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_ScrHome
void ui_ScrHome_screen_init(void);
lv_obj_t * ui_ScrHome;
lv_obj_t * ui_conFullScreen;
lv_obj_t * ui_conHeader;
lv_obj_t * ui_conSym;
lv_obj_t * ui_labSYMBOL;
lv_obj_t * ui_labDESC;
lv_obj_t * ui_conPrice;
lv_obj_t * ui_labPERCENT;
lv_obj_t * ui_labPRICE;
lv_obj_t * ui_conChart;
lv_obj_t * ui_Chart1;
lv_obj_t * ui_Chart1_Xaxis;
lv_obj_t * ui_Chart1_Yaxis1;
lv_obj_t * ui_Chart1_Yaxis2;
void ui_event_imgSettingsBut(lv_event_t * e);
lv_obj_t * ui_imgSettingsBut;
lv_obj_t * ui_panOldData;
lv_obj_t * ui_labOldDataWarn;
lv_obj_t * ui_labOldDataDate;
lv_obj_t * ui_labStartDate;
lv_obj_t * ui_labEndDate;
// CUSTOM VARIABLES


// SCREEN: ui_ScrSleep
void ui_ScrSleep_screen_init(void);
lv_obj_t * ui_ScrSleep;
lv_obj_t * ui_labTimeSleep;
// CUSTOM VARIABLES


// SCREEN: ui_ScrSettings
void ui_ScrSettings_screen_init(void);
lv_obj_t * ui_ScrSettings;
void ui_event_Image2(lv_event_t * e);
lv_obj_t * ui_Image2;
lv_obj_t * ui_conWebAddress;
lv_obj_t * ui_labWPTitle;
lv_obj_t * ui_labWebAddress;
void ui_event_keyboard(lv_event_t * e);
lv_obj_t * ui_keyboard;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Container5;
lv_obj_t * ui_Container7;
lv_obj_t * ui_Label5;
void ui_event_taTickerSwitchT(lv_event_t * e);
lv_obj_t * ui_taTickerSwitchT;
lv_obj_t * ui_Container8;
lv_obj_t * ui_Label6;
void ui_event_taSleepT(lv_event_t * e);
lv_obj_t * ui_taSleepT;
lv_obj_t * ui_Container6;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Container9;
lv_obj_t * ui_Label8;
void ui_event_taWifiSsid(lv_event_t * e);
lv_obj_t * ui_taWifiSsid;
lv_obj_t * ui_Container10;
lv_obj_t * ui_Label9;
void ui_event_taWifiPass(lv_event_t * e);
lv_obj_t * ui_taWifiPass;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
const lv_image_dsc_t * ui_imgset_1703005419[1] = {&ui_img_1471171794};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_imgSettingsBut(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScrSettings, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScrSettings_screen_init);
    }
}

void ui_event_Image2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScrHome, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScrHome_screen_init);
    }
}

void ui_event_keyboard(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_READY) {
        keyboardEnter(e);
    }
}

void ui_event_taTickerSwitchT(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_keyboard,  ui_taTickerSwitchT);
    }
}

void ui_event_taSleepT(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_keyboard,  ui_taSleepT);
    }
}

void ui_event_taWifiSsid(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_keyboard,  ui_taWifiSsid);
    }
}

void ui_event_taWifiPass(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_keyboard,  ui_taWifiPass);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScrHome_screen_init();
    ui_ScrSleep_screen_init();
    ui_ScrSettings_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScrHome);
}
