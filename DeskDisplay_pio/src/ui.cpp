#include "ui.hpp"

#include <Arduino.h>
// #include <lvgl.h>
// #include <esp32_smartdisplay.h>

void uiTask(void *parameters)
{
    Serial.println("Starting uiTask");
    // smartdisplay_init();
    //  auto display = lv_display_get_default();

    for (;;)
    {

        vTaskDelay(1000);
    }
}