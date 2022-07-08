/**
 * @file timely_apps.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "timely_apps.h"
#include "timely_data.h"
#include "timely_watchface.h"
#include "timely_config.h"

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
static lv_style_t font_style;
static lv_style_t style_btn;

/* #if USE_APPLICATIONS == 1 */
static lv_obj_t *timely_apps_tile;
static lv_obj_t *timely_app_tile;
static timely_app_t *current_app;
/* #endif */

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void timely_apps_style_init()
{
    lv_style_init(&font_style);
    lv_style_init(&style_btn);

    lv_style_set_text_font(&font_style, &lv_font_montserrat_28);
    lv_style_set_bg_color(&style_btn, lv_color_hex(0x2f3237));
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        LV_LOG_USER("Clicked");
        timely_app_t *app = (timely_app_t*)lv_event_get_user_data(e);
        app->context = timely_app_tile;
        current_app = app;
        //lv_obj_add_event_cb(timely_tv, weather_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
        if(app->on_init != NULL)
        {
            app->on_init((void*)app);
            lv_obj_clear_flag(timely_app_tile, LV_OBJ_FLAG_HIDDEN);
            //lv_obj_set_tile(timely_tv, weather_app_tile, LV_ANIM_ON);
            lv_obj_set_tile_id(lv_obj_get_parent(timely_apps_tile), 3, 1, LV_ANIM_ON);
        }
    }
    else if(code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("Toggled");
    }
}

static void timely_app_event_handler(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);

    if (code == LV_EVENT_DEFOCUSED)
    {
        if (current_app != NULL && current_app->on_close != NULL)
        {
            current_app->on_close((void*)current_app);
            current_app = NULL;
        }
        LV_LOG_USER("Saiu da tela do aplicativo");

        lv_obj_clean(timely_app_tile);
        lv_obj_add_flag(timely_app_tile, LV_OBJ_FLAG_HIDDEN);
    }
}

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_apps_init(lv_obj_t *context)
{
    timely_apps_style_init();
    timely_apps_tile = context;
    lv_obj_t * timely_tv = lv_obj_get_parent(timely_apps_tile);
    timely_app_tile = lv_tileview_add_tile(timely_tv, 3, 1, LV_DIR_HOR);
    lv_obj_add_event_cb(timely_app_tile, timely_app_event_handler, LV_EVENT_DEFOCUSED, NULL);
    lv_obj_add_flag(timely_app_tile, LV_OBJ_FLAG_HIDDEN);
    #if USE_APPLICATIONS == 1
    #endif
    lv_obj_t * label, *icon;

    int app_align = -80;
    if (timely_apps == NULL)
    {
        printf("timely_apps is NULL\n");
    }
    else
    {
        printf("timely_apps is not NULL: %d\n", LENGTH(timely_apps));
        for(int index = 0; index < LENGTH(timely_apps); index++)
        {
            lv_obj_t * btn1 = lv_btn_create(context);
            lv_obj_set_scrollbar_mode(context, LV_SCROLLBAR_MODE_OFF);
            lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, (void*)&timely_apps[index]);
            lv_obj_align(btn1, LV_ALIGN_CENTER, 0, app_align );
            lv_obj_add_style(btn1, &style_btn, 0);

            if (timely_apps[index].icon != NULL)
            {
                icon = lv_img_create(btn1);
                lv_obj_align(icon, LV_ALIGN_LEFT_MID, 0, 0);
                lv_img_set_src(icon, timely_apps[index].icon);
                //lv_img_set_src(icon, &activity_48x48);
            }
            timely_apps[index].context = timely_app_tile;

            // App title label
            label = lv_label_create(btn1);
            lv_label_set_text(label, timely_apps[index].name);
            //lv_obj_center(label);
            lv_obj_align(label, LV_ALIGN_CENTER, 30, 5);
            lv_obj_set_size(label, 150, 40);

            lv_obj_add_style(label, &font_style, 0);

            printf("%s - %s\n", timely_apps[index].name, timely_apps[index].description);
            app_align += 80;
        }
    }
}

void timely_register_apps(timely_app_t *apps)
{
    if(apps == NULL)
    {
        printf("apps is null\n");
    }
    else
    {
        printf("apps is not null: %d\n", LENGTH(apps));
        /* timely_apps = (timely_app_t*)malloc(sizeof(timely_app_t)*LENGTH(apps)); */
        /* timely_apps = apps; */
        printf("timely_apps: %d\n", LENGTH(timely_apps));
    }
    /* memcpy((void*)apps, (void*)timely_apps, sizeof(apps)); */
}
