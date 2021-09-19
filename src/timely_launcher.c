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
 *  STATIC PROTOTYPES
 **********************/

static void auto_del(lv_obj_t * obj, uint32_t delay)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, 0);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
    lv_anim_start(&a);
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
    lv_obj_t * obj;

    lv_style_t text_style;
    lv_style_init(&text_style);
    lv_style_set_text_font(&text_style, &lv_font_montserrat_48);  /*Set a larger font*/

    static lv_style_t style_tileview;
    lv_style_init(&style_tileview);
    lv_style_set_bg_color(&style_tileview, lv_color_black());

    lv_obj_t * timely_tv = lv_tileview_create(lv_scr_act());
    lv_obj_set_size(timely_tv, 240, 240);
    lv_obj_set_scrollbar_mode(timely_tv, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(timely_tv, &style_tileview, 0);

    obj = lv_tileview_add_tile(timely_tv, 1, 0, LV_DIR_VER);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Settings: 1;0");
    //lv_obj_add_style(obj, &text_style, 0);

    obj = lv_tileview_add_tile(timely_tv, 1, 1, LV_DIR_ALL);
    timely_watchface_init(obj);
    //obj = lv_label_create(obj);
    //lv_label_set_text(obj, "Main Tile: 1;1");

    obj = lv_tileview_add_tile(timely_tv, 1, 2, LV_DIR_VER);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Notifications: 1;2");

    obj = lv_tileview_add_tile(timely_tv, 2, 1, LV_DIR_HOR);
    //obj = lv_label_create(obj);
    //lv_label_set_text(obj, "Apps: 2;1");
    init_apps((lv_obj_t*) obj);

    obj = lv_tileview_add_tile(timely_tv, 0, 1, LV_DIR_HOR);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Favorites: 1;2");

    lv_obj_set_tile_id(timely_tv, 1, 1, LV_ANIM_OFF);
}
