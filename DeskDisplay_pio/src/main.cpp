#include <Arduino.h>
#include <lvgl.h>
#include <esp32_smartdisplay.h>

void setup() {
  smartdisplay_init();
  auto display = lv_display_get_default();
}

void loop() {
}
