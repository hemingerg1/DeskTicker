// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: DeskDisplay_SquareLine_Project

#include "ui.h"


const ui_theme_variable_t _ui_theme_color_defText[1] = {0x807F7F};
const ui_theme_variable_t _ui_theme_alpha_defText[1] = {255};

const ui_theme_variable_t _ui_theme_color_upText[1] = {0x72D679};
const ui_theme_variable_t _ui_theme_alpha_upText[1] = {255};

const ui_theme_variable_t _ui_theme_color_downText[1] = {0xEB6666};
const ui_theme_variable_t _ui_theme_alpha_downText[1] = {255};
uint8_t ui_theme_idx = UI_THEME_DEFAULT;


void ui_theme_set(uint8_t theme_idx)
{
    ui_theme_idx = theme_idx;
    _ui_theme_set_variable_styles(UI_VARIABLE_STYLES_MODE_FOLLOW);
}
