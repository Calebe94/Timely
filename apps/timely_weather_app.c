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
static lv_obj_t *weather_icon;
static lv_obj_t *weather_label;
static lv_style_t style_hour;


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
static void timely_weather_app_style_init()
{
    lv_style_init(&style_hour);
    lv_style_set_text_font(&style_hour, &lv_font_montserrat_48);
}

static void timely_format_time(int value, char *string)
{
    if(value < 9)
    {
        sprintf(string, "0%d", value);
    }
    else
    {
        sprintf(string, "%d", value);
    }
}

static void weather_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("Toggled");

    }
}
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_weather_init(void *context)
{
    lv_obj_t * context_obj = ((timely_app_t *) context)->context;

    LV_LOG_USER("Clicked");
    LV_LOG_USER( ((timely_app_t *) context)->name );

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
