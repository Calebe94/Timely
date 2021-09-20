/**
 * @file timely_watchface.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "timely_watchface.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *hour_label;
static lv_obj_t *minute_label;
static lv_obj_t *datetime_label;
static lv_obj_t *missed_notification_label;
static lv_obj_t *weather_icon;
static lv_obj_t *weather_label;
static lv_style_t style_clock;
static lv_style_t style_date;

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
static void timely_watchface_tile_style_init()
{
    lv_style_init(&style_clock);
    lv_style_set_text_font(&style_clock, &lv_font_montserrat_48);
    lv_style_set_text_color(&style_clock, lv_color_white());

    lv_style_init(&style_date);
    lv_style_set_text_color(&style_date, lv_color_white());
}

static void timely_format_time(int value, char *string)
{
    if(value < 10)
    {
        sprintf(string, "0%d", value);
    }
    else
    {
        sprintf(string, "%d", value);
    }
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_watchface_init(lv_obj_t *reference)
{
    timely_watchface_tile_style_init();

    /*******
     * HOUR
     *******/
    hour_label = lv_label_create(reference);
    lv_label_set_text(hour_label, "19");
    lv_obj_add_style(hour_label, &style_clock, 0);

    lv_label_set_long_mode(hour_label, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(hour_label, true);                      /*Enable re-coloring by commands in the text*/

    lv_obj_set_width(hour_label, 100);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(hour_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(hour_label, LV_ALIGN_CENTER, 0, -80);

    /*********
     * MINUTE
     ********/
    minute_label = lv_label_create(reference);
    lv_label_set_text(minute_label, "20");
    lv_obj_add_style(minute_label, &style_clock, 0);

    lv_label_set_long_mode(minute_label, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(minute_label, true);                      /*Enable re-coloring by commands in the text*/

    lv_obj_set_width(minute_label, 100);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(minute_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(minute_label, LV_ALIGN_CENTER, 0, -30);

    /***********
     * DATETIME
     **********/
    datetime_label = lv_label_create(reference);
    lv_label_set_long_mode(datetime_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    lv_obj_set_width(datetime_label, 100);
    lv_label_set_text(datetime_label, "25 nov. 2021");
    lv_obj_add_style(datetime_label, &style_date, 0);
    lv_obj_align(datetime_label, LV_ALIGN_CENTER, 0, 5);

    /**********************
     * MISSED NOTIFICATION
     *********************/
    missed_notification_label = lv_label_create(reference);
    lv_label_set_long_mode(missed_notification_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    //lv_obj_set_width(missed_notification_label, 90);
    lv_label_set_text(missed_notification_label, "Missed 3 Notifications");
    lv_obj_add_style(missed_notification_label, &style_date, 0);
    lv_obj_align(missed_notification_label, LV_ALIGN_CENTER, 0, 25);

    /**********************
     * WEATHER ICON
     *********************/
    weather_icon = lv_img_create(reference);
    lv_img_set_src(weather_icon, &cloudy_sun_48x48);
    lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, 60);

    /**********************
     * WEATHER LABEL
     *********************/
    weather_label = lv_label_create(reference);
    lv_label_set_long_mode(weather_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    //lv_obj_set_width(missed_notification_label, 90);
    lv_label_set_text(weather_label, "16°C");
    lv_obj_add_style(weather_label, &style_date, 0);
    lv_obj_align(weather_label, LV_ALIGN_CENTER, 0, 90);
}

void timely_watchface_update()
{
    char minute_string[5], hour_string[5], buffer[20];

    time_t current_time;
    struct tm * tminfo;
    time(&current_time);
    tminfo = localtime ( &current_time );
    timely_format_time(tminfo->tm_hour, hour_string);
    lv_label_set_text(hour_label, hour_string);
    timely_format_time(tminfo->tm_min, minute_string);
    lv_label_set_text(minute_label, minute_string);
    strftime(buffer, 20, "%d - %m - %Y", tminfo);
    lv_label_set_text(datetime_label, buffer);
    printf("Current time = %s", ctime(&current_time));
}
