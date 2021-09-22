#ifndef _TIMELY_CONFIG_H_
#define _TIMELY_CONFIG_H_
#include "timely.h"

/****************************
 * CONFIG MACROS
 ***************************/
#define USE_APPLICATIONS    1
#define USE_SETTINGS        0
#define USE_NOTIFICATIONS   0
#define USE_TRAY            0

/****************************
 * IMAGES DECLARATIONS
 * Applications icons
 ***************************/
LV_IMG_DECLARE(weather_48x48);
LV_IMG_DECLARE(clock_48x48);
LV_IMG_DECLARE(alarm_48x48);
LV_IMG_DECLARE(activity_48x48);

/****************************
 * APPLICATIONS FUNCTIONS
 ***************************/
extern void timely_weather_init(void *);

/****************************
 * APPLICATIONS LIST
 ***************************/
static timely_app_t apps[] = {
    { "Weather",    "A simple weather forecast app.",   {0, 1, 0}, &weather_48x48,      timely_weather_init, NULL, NULL,                  NULL },
    { "Clock",      "A simple clock app.",              {0, 1, 0}, &clock_48x48,        NULL,                NULL, NULL,                  NULL },
    { "Alarm",      "A simple alarm app.",              {0, 1, 0}, &alarm_48x48,        NULL,                NULL, NULL,                  NULL },
    { "Activity",   "A simple activity app tracker.",   {0, 1, 0}, &activity_48x48,     NULL,                NULL, NULL,                  NULL },
};

#endif
