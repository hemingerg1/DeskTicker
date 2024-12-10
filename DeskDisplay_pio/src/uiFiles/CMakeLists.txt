SET(SOURCES screens/ui_ScrHome.c
    screens/ui_ScrSleep.c
    screens/ui_ScrSettings.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_1471171794.c
    images/ui_img_home_png.c)

add_library(ui ${SOURCES})
