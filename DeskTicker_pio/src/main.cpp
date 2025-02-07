#include <Arduino.h>

#include <WiFi.h>
#include <SD.h>
#include <ESP32Time.h>

#include "myUtils.hpp"
#include "ui.hpp"
#include "data.hpp"
#include "web.hpp"

#define TIMEZONE "EST+5EDT,M3.2.0/2,M11.1.0/2"

#define PRINT_HIGHWATER false

SET_LOOP_TASK_STACK_SIZE(4096);

void sysTask(void *pvParameters);

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
  logmutex = xSemaphoreCreateMutex();
  if (logmutex != NULL)
  {
    xSemaphoreGive(logmutex);
  }

  // set log levels and callback
  esp_log_level_set("*", ESP_LOG_INFO);
  /*
  esp_log_level_set("main.cpp", ESP_LOG_DEBUG);
  esp_log_level_set("data.cpp", ESP_LOG_DEBUG);
  esp_log_level_set("web.cpp", ESP_LOG_DEBUG);
  esp_log_level_set("ui.cpp", ESP_LOG_DEBUG);
  esp_log_level_set("myUtils.cpp", ESP_LOG_DEBUG);
  */
  esp_log_set_vprintf(handleNewLogMessage);

  // init SD card
  if (!SD.begin(5))
  {
    ESP_LOGE("main.cpp", "Card Mount Failed");
    reboot();
  }

  // get the latest log file from SD card
  logFilesInit();
  ESP_LOGI("main.cpp", "***** Booting ***** Current log file %d.txt", logFileNum);

  printSdUssage();

  // create a timer to give settingsInit() a time limit to complete.
  // if not completed in time, reboot
  // when SD file system fails to mount, code can hang in prefs.begin()
  timeoutTimer = xTimerCreate("Timeout Timer", 6000, pdFALSE, NULL, timeoutReboot);
  xTimerStart(timeoutTimer, 0);
  // get ui settings from NVS
  xTaskCreatePinnedToCore(settingsInitTask, "settingsTask", 2000, NULL, 1, NULL, 1);
  vTaskDelay(1000);

  xTaskCreatePinnedToCore(uiTask, "uiTask", 7168, NULL, 4, &uiTaskHandle, 1);

  // start wifi connection
  wificon();
  timeSync(TIMEZONE, "time1.google.com", "time2.google.com");

  xTaskCreatePinnedToCore(dataTask, "dataTask", 6144, NULL, 3, &dataTaskHandle, 1);
  xTaskCreatePinnedToCore(webTask, "webTask", 4096, NULL, 2, &webTaskHandle, 1);
  xTaskCreatePinnedToCore(sysTask, "sysTask", 4096, NULL, 2, &sysTaskHandle, 1);
}

void loop()
{
  vTaskDelay(1000);
}

void sysTask(void *pvParameters)
{
  while (1)
  {
    vTaskDelay(5 * 60 * 1000); // run every 5 mins

    if (PRINT_HIGHWATER)
    {
      Serial.print("\n-------- High Water Marks --------\n");
      Serial.println("(minimum free stack space)");
      Serial.print("uiTask : ");
      Serial.println(uxTaskGetStackHighWaterMark(uiTaskHandle));
      Serial.print("dataTask : ");
      Serial.println(uxTaskGetStackHighWaterMark(dataTaskHandle));
      // Serial.print("webTask : ");
      // Serial.println(uxTaskGetStackHighWaterMark(webTaskHandle));
      Serial.print("sysTask: ");
      Serial.println(uxTaskGetStackHighWaterMark(sysTaskHandle));
      Serial.print("loopTask: ");
      Serial.println(uxTaskGetStackHighWaterMark(loopTaskHandle));
      Serial.println("----------------------------------");
      Serial.print("free heap space: ");
      Serial.println(ESP.getFreeHeap());
      Serial.print("minimum free heap space: ");
      Serial.println(ESP.getMinFreeHeap());
      Serial.println("----------------------------------");
      Serial.printf("Market Open: %d\n", marketOpen);
      Serial.println("----------------------------------\n");
      Serial.flush();
    }

    // check if it is time to create new log file
    if (needNewLogFile)
    {
      createNewLogFile();
    }

    // if there is log messages in buffer save to sd card
    if (strlen(logBuf) > 128)
    {
      saveLogToSD();
    }

    // check wifi is still connected
    if (WiFi.status() != WL_CONNECTED)
    {
      wificon();
    }
  }
}