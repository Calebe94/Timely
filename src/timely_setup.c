/**
 * @file timely.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include "timely_setup.h"

/*********************
 *      DEFINES
 *********************/

#define TIME_STEP   50

/**********************
 *      TYPEDEFS
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
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void timely_launcher_init(void)
{
    lv_obj_t * obj;

    lv_obj_t * timely_tv = lv_tileview_create(lv_scr_act());
    lv_obj_set_size(timely_tv, 240, 240);
    lv_obj_set_scrollbar_mode(timely_tv, LV_SCROLLBAR_MODE_OFF);

    obj = lv_tileview_add_tile(timely_tv, 1, 0, LV_DIR_VER);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Settings: 1;0");

    obj = lv_tileview_add_tile(timely_tv, 1, 1, LV_DIR_ALL);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Main Tile: 1;1");

    obj = lv_tileview_add_tile(timely_tv, 1, 2, LV_DIR_VER);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Notifications: 1;2");

    obj = lv_tileview_add_tile(timely_tv, 2, 1, LV_DIR_HOR);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Apps: 2;1");

    obj = lv_tileview_add_tile(timely_tv, 0, 1, LV_DIR_HOR);
    obj = lv_label_create(obj);
    lv_label_set_text(obj, "Favorites: 1;2");

    lv_obj_set_tile_id(timely_tv, 1, 1, LV_ANIM_OFF);
}
