/**
 * @file timely_weather_data.h
 *
 */

#ifndef _TIMELY_WEATHER_DATA_H_
#define _TIMELY_WEATHER_DATA_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <time.h>
#include "../timely.h"
#include "timely_data.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
// https://openweathermap.org/weather-conditions
// https://openweathermap.org/guide

/**************************
 * Weather Condition Codes
 *************************/
typedef enum {
    /**************************
    * Weather: Thunderstorm
    *************************/
    THUNDERSTORM_WITH_LIGHT_RAIN = 200,
    THUNDERSTORM_WITH_RAIN,
    THUNDERSTORM_WITH_HEAVY_RAIN,
    LIGHT_THUNDERSTORM = 210,
    THUNDERSTORM,
    HEAVY_THUNDERSTORM,
    RAGGED_THUNDERSTORM = 221,
    THUNDERSTORM_WITH_LIGHT_DRIZZLE = 230,
    THUNDERSTORM_WITH_DRIZZLE,
    THUNDERSTORM_WITH_HEAVY_DRIZZLE,

    /**************************
    * Weather: Drizzle
    *************************/
    LIGHT_INTENSITY_DRIZZLE = 300,
    DRIZZLE,
    HEAVY_INTENSITY_DRIZZLE,
    LIGHT_INTENSITY_DRIZZLE_RAIN = 310,
    DRIZZLE_RAIN,
    HEAVY_INTENSITY_DRIZZLE_RAIN,
    SHOWER_RAIN_AND_DRIZZLE,
    HEAVY_SHOWER_RAIN_AND_DRIZZLE,
    SHOWER_DRIZZLE = 321,

    /**************************
    * Weather: Rain
    *************************/
    LIGHT_RAIN = 500,
    MODERATE_RAIN,
    HEAVY_INTENSITY_RAIN,
    VERY_HEAVY_RAIN,
    EXTREME_RAIN,
    FREEZING_RAIN = 511,
    LIGHT_INTENSITY_SHOWER_RAIN = 520,
    SHOWER_RAIN = 521,
    HEAVY_INTENSITY_SHOWER_RAIN,
    RAGGED_SHOWER_RAIN = 531,

    /**************************
    * Weather: Snow
    *************************/
    LIGHT_SNOW = 600,
    SNOW,
    HEAVY_SNOW,
    SLEET = 611,
    LIGHT_SHOWER_SLEET,
    SHOWER_SLEET,
    LIGHT_RAIN_AND_SNOW = 615,
    RAIN_AND_SNOW,
    LIGHT_SHOWER_SNOW = 620,
    SHOWER_SNOW,
    HEAVY_SHOWER_SNOW,

    /**************************
    * Weather: Atmosphere
    *************************/
    MIST = 701,
    SMOKE = 711,
    HAZE = 721,
    DUST_WHIRLS = 731,
    FOG = 741,
    SAND = 751,
    DUST = 761,
    VOLCANIC_ASH,
    SQUALLS = 771,
    TORNADO = 781,

    /**************************
    * Weather: Clouds
    *************************/
    CLEAR_SKY = 800,
    FEW_CLOUDS,
    SCATTERED_CLOUDS,
    BROKEN_CLOUDS,
    OVERCAST_CLOUDS
} timely_weather_condition_codes_t;

// https://openweathermap.org/current
typedef struct timely_raw_weather {
    timely_weather_condition_codes_t id;  // Weather Condition codes
    char main[MAX_BUFFER_SIZE];
    char description[MAX_BUFFER_SIZE];
    int icon;
} timely_weather_condition_t;

typedef struct timely_weather_temp {
    float temp_k;
    float temp_c;
    float temp_f;
    float feels_like;
    float temp_min;
    int pressure;
    int humidity;
} timely_weather_main_t;

typedef struct timely_weather_sys {
    char country_code[3];
    char city[MAX_BUFFER_SIZE];
    time_t sunrise;
    time_t sunset;
} timely_weather_sys_t;

typedef struct timely_weather_wind {
    float speed;
    int degrees;
} timely_weather_wind_t;

typedef struct timely_weather {
    timely_weather_condition_t condition;
    timely_weather_main_t main;
    timely_weather_sys_t sys;
    timely_weather_wind_t wind;
    time_t timestamp;
} timely_weather_t;

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
