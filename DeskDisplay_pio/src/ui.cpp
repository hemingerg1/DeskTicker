#include "ui.hpp"

#include <Arduino.h>
#include <lvgl.h>
#include <esp32_smartdisplay.h>

void uiTask(void *parameters)
{
    smartdisplay_init();
    // auto display = lv_display_get_default();

    for (;;)
    {
        Serial.println("Running uiTask");
        vTaskDelay(1000);
    }
}