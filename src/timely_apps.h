/**
 * @file timely_apps.h
 *
 */

#ifndef _TIMELY_APPS_H_
#define _TIMELY_APPS_H_

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

void timely_apps_init(lv_obj_t *);

void timely_register_apps(timely_app_t *);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
