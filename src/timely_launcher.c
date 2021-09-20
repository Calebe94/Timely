/**
 * @file timely_launcher.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include "timely_launcher.h"
#include "timely_watchface.h"
#include "../timely_config.h"

/*********************
 *      DEFINES
 *********************/
#define TIME_STEP   50

/**********************
 *  EXTERNAL VARIABLES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_style_t style_tileview;
static lv_obj_t *timely_tileview;
static lv_obj_t *timely_watchface_tile;
#if USE_APPLICATIONS == 1
static lv_obj_t *timely_apps_tile;
#endif
#if USE_NOTIFICATIONS == 1
static lv_obj_t *timely_notifications_tile;
#endif
#if USE_SETTINGS == 1
static lv_obj_t *timely_settings_tile;
#endif
#if USE_TRAY == 1
static lv_obj_t *timely_tray_tile;
#endif

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void timely_launcher_style_init()
{
    lv_style_init(&style_tileview);
    lv_style_set_bg_color(&style_tileview, lv_color_black());
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        LV_LOG_USER("Clicked");
        timely_app_t *app = (timely_app_t*)lv_event_get_user_data(e);

        app->on_init((void*)app);

        lv_obj_set_tile_id(lv_obj_get_parent(app->context), 3, 1, LV_ANIM_ON);
    }
    else if(code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("Toggled");
    }
}

static void init_apps(void *argv)
{
    static lv_style_t font_style;
    static lv_style_t style_btn;

    lv_style_init(&font_style);
    lv_style_init(&style_btn);

    lv_style_set_text_font(&font_style, &lv_font_montserrat_28);
    lv_style_set_bg_color(&style_btn, lv_color_hex(0x2f3237));

    lv_obj_t * label, *icon;
    lv_obj_t *context = (lv_obj_t*)argv;

    int app_align = -80;
    for(int index = 0; index < LENGTH(apps); index++)
    {
        lv_obj_t * btn1 = lv_btn_create(context);
        lv_obj_set_scrollbar_mode(context, LV_SCROLLBAR_MODE_OFF);
        lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, (void*)&apps[index]);
        lv_obj_align(btn1, LV_ALIGN_CENTER, 0, app_align );
        lv_obj_add_style(btn1, &style_btn, 0);

        if (apps[index].icon != NULL)
        {
            icon = lv_img_create(btn1);
            lv_obj_align(icon, LV_ALIGN_LEFT_MID, 0, 0);
            lv_img_set_src(icon, apps[index].icon);
            //lv_img_set_src(icon, &activity_48x48);
        }
        apps[index].context = argv;

        // App title label
        label = lv_label_create(btn1);
        lv_label_set_text(label, apps[index].name);
        //lv_obj_center(label);
        lv_obj_align(label, LV_ALIGN_CENTER, 30, 5);
        lv_obj_set_size(label, 150, 40);

        lv_obj_add_style(label, &font_style, 0);

        printf("%s - %s\n", apps[index].name, apps[index].description);
        app_align += 80;
    }
}

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_launcher_init(void)
{
    timely_launcher_style_init();

    timely_tileview = lv_tileview_create(lv_scr_act());
    lv_obj_set_size(timely_tileview, 240, 240);
    lv_obj_set_scrollbar_mode(timely_tileview, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(timely_tileview, &style_tileview, 0);

    timely_watchface_tile = lv_tileview_add_tile(timely_tileview, 1, 1, LV_DIR_ALL);
    lv_obj_set_tile(timely_tileview, timely_watchface_tile, LV_ANIM_OFF);
    timely_watchface_init(timely_watchface_tile);

    #if USE_SETTINGS == 1
    timely_settings_tile = lv_tileview_add_tile(timely_tileview, 1, 0, LV_DIR_VER);
    #endif

    #if USE_NOTIFICATIONS == 1
    timely_notifications_tile = lv_tileview_add_tile(timely_tileview, 1, 2, LV_DIR_VER);
    #endif

    #if USE_APPLICATIONS == 1
    timely_apps_tile = lv_tileview_add_tile(timely_tileview, 2, 1, LV_DIR_HOR);
    //init_apps((lv_obj_t*) timely_apps_tile);
    timely_apps_init(timely_apps_tile);
    #endif

    #if USE_TRAY == 1
    timely_tray_tile = lv_tileview_add_tile(timely_tileview, 0, 1, LV_DIR_HOR);
    #endif

    lv_obj_set_tile_id(timely_tileview, 1, 1, LV_ANIM_OFF);
}


void timely_launcher_go_to_watchface(void)
{
    lv_obj_set_tile_id(timely_tileview, 1, 1, LV_ANIM_OFF);
}

void timely_launcher_go_to_apps(void)
{
    lv_obj_set_tile_id(timely_tileview, 2, 1, LV_ANIM_OFF);
}

void timely_launcher_go_to_notifications(void)
{
    lv_obj_set_tile_id(timely_tileview, 1, 2, LV_ANIM_OFF);
}

void timely_launcher_go_to_settings(void)
{
    lv_obj_set_tile_id(timely_tileview, 1, 0, LV_ANIM_OFF);
}

void timely_launcher_go_to_tray(void)
{
    lv_obj_set_tile_id(timely_tileview, 0, 1, LV_ANIM_OFF);
}
