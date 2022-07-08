/**
 * @file timely_lock_screen.h
 *
 */

#ifndef _TIMELY_LOCK_SCREEN_H_
#define _TIMELY_LOCK_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "timely.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void timely_lock_screen_init();

void timely_lock_screen_update();

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
