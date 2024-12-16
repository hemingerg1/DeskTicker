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
void handleTicListPost(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total);
void handleListFiles(AsyncWebServerRequest *request);
void handleSysInfo(AsyncWebServerRequest *request);
void handleHistLengthGet(AsyncWebServerRequest *request);
void handleHistLengthPost(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total);
void handleLog(AsyncWebServerRequest *request);

#endif