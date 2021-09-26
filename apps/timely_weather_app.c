/**
 * @file timely_main.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "timely_weather_app.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *weather_name_label;
static lv_obj_t *weather_description_label;
static lv_obj_t *weather_icon;
static lv_obj_t *weather_label;
static lv_style_t style_name;
static lv_style_t style_description;

/**********************
 *  IMAGE DECLARATIONS
 **********************/
LV_IMG_DECLARE(cloudy_sun_48x48);

/**********************
 *  GLOBAL VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void timely_weather_style_init()
{
    lv_style_init(&style_name);
    lv_style_set_text_font(&style_name, &lv_font_montserrat_28);
    lv_style_set_text_color(&style_name, lv_color_white());

    lv_style_init(&style_description);
    lv_style_set_text_font(&style_description, &lv_font_montserrat_14);
    lv_style_set_text_color(&style_description, lv_color_white());
}
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_weather_init(void *context)
{
    timely_weather_style_init();
    lv_obj_t * context_obj = ((timely_app_t *) context)->context;

    LV_LOG_USER( ((timely_app_t *) context)->name );

    /**********************
     * WEATHER APP NAME
     *********************/
    weather_name_label = lv_label_create(context_obj);
    lv_label_set_long_mode(weather_name_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    lv_label_set_text(weather_name_label, ((timely_app_t *) context)->name);
    lv_obj_add_style(weather_name_label, &style_name, 0);
    lv_obj_align(weather_name_label, LV_ALIGN_CENTER, 0, -80);

    /**********************
     * WEATHER APP Description
     *********************/
    weather_description_label = lv_label_create(context_obj);
    lv_label_set_long_mode(weather_description_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    lv_label_set_text(weather_description_label, ((timely_app_t *) context)->description);
    lv_obj_add_style(weather_description_label, &style_description, 0);
    lv_obj_align(weather_description_label, LV_ALIGN_CENTER, 0, 0);

    /**********************
     * WEATHER ICON
     *********************/
    weather_icon = lv_img_create(context_obj);
    lv_img_set_src(weather_icon, &cloudy_sun_48x48);
    lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, 60);

    /**********************
     * WEATHER LABEL
     *********************/
    weather_label = lv_label_create(context_obj);
    lv_label_set_long_mode(weather_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    //lv_obj_set_width(missed_notification_label, 90);
    lv_label_set_text(weather_label, "16°C");
    lv_obj_align(weather_label, LV_ALIGN_CENTER, 0, 90);
}
