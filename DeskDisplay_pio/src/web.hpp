#ifndef WEB_HPP
#define WEB_HPP

#include <ESPAsyncWebServer.h>

extern AsyncWebServer server;

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void webTask(void *parameters);

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/
void handleRoot(AsyncWebServerRequest *request);
void handleApiGet(AsyncWebServerRequest *request);
void handleApiPost(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total);
void handleListFiles(AsyncWebServerRequest *request);
void handleSysInfo(AsyncWebServerRequest *request);

#endif