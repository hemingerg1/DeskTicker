#include "ui.hpp"

#include <Arduino.h>
#include <lvgl.h>
#include <esp32_smartdisplay.h>
#include <DatabaseOnSD.h>
#include <WiFi.h>

#include "myUtils.hpp"
#include "uiFiles/ui.h"

static const char *myTAG = "ui.cpp";

int chartDataArray[130] = {0};
bool screenSleep = false;

lv_chart_series_t *ui_Chart1_series_1;

/***********************************************************************/
/***************************  FreeRTOS task  ***************************/
/***********************************************************************/
void uiTask(void *parameters)
{
    // init display and lvgl
    smartdisplay_init();
    smartdisplay_lcd_set_backlight(0.7); // set backlight in %
    lv_display_t *display = lv_display_get_default();
    lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    ui_init();

    // add chart data array to chart series
    ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x808080), LV_CHART_AXIS_SECONDARY_Y);
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, chartDataArray);

    // add callback funtion to chart to formate y-axis labels as floats
    lv_obj_add_event_cb(ui_Chart1_Yaxis2, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(ui_Chart1_Yaxis2, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    // set sleep screen time to custom font
    lv_obj_set_style_text_font(ui_labTimeSleep, &lv_montserrat_bold_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    // set settings screen fields
    lv_textarea_set_text(ui_taTickerSwitchT, String(symbolChangeTime).c_str());
    lv_textarea_set_text(ui_taSleepT, String(screenTimeout).c_str());

    ulong now = millis();
    ulong lv_last_tick = millis();
    ulong last_loop = 0;
    uint tickerNum = 0;
    ulong cdr = 0;

    // delay to let wificon() try to retreive wifi credentials from NVS
    vTaskDelay(1000);

    // if no wifi credentials are stored in NVS, change to settings screen
    if (noWifiInit && lv_scr_act() != ui_ScrSettings)
    {
        lv_scr_load(ui_ScrSettings);
    }

    while (1)
    {
        now = millis();

        // check for inactivity
        displaySleep();

        // Update the ticker
        lv_tick_inc(now - lv_last_tick);
        lv_last_tick = now;

        // Update the UI
        lv_timer_handler();

        if (lv_scr_act() == ui_ScrHome)
        {
            if (now > last_loop + (symbolChangeTime * 1000) || now < last_loop || last_loop == 0)
            {
                if (numTickers != 0)
                {
                    updateHomeScreen(tickerList[tickerNum]);
                    tickerNum++;
                    if (tickerNum == numTickers)
                    {
                        tickerNum = 0;
                    }
                    last_loop = now;
                }
            }
        }
        else if (lv_scr_act() == ui_ScrSleep)
        {
            updateSleepScreen();
            vTaskDelay(500);
        }

        vTaskDelay(5);
    }
}

/***********************************************************************/
/*************************  Helper Functions  **************************/
/***********************************************************************/
// function to update the main screen
void updateHomeScreen(ticker &tic)
{
    if (tic.symbol != "")
    {
        xSemaphoreTake(TickListmutex, portMAX_DELAY);

        lv_label_set_text_fmt(ui_labSYMBOL, "%s", tic.symbol.c_str());
        lv_label_set_text_fmt(ui_labDESC, "%s", tic.disc.c_str());
        lv_label_set_text_fmt(ui_labPERCENT, "%.2f%%", tic.changePct);

        updateChart(tic);

        if (tic.change > 0)
        {
            lv_label_set_text_fmt(ui_labPRICE, "%.2f,  +%.2f", tic.price, tic.change);
            ui_object_set_themeable_style_property(ui_labPERCENT, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR, _ui_theme_color_upText);
            lv_chart_set_series_color(ui_Chart1, ui_Chart1_series_1, lv_color_hex(0x72d679));
        }
        else if (tic.change < 0)
        {
            lv_label_set_text_fmt(ui_labPRICE, "%.2f,  %.2f", tic.price, tic.change);
            ui_object_set_themeable_style_property(ui_labPERCENT, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR, _ui_theme_color_downText);
            lv_chart_set_series_color(ui_Chart1, ui_Chart1_series_1, lv_color_hex(0xeb6666));
        }
        else
        {
            lv_label_set_text_fmt(ui_labPRICE, "%.2f,  %.2f", tic.price, tic.change);
            ui_object_set_themeable_style_property(ui_labPERCENT, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR, _ui_theme_color_defText);
            lv_chart_set_series_color(ui_Chart1, ui_Chart1_series_1, lv_color_hex(0x808080));
        }

        xSemaphoreGive(TickListmutex);
    }
}

// function to update the chart
void updateChart(ticker &tic)
{
    // get data from SD card
    xSemaphoreTake(SDmutex, 5000);
    MyTable table("/data/" + tic.symbol + ".csv");
    bool addToday = false;
    int len = 0;
    len = table.countRows() - 1; // subtract 1 to exclude header row
    if (len > 1)
    {
        for (int i = 1; i <= len; i++)
        {
            // check if last row in table is today
            if (i == len && marketOpen)
            {
                String lastDate = table.readCell(i, 0);
                int month = lastDate.substring(5, 7).toInt();
                int day = lastDate.substring(8, 10).toInt();

                // if today is in csv file substitute price for ticker current price
                if (month == rtc.getMonth() + 1 && day == rtc.getDay() && tic.price != 0)
                {
                    chartDataArray[i - 1] = int(tic.price * 100);
                }
                else
                {
                    addToday = true;
                    chartDataArray[i - 1] = int(table.readCell(i, 1).toFloat() * 100);
                }
            }
            else
            {
                chartDataArray[i - 1] = int(table.readCell(i, 1).toFloat() * 100);
            }
            // if there is error reading the SD card, use the previous value
            if (chartDataArray[i - 1] == 0 && i > 1)
            {
                chartDataArray[i - 1] = chartDataArray[i - 2];
            }
        }
        String startdt = table.readCell(1, 0);
        String enddt = table.readCell(len, 0);
        xSemaphoreGive(SDmutex);

        // check if end date is older than 3 days, if so display a warning
        if (isDateOlderThan3Days(enddt))
        {
            lv_label_set_text_fmt(ui_labOldDataDate, "Last Date: %s", enddt.c_str());
            lv_obj_remove_flag(ui_panOldData, LV_OBJ_FLAG_HIDDEN);
            tic.csvRetry = true;
        }
        else
        {
            lv_obj_add_flag(ui_panOldData, LV_OBJ_FLAG_HIDDEN);
        }

        // if market is open and csv filed didn't contain today's date, add today's price to the end of the array
        if (addToday && tic.price != 0)
        {
            chartDataArray[len] = int(tic.price * 100);
            ESP_LOGV(myTAG, "add today: %d", chartDataArray[len]);
            len++;

            lv_label_set_text_fmt(ui_labEndDate, "%d/%d", rtc.getMonth() + 1, rtc.getDay());
        }
        else
        {
            lv_label_set_text_fmt(ui_labEndDate, "%d/%d", enddt.substring(5, 7).toInt(), enddt.substring(8, 10).toInt());
        }

        // set chart start date label
        lv_label_set_text_fmt(ui_labStartDate, "%d/%d", startdt.substring(5, 7).toInt(), startdt.substring(8, 10).toInt());

        // adjust X axis for the data length
        lv_chart_set_point_count(ui_Chart1, len);

        // adjust Y axis range
        int *loc_min = std::min_element(chartDataArray, chartDataArray + len);
        int *loc_max = std::max_element(chartDataArray, chartDataArray + len);
        int data_min = *loc_min; // data is already * 100
        int data_max = *loc_max; // data is already * 100
        // int mean = (data_min + data_max) / 2;
        int soft_min = data_min * 0.98;
        int soft_max = data_max * 1.02;
        uint cmax = max(data_max + 200, soft_max);
        uint cmin = min(data_min - 500, soft_min);
        cmax = ((cmax + 99) / 100) * 100; // round up to nearest 100
        cmin = ((cmin - 99) / 100) * 100; // round down to nearest 100
        lv_chart_set_range(ui_Chart1, LV_CHART_AXIS_SECONDARY_Y, cmin, cmax);
        lv_scale_set_range(ui_Chart1_Yaxis2, cmin, cmax);

        lv_chart_refresh(ui_Chart1);
    }
    else
    {
        xSemaphoreGive(SDmutex);
    }
}

// Function to check if a given date is older than 3 days
bool isDateOlderThan3Days(const String &dateString)
{
    struct tm inputDate = {0};

    // Parse the input date string (YYYY-MM-DD)
    if (sscanf(dateString.c_str(), "%d-%d-%d", &inputDate.tm_year, &inputDate.tm_mon, &inputDate.tm_mday) != 3)
    {
        ESP_LOGE(myTAG, "Error: Invalid date format in CSV file. Use YYYY-MM-DD.");
        return false;
    }

    // Adjust year and month to match tm structure expectations
    inputDate.tm_year -= 1900;
    inputDate.tm_mon -= 1;

    // Convert input date to time_t
    time_t inputTime = mktime(&inputDate);
    if (inputTime == -1)
    {
        ESP_LOGE(myTAG, "Error: Unable to convert input date to time.");
        return false;
    }

    // Get the current time
    time_t now;
    time(&now);

    // Calculate the difference in seconds between now and the input date
    double differenceInSeconds = difftime(now, inputTime);

    // Convert seconds to days and check if greater than 3 days
    double daysDifference = differenceInSeconds / (60 * 60 * 24);

    // if Sunday or Monday allow older data
    if (rtc.getDayofWeek() <= 1)
    {
        return daysDifference > 4;
    }
    else
    {
        return daysDifference > 2;
    }
}

// callback function to format the chart y-axis labels
static void draw_event_cb(lv_event_t *e)
{
    // lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);
    lv_draw_task_t *draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = (lv_draw_dsc_base_t *)lv_draw_task_get_draw_dsc(draw_task);
    lv_draw_label_dsc_t *label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);

    if (base_dsc->part == LV_PART_INDICATOR)
    {
        if (label_draw_dsc)
        {
            /*Free the previously allocated text if needed*/
            if (label_draw_dsc->text_local)
                lv_free((void *)label_draw_dsc->text);

            /*Malloc the text and set text_local as 1 to make LVGL automatically free the text.
             * (Local texts are malloc'd internally by LVGL. Mimic this behavior here too)*/
            char tmp_buffer[20] = {0}; /* Big enough buffer */
            float val = (float)base_dsc->id2 / 100.0;
            if (val > 100)
            {
                lv_snprintf(tmp_buffer, sizeof(tmp_buffer), "%d", int(val));
            }
            else
            {
                lv_snprintf(tmp_buffer, sizeof(tmp_buffer), "%.1f", val);
            }

            label_draw_dsc->text = lv_strdup(tmp_buffer);
            label_draw_dsc->text_local = 1;
        }
    }
}

// function to set display to sleep mode
void displaySleep()
{
    int inactMin = lv_disp_get_inactive_time(NULL) / 1000 / 60;
    int adjustTimeout = screenTimeout;

    // adjust sleep timeout if market is open or overnight
    if (marketOpen)
    {
        adjustTimeout = screenTimeout * 6;
    }
    else if (rtc.getHour() >= 20 || rtc.getHour() < 8)
    {
        adjustTimeout = screenTimeout / 3;
    }

    if (!screenSleep && inactMin >= adjustTimeout)
    {
        smartdisplay_lcd_set_backlight(0.03);
        lv_scr_load(ui_ScrSleep);
        screenSleep = true;
    }
    else if (screenSleep && inactMin < adjustTimeout)
    {
        smartdisplay_lcd_set_backlight(0.7);
        lv_scr_load(ui_ScrHome);
        screenSleep = false;
    }
}

// function to update the time on the sleep screen
void updateSleepScreen()
{
    lv_label_set_text_fmt(ui_labTimeSleep, "%d:%02d", rtc.getHour(), rtc.getMinute());
}

// function to handle enter key press on the keyboard
void keyboardEnter(lv_event_t *e)
{
    lv_obj_t *target = lv_keyboard_get_textarea(lv_event_get_current_target_obj(e));

    xSemaphoreTake(prefsmutex, portMAX_DELAY);
    prefs.begin("settings", false);
    if (target == ui_taTickerSwitchT)
    {
        symbolChangeTime = atoi(lv_textarea_get_text(ui_taTickerSwitchT));
        prefs.putShort("symChT", symbolChangeTime);
        ESP_LOGI(myTAG, "UI changed symbolChangeTime to %d", symbolChangeTime);
    }
    else if (target == ui_taSleepT)
    {
        screenTimeout = atoi(lv_textarea_get_text(ui_taSleepT));
        prefs.putShort("slpT", screenTimeout);
        ESP_LOGI(myTAG, "UI changed screenTimeout to %d", screenTimeout);
    }
    else if (target == ui_taWifiSsid)
    {
        prefs.putString("SSID", lv_textarea_get_text(ui_taWifiSsid));
        ESP_LOGI(myTAG, "UI changed SSID");
    }
    else if (target == ui_taWifiPass)
    {
        prefs.putString("PASS", lv_textarea_get_text(ui_taWifiPass));
        lv_textarea_set_text(ui_taWifiPass, "");
        ESP_LOGI(myTAG, "UI changed WIFI password");
    }
    else
    {
        ESP_LOGD(myTAG, "No target found");
    }
    prefs.end();
    xSemaphoreGive(prefsmutex);
}
