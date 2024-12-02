#include "ui.hpp"

#include <Arduino.h>
#include <lvgl.h>
#include <esp32_smartdisplay.h>

#include "myUtils.h"
#include "uiFiles/ui.h"

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void uiTask(void *parameters)
{
    vTaskDelay(500);
    Serial.println("uiTask: init");

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1); // set backlight to 100%
    lv_display_t *display = lv_display_get_default();
    lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    ui_init();

    //Serial.printf("lv color size: %d,   buffer pixels: %d\n", sizeof(lv_color_t), LVGL_BUFFER_PIXELS);

    ulong now = millis();
    ulong lv_last_tick = millis();
    ulong last_loop = 0;
    uint tickerNum = 0;
    ulong cdr = 0;

    Serial.println("uiTask: init done");
    while (1)
    {
        now = millis();
        if (now > last_loop + 10000 || now < last_loop)
        {
            // read photo resistor
            // cdr = analogReadMilliVolts(CDS);
            // Serial.printf("CDS: %d\n", cdr);

            updateHomeScreen(tickerList[tickerNum]);
            tickerNum++;
            if (tickerNum == numTickers)
            {
                tickerNum = 0;
            }
            last_loop = now;
        }
        // Update the ticker
        lv_tick_inc(now - lv_last_tick);
        lv_last_tick = now;
        // Update the UI
        lv_timer_handler();

        vTaskDelay(10);
    }
}

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/
void updateHomeScreen(ticker tic)
{
    //Serial.printf("Symbol: %s, Desc: %s, Price: %.2f, Change: %.2f, ChangePct: %.2f%%\n", tic.symbol.c_str(), tic.disc.c_str(), tic.price, tic.change, tic.changePct);

    lv_label_set_text_fmt(ui_labSYMBOL, "%s", tic.symbol.c_str());
    lv_label_set_text_fmt(ui_labDESC, "%s", tic.disc.c_str());
    lv_label_set_text_fmt(ui_labPRICE, "%.2f", tic.price);
}