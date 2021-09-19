/**
 * @file timely_watchface.h
 *
 */

#ifndef _TIMELY_WATCHFACE_SCREEN_H_
#define _TIMELY_WATCHFACE_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../timely.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void timely_watchface_init(lv_obj_t *reference);

void timely_watchface_update();

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
