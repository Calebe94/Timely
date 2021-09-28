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
static lv_obj_t *bell_button;
static lv_obj_t *secreen_brightness_slider;
static lv_obj_t *steps_counter_button;
static lv_obj_t *settings_button;
static lv_obj_t *power_button;
static lv_obj_t *timely_settings_tile;
static lv_style_t control_buttons_style;

/***************** *****
 *  GLOBAL VARIABLES
 **********************/

/**********************
 *  STATIC FUNCTIONS
 **********************/
static void timely_settings_style_init()
{
    lv_style_init(&control_buttons_style);
    lv_style_set_text_font(&control_buttons_style, &lv_font_montserrat_28);
    lv_style_set_bg_color(&control_buttons_style, lv_color_hex(0xCD7B30));
    lv_style_set_text_color(&control_buttons_style, lv_color_white());
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void timely_settings_init(lv_obj_t *context)
{
    timely_settings_style_init();
    timely_settings_tile = context;

    lv_obj_set_scrollbar_mode(context, LV_SCROLLBAR_MODE_OFF);

    /*******************
     * Control Buttons
     ******************/
    wifi_button = lv_btn_create(context);
    lv_obj_add_style(wifi_button, &control_buttons_style, 0);
    lv_obj_align(wifi_button, LV_ALIGN_TOP_LEFT, 8, 10);
    lv_obj_set_size(wifi_button, 50, 50);
    lv_obj_t *wifi_label = lv_label_create(wifi_button);
    lv_obj_set_align(wifi_label, LV_ALIGN_CENTER);
    lv_label_set_text(wifi_label, LV_SYMBOL_WIFI);

    bluetooth_button = lv_btn_create(context);
    lv_obj_add_style(bluetooth_button, &control_buttons_style, 0);
    lv_obj_align(bluetooth_button, LV_ALIGN_OUT_TOP_MID, 66, 10);
    lv_obj_set_size(bluetooth_button, 50, 50);
    lv_obj_t *bluetooth_label = lv_label_create(bluetooth_button);
    lv_obj_set_align(bluetooth_label, LV_ALIGN_CENTER);
    lv_label_set_text(bluetooth_label, LV_SYMBOL_BLUETOOTH);

    bell_button = lv_btn_create(context);
    lv_obj_add_style(bell_button, &control_buttons_style, 0);
    lv_obj_align(bell_button, LV_ALIGN_TOP_RIGHT, -66, 10);
    lv_obj_set_size(bell_button, 50, 50);
    lv_obj_t *bell_label = lv_label_create(bell_button);
    lv_obj_set_align(bell_label, LV_ALIGN_CENTER);
    lv_label_set_text(bell_label, LV_SYMBOL_BELL);

    sound_button = lv_btn_create(context);
    lv_obj_add_style(sound_button, &control_buttons_style, 0);
    lv_obj_align(sound_button, LV_ALIGN_TOP_RIGHT, -8, 10);
    lv_obj_set_size(sound_button, 50, 50);
    lv_obj_t *sound_label = lv_label_create(sound_button);
    lv_obj_set_align(sound_label, LV_ALIGN_CENTER);
    lv_label_set_text(sound_label, LV_SYMBOL_VOLUME_MAX);
}
