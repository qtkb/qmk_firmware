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
#define PRODUCT_ID      0x4745
#define DEVICE_VER      0x0001
#define MANUFACTURER    qtkb
#define PRODUCT         qt45
#define DESCRIPTION     Keyboard

#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { C7, C6, D3, D0 }
#define MATRIX_COL_PINS { B5, B6, B4, D7, D6, D5, D4, F0, F7, F6, F5, E6, F4, F1 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCING_DELAY 5
