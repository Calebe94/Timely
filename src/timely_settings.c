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

#include "timely_launcher.h"

#include "timely_settings.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *wifi_button;
static lv_obj_t *bluetooth_button;
static lv_obj_t *sound_button;
static lv_obj_t *motor_button;
static lv_obj_t *secreen_brightness_slider;
static lv_obj_t *steps_counter_button;
static lv_obj_t *settings_button;
static lv_obj_t *power_button;
static lv_obj_t *timely_settings_tile;
/***************** *****
 *  GLOBAL VARIABLES
 **********************/

/**********************
 *  STATIC FUNCTIONS
 **********************/
static void timely_settings_style_init()
{

}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void timely_settings_init(lv_obj_t *context)
{
    timely_settings_style_init();
    timely_settings_tile = context;
    lv_obj_t * timely_tv = lv_obj_get_parent(timely_settings_tile);
    lv_obj_set_scrollbar_mode(context, LV_SCROLLBAR_MODE_OFF);

    wifi_button = lv_btn_create(context);
    lv_obj_align(wifi_button, LV_ALIGN_OUT_TOP_MID, 0, 0);
    lv_obj_t *wifi_label = lv_label_create(wifi_button);
    lv_label_set_text(wifi_label, LV_SYMBOL_WIFI);

    bluetooth_button = lv_btn_create(context);
    lv_obj_align(bluetooth_button, LV_ALIGN_OUT_TOP_MID, 50, 0);
    lv_obj_t *bluetooth_label = lv_label_create(bluetooth_button);
    lv_label_set_text(bluetooth_label, LV_SYMBOL_BLUETOOTH);
}
