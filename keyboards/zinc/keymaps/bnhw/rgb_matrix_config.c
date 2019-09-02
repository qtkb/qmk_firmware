#include QMK_KEYBOARD_H
#include "rgb_matrix_config.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config =
{
    // Key Matrix to LED Index
    {
        // Left
        { 0,  1,   2,  3,  4,  5 },
        { 11, 10,  9,  8,  7,  6 },
        { 12, 13, 14, 15, 16, 17 },
        { 23, 22, 21, 20, 19, 18 },
        // Right
        { 24, 25, 26, 27, 28, 29 },
        { 35, 34, 33, 32, 31, 30 },
        { 36, 37, 38, 39, 40, 41 },
        { 47, 46, 45, 44, 43, 42 }
    },
    // LED Index to Physical Position
    {
        // Left
        { 0, 0 }, { 20, 0 }, { 40, 0 }, { 60, 0 }, { 80, 0 }, { 100, 0 },
        { 105, 20 }, { 85, 20 }, { 65, 20 }, { 45, 20 }, { 15, 20 }, { 5, 20 },
        { 10, 40 }, { 30, 40 }, { 50, 40 }, { 70, 40 }, { 90, 40 }, { 110, 40 },
        { 115, 60 }, { 95, 60 }, { 75, 60 }, { 55, 60 }, { 35, 60 }, { 15, 60 },
        // Right
        { 120, 0 }, { 140, 0 }, { 160, 0 }, { 180, 0 }, { 200, 0 }, { 220, 0 },
        { 225, 20 }, { 205, 20 }, { 185, 20 }, { 165, 20 }, { 135, 20 }, { 125, 20 },
        { 130, 40 }, { 150, 40 }, { 170, 40 }, { 190, 40 }, { 210, 40 }, { 230, 40 },
        { 235, 60 }, { 215, 60 }, { 195, 60 }, { 175, 60 }, { 155, 60 }, { 135, 60 },
    },
    // LED Index to Flag
    {
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4
    }
};

void swap_matrix_hands(led_config_t* led_config)
{
    uint8_t uint8;
    point_t point;
    int i, j;

    int half_matrix_rows = MATRIX_ROWS / 2;
    int half_driver_led_total = DRIVER_LED_TOTAL / 2;

    for (i = 0; i < half_matrix_rows; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            uint8 = led_config->matrix_co[i][j];
            led_config->matrix_co[i][j] = led_config->matrix_co[i + half_matrix_rows][j];
            led_config->matrix_co[i + half_matrix_rows][j] = uint8;
        }
    }

    for (i = 0; i < half_driver_led_total; i++)
    {
        point = led_config->point[i];
        led_config->point[i] = led_config->point[i + half_driver_led_total];
        led_config->point[i + half_driver_led_total] = point;
    }
}
#endif
