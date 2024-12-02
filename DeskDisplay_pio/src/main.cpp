#include <Arduino.h>

#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>
#include <SD.h>
#include <ESP32Time.h>

#include "secrets.h"
#include "myUtils.h"
#include "ui.hpp"
#include "data.hpp"
#include "web.hpp"

#define TIMEZONE "EST+5EDT,M3.2.0/2,M11.1.0/2"

TaskHandle_t uiTaskHandle = NULL;
TaskHandle_t dataTaskHandle = NULL;
TaskHandle_t webTaskHandle = NULL;
// TaskHandle_t highwaterTaskHandle = NULL;

// define data types for the highwater mark timer
// TimerHandle_t highwaterTimer;
// BaseType_t hwTimerStarted;
// void highwaterTask(void *pvParameters);
// void hwCallback(TimerHandle_t xTimer);

SET_LOOP_TASK_STACK_SIZE(3072);

void setup()
{
  Serial.begin(115200);
  Serial.println("Booting...");

  SDmutex = xSemaphoreCreateMutex();
  if (SDmutex != NULL)
  {
    xSemaphoreGive(SDmutex);
    Serial.println("SDmutex created");
  }
  TickListmutex = xSemaphoreCreateMutex();
  if (TickListmutex != NULL)
  {
    xSemaphoreGive(TickListmutex);
    Serial.println("TickListmutex created");
  }

  if (!SD.begin(5)) // maybe (5)
  {
    Serial.println("Card Mount Failed");
    return;
  }
  printSdUssage();

  wificon();
  timeSync(TIMEZONE, "time1.google.com", "time2.google.com");

  // create and start a timer to trigger the highwater task every 60 seconds
  // highwaterTimer = xTimerCreate("Highwater Timer", pdMS_TO_TICKS(60000), pdTRUE, 0, hwCallback);
  // hwTimerStarted = xTimerStart(highwaterTimer, 0);

  // create tasks
  xTaskCreatePinnedToCore(uiTask, "uiTask", 6144, NULL, 1, &uiTaskHandle, 1);
  xTaskCreatePinnedToCore(dataTask, "dataTask", 6144, NULL, 1, &dataTaskHandle, 1);
  xTaskCreatePinnedToCore(webTask, "webTask", 5120, NULL, 1, &webTaskHandle, 1);
  // xTaskCreatePinnedToCore(highwaterTask, "highwaterTask", 1280, NULL, 1, &highwaterTaskHandle, 1);

  /*
  Serial.print("setup highwater: ");
  Serial.println(uxTaskGetStackHighWaterMark(NULL));
  */
}

void loop()
{
  vTaskDelay(60000);
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
  Serial.println("----------------------------------\n");
  Serial.flush();
}

/*
void highwaterTask(void *pvParameters)
{
  while (1)
  {
    vTaskSuspend(NULL); // suspend this task until the timer triggers
    }
}

void hwCallback(TimerHandle_t xTimer)
{
  vTaskResume(highwaterTaskHandle); // run the highwater program once
}
*/