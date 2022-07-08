/**
 * @file timely_launcher.h
 *
 */

#ifndef _TIMELY_H_
#define _TIMELY_H_

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

/*
timely_launcher: functions to control the launcher;
    _init: this function will initiate the launcher and should take no argument;
    _set_weather: function to update the weather info on UI. The info's described in timely_weather_data.h;
    _set_notifications: function to update the notifications info on UI. (There is no struct data yet);
    _go_to_watchface: function to make UI change its context to watchface tile;
    _go_to_apps: function to make UI change its context to applications tile;
    _go_to_notifications: function to make UI change its context to notifications tile;
    _go_to_tray: function to make UI change its context to tray tile;
    _go_to_app: function to make UI change its context to a given app tile;
    _go_back: go back by one tile;
    _deinit: this function will initiate the launcher and should take no argument;
*/

void timely_launcher_init(void);

void timely_launcher_go_to_watchface(void);

void timely_launcher_go_to_apps(void);

void timely_launcher_go_to_notifications(void);

void timely_launcher_go_to_settings(void);

void timely_launcher_go_to_tray(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
