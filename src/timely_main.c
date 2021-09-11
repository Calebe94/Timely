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

#include "timely_main.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *hour_label;
static lv_obj_t *minute_label;
static lv_obj_t *datetime_label;
static lv_style_t style_hour;

/***************** *****
 *  GLOBAL VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void timely_main_tile_style_init()
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

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_main_init(lv_obj_t *reference)
{
    timely_main_tile_style_init();

    /*******
     * HOUR
     *******/
    hour_label = lv_label_create(reference);
    lv_label_set_text(hour_label, "19");
    lv_obj_add_style(hour_label, &style_hour, 0);

    lv_label_set_long_mode(hour_label, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(hour_label, true);                      /*Enable re-coloring by commands in the text*/

    lv_obj_set_width(hour_label, 100);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(hour_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(hour_label, LV_ALIGN_CENTER, 0, -40);

    /*********
     * MINUTE
     ********/
    minute_label = lv_label_create(reference);
    lv_label_set_text(minute_label, "20");
    lv_obj_add_style(minute_label, &style_hour, 0);

    lv_label_set_long_mode(minute_label, LV_LABEL_LONG_WRAP);     /*Break the long lines*/
    lv_label_set_recolor(minute_label, true);                      /*Enable re-coloring by commands in the text*/

    lv_obj_set_width(minute_label, 100);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(minute_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(minute_label, LV_ALIGN_CENTER, 0, 10);

    /***********
     * DATETIME
     **********/
    datetime_label = lv_label_create(reference);
    lv_label_set_long_mode(datetime_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    lv_obj_set_width(datetime_label, 90);
    lv_label_set_text(datetime_label, "25 nov. 2021");
    lv_obj_align(datetime_label, LV_ALIGN_CENTER, 0, 50);
}

void timely_main_update()
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
