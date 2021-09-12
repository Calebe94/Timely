/**
 * @file timely_data.h
 *
 */

#ifndef _TIMELY_DATA_H_
#define _TIMELY_DATA_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "../timely.h"
#include "timely_weather_data.h"
/*********************
 *      DEFINES
 *********************/
#define MAX_BUFFER_SIZE      32

/**********************
 *      TYPEDEFS
 **********************/
typedef struct timely_version {
    uint8_t major;
    uint8_t minor;
    uint8_t bugfix;
} timely_version_t;

typedef struct timely_app {
    char name[MAX_BUFFER_SIZE];          // app name
    char description[MAX_BUFFER_SIZE];   // short description
    timely_version_t version;            // version of the app
    const lv_img_dsc_t *icon;            // app icon
    void (*on_init)(void *);             // function that inits the app
    void (*on_change)(void*);            // function used to update info on the app
    void (*on_close)(void *);            // function to unitialize the app
} timely_app_t;
/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus

} /* extern "C" */
#endif

#endif
