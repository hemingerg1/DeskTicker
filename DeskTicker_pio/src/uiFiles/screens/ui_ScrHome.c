// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DeskDisplay_SquareLine_Project

#include "../ui.h"

void ui_ScrHome_screen_init(void)
{
    ui_ScrHome = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_ScrHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScrHome, lv_color_hex(0x161616), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScrHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_conFullScreen = lv_obj_create(ui_ScrHome);
    lv_obj_remove_style_all(ui_conFullScreen);
    lv_obj_set_width(ui_conFullScreen, lv_pct(100));
    lv_obj_set_height(ui_conFullScreen, lv_pct(100));
    lv_obj_set_align(ui_conFullScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_conFullScreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_conFullScreen, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_conFullScreen, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_conHeader = lv_obj_create(ui_conFullScreen);
    lv_obj_remove_style_all(ui_conHeader);
    lv_obj_set_height(ui_conHeader, 55);
    lv_obj_set_width(ui_conHeader, lv_pct(100));
    lv_obj_set_flex_flow(ui_conHeader, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_conHeader, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_conHeader, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_conHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_conHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_conHeader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_conHeader, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_conSym = lv_obj_create(ui_conHeader);
    lv_obj_remove_style_all(ui_conSym);
    lv_obj_set_height(ui_conSym, lv_pct(100));
    lv_obj_set_width(ui_conSym, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_conSym, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_conSym, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_conSym, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(ui_conSym, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_conSym, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_conSym, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_conSym, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_conSym, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labSYMBOL = lv_label_create(ui_conSym);
    lv_obj_set_width(ui_labSYMBOL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labSYMBOL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labSYMBOL, 10);
    lv_obj_set_y(ui_labSYMBOL, 10);
    lv_label_set_text(ui_labSYMBOL, "sym");
    lv_obj_set_style_text_color(ui_labSYMBOL, lv_color_hex(0xEDEAEA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labSYMBOL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labSYMBOL, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labDESC = lv_label_create(ui_conSym);
    lv_obj_set_width(ui_labDESC, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labDESC, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labDESC, 10);
    lv_obj_set_y(ui_labDESC, 20);
    lv_obj_set_align(ui_labDESC, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_labDESC, "description");
    ui_object_set_themeable_style_property(ui_labDESC, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_defText);
    ui_object_set_themeable_style_property(ui_labDESC, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_defText);

    ui_conPrice = lv_obj_create(ui_conHeader);
    lv_obj_remove_style_all(ui_conPrice);
    lv_obj_set_height(ui_conPrice, lv_pct(100));
    lv_obj_set_width(ui_conPrice, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_conPrice, -48);
    lv_obj_set_y(ui_conPrice, 3);
    lv_obj_set_align(ui_conPrice, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_conPrice, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_conPrice, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);
    lv_obj_remove_flag(ui_conPrice, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_conPrice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_conPrice, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_conPrice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_conPrice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labPERCENT = lv_label_create(ui_conPrice);
    lv_obj_set_width(ui_labPERCENT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labPERCENT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_labPERCENT, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_labPERCENT, "Per%");
    lv_obj_set_style_text_font(ui_labPERCENT, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labPRICE = lv_label_create(ui_conPrice);
    lv_obj_set_width(ui_labPRICE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labPRICE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labPRICE, -10);
    lv_obj_set_y(ui_labPRICE, 10);
    lv_obj_set_align(ui_labPRICE, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_labPRICE, "price");
    ui_object_set_themeable_style_property(ui_labPRICE, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_defText);
    ui_object_set_themeable_style_property(ui_labPRICE, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_defText);
    lv_obj_set_style_text_font(ui_labPRICE, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_conChart = lv_obj_create(ui_conFullScreen);
    lv_obj_remove_style_all(ui_conChart);
    lv_obj_set_width(ui_conChart, lv_pct(100));
    lv_obj_set_flex_grow(ui_conChart, 1);
    lv_obj_set_align(ui_conChart, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_conChart, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_conChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_conChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_conChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_conChart, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart1 = lv_chart_create(ui_conChart);
    lv_obj_set_width(ui_Chart1, 275);
    lv_obj_set_height(ui_Chart1, lv_pct(90));
    lv_obj_set_align(ui_Chart1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Chart1, LV_OBJ_FLAG_OVERFLOW_VISIBLE);     /// Flags
    lv_obj_remove_flag(ui_Chart1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_Chart1, LV_OBJ_FLAG_OVERFLOW_VISIBLE);      //make scales visible - Should it be forced to True?
    //lv_obj_remove_flag( ui_Chart1, LV_OBJ_FLAG_SCROLLABLE );    //no chart-zoom in LVGL9 - Shouldn't it be forced to False?
    lv_chart_set_type(ui_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_Chart1, 30);
    lv_chart_set_range(ui_Chart1, LV_CHART_AXIS_SECONDARY_Y, 0, 1000);
    lv_chart_set_div_line_count(ui_Chart1, 5, 0);
    lv_obj_set_style_bg_color(ui_Chart1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Chart1, lv_color_hex(0x2C2C2C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Chart1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chart1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chart1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart1_Xaxis = lv_scale_create(ui_Chart1);
    lv_scale_set_mode(ui_Chart1_Xaxis, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
    lv_obj_set_size(ui_Chart1_Xaxis, lv_pct(100), 2);
    lv_obj_set_align(ui_Chart1_Xaxis, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(ui_Chart1_Xaxis, 2 + lv_obj_get_style_pad_bottom(ui_Chart1,
                                                                  LV_PART_MAIN) + lv_obj_get_style_border_width(ui_Chart1, LV_PART_MAIN));
    lv_obj_set_style_line_width(ui_Chart1_Xaxis, 0, LV_PART_MAIN);
    lv_obj_set_style_line_width(ui_Chart1_Xaxis, 1, LV_PART_ITEMS);   //LVGL-9.1 ticks are thicker by default
    lv_obj_set_style_line_width(ui_Chart1_Xaxis, 1, LV_PART_INDICATOR);
    lv_obj_set_style_length(ui_Chart1_Xaxis, 0, LV_PART_ITEMS);      //minor tick length
    lv_obj_set_style_length(ui_Chart1_Xaxis, 0, LV_PART_INDICATOR);      //major tick length
    lv_scale_set_range(ui_Chart1_Xaxis, 0, 0 > 0 ? 0 - 1 : 0);
    lv_scale_set_total_tick_count(ui_Chart1_Xaxis, (0 > 0 ? 0 - 1 : 0) * 0 + 1);
    lv_scale_set_major_tick_every(ui_Chart1_Xaxis, 0 >= 1 ? 0 : 1);
    lv_scale_set_label_show(ui_Chart1_Xaxis, false);
    ui_Chart1_Yaxis1 = lv_scale_create(ui_Chart1);
    lv_scale_set_mode(ui_Chart1_Yaxis1, LV_SCALE_MODE_VERTICAL_LEFT);
    lv_obj_set_size(ui_Chart1_Yaxis1, 50, lv_pct(100));
    lv_obj_set_align(ui_Chart1_Yaxis1, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(ui_Chart1_Yaxis1, -50 - lv_obj_get_style_pad_left(ui_Chart1,
                                                                   LV_PART_MAIN) - lv_obj_get_style_border_width(ui_Chart1, LV_PART_MAIN) + 2);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis1, 0, LV_PART_MAIN);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis1, 1, LV_PART_ITEMS);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis1, 1, LV_PART_INDICATOR);
    lv_obj_set_style_length(ui_Chart1_Yaxis1, 0, LV_PART_ITEMS);   //minor tick length
    lv_obj_set_style_length(ui_Chart1_Yaxis1, 0, LV_PART_INDICATOR);   //major tick length
    lv_scale_set_total_tick_count(ui_Chart1_Yaxis1, (0 > 0 ? 0 - 1 : 0) * 0 + 1);
    lv_scale_set_major_tick_every(ui_Chart1_Yaxis1, 0 >= 1 ? 0 : 1);
    lv_scale_set_label_show(ui_Chart1_Yaxis1, false);
    ui_Chart1_Yaxis2 = lv_scale_create(ui_Chart1);
    lv_scale_set_mode(ui_Chart1_Yaxis2, LV_SCALE_MODE_VERTICAL_RIGHT);
    lv_obj_set_size(ui_Chart1_Yaxis2, 2, lv_pct(100));
    lv_obj_set_align(ui_Chart1_Yaxis2, LV_ALIGN_RIGHT_MID);
    lv_obj_set_x(ui_Chart1_Yaxis2, 2 + lv_obj_get_style_pad_right(ui_Chart1,
                                                                  LV_PART_MAIN) + lv_obj_get_style_border_width(ui_Chart1, LV_PART_MAIN) + 1);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis2, 0, LV_PART_MAIN);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis2, 1, LV_PART_ITEMS);
    lv_obj_set_style_line_width(ui_Chart1_Yaxis2, 1, LV_PART_INDICATOR);
    lv_obj_set_style_length(ui_Chart1_Yaxis2, 0, LV_PART_ITEMS);   //minor tick length
    lv_obj_set_style_length(ui_Chart1_Yaxis2, 0, LV_PART_INDICATOR);   //major tick length
    lv_scale_set_range(ui_Chart1_Yaxis2,  0, 1000);
    lv_scale_set_total_tick_count(ui_Chart1_Yaxis2, (5 > 0 ? 5 - 1 : 0) * 2 + 1);
    lv_scale_set_major_tick_every(ui_Chart1_Yaxis2, 2 >= 1 ? 2 : 1);

    lv_obj_set_style_size(ui_Chart1, 0, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_object_set_themeable_style_property(ui_Chart1_Xaxis, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_defText);
    ui_object_set_themeable_style_property(ui_Chart1_Xaxis, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_defText);
    ui_object_set_themeable_style_property(ui_Chart1_Yaxis1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_defText);
    ui_object_set_themeable_style_property(ui_Chart1_Yaxis1, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_defText);
    ui_object_set_themeable_style_property(ui_Chart1_Yaxis2, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_COLOR,
                                           _ui_theme_color_defText);
    ui_object_set_themeable_style_property(ui_Chart1_Yaxis2, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_TEXT_OPA,
                                           _ui_theme_alpha_defText);
    lv_obj_set_style_text_align(ui_Chart1_Xaxis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Chart1_Yaxis1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Chart1_Yaxis2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    //This workaround (an invisible outline) is needed because without it chart overflow-visible doesn't work in LVGL-9.1
    lv_obj_set_style_outline_pad(ui_Chart1, LV_MAX3(2, 50, 2),
                                 LV_PART_MAIN | LV_STATE_DEFAULT);   //workaround for ineffective 'overflow visible' flag
    lv_obj_set_style_outline_width(ui_Chart1, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_imgSettingsBut = lv_image_create(ui_conChart);
    lv_image_set_src(ui_imgSettingsBut, &ui_img_1471171794);
    lv_obj_set_width(ui_imgSettingsBut, 24);
    lv_obj_set_height(ui_imgSettingsBut, 24);
    lv_obj_set_x(ui_imgSettingsBut, 2);
    lv_obj_set_y(ui_imgSettingsBut, 2);
    lv_obj_set_align(ui_imgSettingsBut, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_imgSettingsBut, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_imgSettingsBut, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_image_set_scale(ui_imgSettingsBut, 150);
    lv_obj_set_style_image_recolor(ui_imgSettingsBut, lv_color_hex(0x8B8B8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(ui_imgSettingsBut, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_panOldData = lv_obj_create(ui_conChart);
    lv_obj_set_width(ui_panOldData, lv_pct(90));
    lv_obj_set_height(ui_panOldData, lv_pct(80));
    lv_obj_set_align(ui_panOldData, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_panOldData, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_panOldData, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_panOldData, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_panOldData, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_panOldData, lv_color_hex(0x4A4C4A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panOldData, 170, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panOldData, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_panOldData, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_panOldData, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_panOldData, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_panOldData, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labOldDataWarn = lv_label_create(ui_panOldData);
    lv_obj_set_width(ui_labOldDataWarn, lv_pct(100));
    lv_obj_set_height(ui_labOldDataWarn, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_labOldDataWarn, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labOldDataWarn, "Warning: data appears to be outdated.");
    lv_obj_set_style_text_color(ui_labOldDataWarn, lv_color_hex(0xEB6666), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labOldDataWarn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_labOldDataWarn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labOldDataWarn, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labOldDataDate = lv_label_create(ui_panOldData);
    lv_obj_set_width(ui_labOldDataDate, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labOldDataDate, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_labOldDataDate, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labOldDataDate, "Last date = xx/xx");
    lv_obj_set_style_text_font(ui_labOldDataDate, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labStartDate = lv_label_create(ui_conChart);
    lv_obj_set_width(ui_labStartDate, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labStartDate, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labStartDate, 2);
    lv_obj_set_y(ui_labStartDate, 3);
    lv_label_set_text(ui_labStartDate, "xx/xx");
    lv_obj_set_style_text_color(ui_labStartDate, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labStartDate, 160, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_labStartDate, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labStartDate, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labEndDate = lv_label_create(ui_conChart);
    lv_obj_set_width(ui_labEndDate, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labEndDate, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labEndDate, -48);
    lv_obj_set_y(ui_labEndDate, 3);
    lv_obj_set_align(ui_labEndDate, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_labEndDate, "xx/xx");
    lv_obj_set_style_text_color(ui_labEndDate, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_labEndDate, 160, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_labEndDate, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_labEndDate, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_imgSettingsBut, ui_event_imgSettingsBut, LV_EVENT_ALL, NULL);

}
