/**
 * @file timely_lock_screen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "timely_main.h"

#include "timely_lock_screen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *lock_screen_button;
static lv_obj_t *hour_label;
static lv_obj_t *minute_label;
static lv_obj_t *datetime_label;
static lv_obj_t *notification_led;
static lv_style_t style_hour;

/***************** *****
 *  GLOBAL VARIABLES
 **********************/

/**********************
 *  STATIC FUNCTIONS
 **********************/
static void timely_lock_screen_style_init()
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

static void lock_screen_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        timely_launcher_init();
        timely_main_update();
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void timely_lock_screen_init()
{
    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_bg_color(&style_btn, lv_color_black());

    timely_lock_screen_style_init();
    lock_screen_button = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(lock_screen_button, lock_screen_event_handler, LV_EVENT_ALL, NULL);
    //lv_obj_align(lock_screen_button, LV_ALIGN_CENTER, 0, -40);
    lv_obj_set_size(lock_screen_button, 240, 240);
    lv_obj_add_style(lock_screen_button, &style_btn, 0);

    /*******
     * HOUR
     *******/
    hour_label = lv_label_create(lock_screen_button);
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
    minute_label = lv_label_create(lock_screen_button);
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
    datetime_label = lv_label_create(lock_screen_button);
    lv_label_set_long_mode(datetime_label, LV_LABEL_LONG_WRAP);     /*Circular scroll*/
    lv_obj_set_width(datetime_label, 90);
    lv_label_set_text(datetime_label, "25 nov. 2021");
    lv_obj_align(datetime_label, LV_ALIGN_CENTER, 0, 50);

    /*******************
     * Notification LED
     ******************/
    notification_led  = lv_led_create(lock_screen_button);
    lv_obj_align(notification_led, LV_ALIGN_CENTER, 0, 80);
    lv_obj_set_size(notification_led, 10, 10);
    lv_led_set_brightness(notification_led, 150);
    lv_led_set_color(notification_led, lv_palette_main(LV_PALETTE_ORANGE));
    lv_led_on(notification_led);
    lv_obj_add_flag(notification_led, LV_OBJ_FLAG_HIDDEN);
}

void timely_lock_screen_update()
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
    lv_obj_clear_flag(notification_led, LV_OBJ_FLAG_HIDDEN);
}
