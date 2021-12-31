/* Copyright 2019
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

#define PRODUCT Onekey Pro Micro

#define MATRIX_COL_PINS { F4 }
#define MATRIX_ROW_PINS { F5 }
#define UNUSED_PINS

#define BACKLIGHT_PIN B6

#define RGB_DI_PIN F6
#define RGB_CI_PIN B1

#define ADC_PIN F6

// clock on pin 3 (d0, int0)
#define PS2_CLOCK_PORT PORTD
#define PS2_CLOCK_PIN PIND
#define PS2_CLOCK_DDR DDRD
#define PS2_CLOCK_BIT 0
#define PS2_INT_INIT() do { EICRA |= ((1<<ISC01) | (0<<ISC00)); } while (0)
#define PS2_INT_ON() do { EIMSK |= (1<<INT0); } while (0)
#define PS2_INT_OFF() do { EIMSK &= ~(1<<INT0); } while (0)
#define PS2_INT_VECT INT0_vect
// data on pin 2 (d1)
#define PS2_DATA_PORT PORTD
#define PS2_DATA_PIN PIND
#define PS2_DATA_DDR DDRD
#define PS2_DATA_BIT 1
#define PS2_MOUSE_ROTATE 270 // compensate for east-facing device orientation
#define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM
#define PS2_MOUSE_SCROLL_DIVISOR_V 3
#define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V
