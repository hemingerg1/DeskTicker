#include <Arduino.h>

#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>
#include <SD.h>

#include "secrets.h"
#include "myUtils.h"
#include "ui.hpp"
#include "data.hpp"
#include "web.hpp"

#define TIMEZONE "EST+5EDT,M3.2.0/2,M11.1.0/2"

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting...");

  if (!SD.begin()) // maybe (5)
  {
    Serial.println("Card Mount Failed");
    return;
  }
  printSdUssage();

  wificon();
  Serial.println("setting time...");
  configTzTime(TIMEZONE, "pool.ntp.org");

  SDmutex = xSemaphoreCreateMutex();

  xTaskCreatePinnedToCore(uiTask, "uiTask", 1024 * 4, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(dataTask, "dataTask", 1024 * 4, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(webTask, "webTask", 1024 * 4, NULL, 1, NULL, 1);
}

void loop()
{
}
