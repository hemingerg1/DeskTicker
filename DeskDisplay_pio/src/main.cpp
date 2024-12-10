#include <Arduino.h>

#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>
#include <SD.h>
#include <ESP32Time.h>

#include "myUtils.h"
#include "ui.hpp"
#include "data.hpp"
#include "web.hpp"

#define TIMEZONE "EST+5EDT,M3.2.0/2,M11.1.0/2"

TaskHandle_t uiTaskHandle = NULL;
TaskHandle_t dataTaskHandle = NULL;
TaskHandle_t webTaskHandle = NULL;

SET_LOOP_TASK_STACK_SIZE(3072);

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting...");

  // create mutexes
  prefsmutex = xSemaphoreCreateMutex();
  if (prefsmutex != NULL)
  {
    xSemaphoreGive(prefsmutex);
  }
  SDmutex = xSemaphoreCreateMutex();
  if (SDmutex != NULL)
  {
    xSemaphoreGive(SDmutex);
  }
  TickListmutex = xSemaphoreCreateMutex();
  if (TickListmutex != NULL)
  {
    xSemaphoreGive(TickListmutex);
  }

  // init SD card
  if (!SD.begin(5))
  {
    Serial.println("Card Mount Failed");
    return;
  }
  printSdUssage();

  // get ui settings for NVS
  settingsInit();

  // start ui task
  xTaskCreatePinnedToCore(uiTask, "uiTask", 7168, NULL, 1, &uiTaskHandle, 1);

  // start wifi connection
  wificon();
  timeSync(TIMEZONE, "time1.google.com", "time2.google.com");

  // create other other tasks
  xTaskCreatePinnedToCore(dataTask, "dataTask", 5630, NULL, 1, &dataTaskHandle, 1);
  xTaskCreatePinnedToCore(webTask, "webTask", 4096, NULL, 1, &webTaskHandle, 1);
}

void loop()
{
  vTaskDelay(120000);

  Serial.print("\n-------- High Water Marks --------\n");
  Serial.println("(minimum free stack space)");
  Serial.print("uiTask : ");
  Serial.println(uxTaskGetStackHighWaterMark(uiTaskHandle));
  Serial.print("dataTask : ");
  Serial.println(uxTaskGetStackHighWaterMark(dataTaskHandle));
  Serial.print("webTask : ");
  Serial.println(uxTaskGetStackHighWaterMark(webTaskHandle));
  Serial.print("loop: ");
  Serial.println(uxTaskGetStackHighWaterMark(NULL));
  Serial.println("----------------------------------");
  Serial.print("free heap space: ");
  Serial.println(ESP.getFreeHeap());
  Serial.print("minimum free heap space: ");
  Serial.println(ESP.getMinFreeHeap());
  Serial.println("----------------------------------");
  Serial.printf("Market Open: %d\n", marketOpen);
  Serial.println("----------------------------------\n");
  Serial.flush();

  if (WiFi.status() != WL_CONNECTED)
  {
    wificon();
  }
}