/* Copyright 2019 Benjamin Davis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x4748
#define DEVICE_VER      0x0001
#define MANUFACTURER    qtkb
#define PRODUCT         tsunami
#define DESCRIPTION     Keyboard

#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { F4, F7, B5, B2 }
#define MATRIX_COL_PINS { D7, B1, E6, B3, B4, B6 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCING_DELAY 5

#define SOFT_SERIAL_PIN D2
