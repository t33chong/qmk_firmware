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

// Interrupt
#ifdef PS2_USE_INT
// clock on pin 3 (d0, int0)
/* #define PS2_CLOCK_PORT PORTD */
/* #define PS2_CLOCK_PIN PIND */
#define PS2_CLOCK_PIN D0
/* #define PS2_CLOCK_DDR DDRD */
/* #define PS2_CLOCK_BIT 0 */

// data on pin 2 (d1)
/* #define PS2_DATA_PORT PORTD */
/* #define PS2_DATA_PIN PIND */
#define PS2_DATA_PIN D1
/* #define PS2_DATA_DDR DDRD */
/* #define PS2_DATA_BIT 1 */

#define PS2_INT_INIT() do { EICRA |= ((1<<ISC01) | (0<<ISC00)); } while (0)
#define PS2_INT_ON() do { EIMSK |= (1<<INT0); } while (0)
#define PS2_INT_OFF() do { EIMSK &= ~(1<<INT0); } while (0)
#define PS2_INT_VECT INT0_vect
#endif // PS2_USE_INT

// USART
#ifdef PS2_USE_USART
#define PS2_CLOCK_PIN   D5
#define PS2_DATA_PIN    D2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
#define PS2_USART_INIT() do {   \
      PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT);   \
      PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);     \
      UCSR1C = ((1 << UMSEL10) |  \
                (3 << UPM10)   |  \
                (0 << USBS1)   |  \
                (3 << UCSZ10)  |  \
                (0 << UCPOL1));   \
      UCSR1A = 0;                 \
      UBRR1H = 0;                 \
      UBRR1L = 0;                 \
  } while (0)
#define PS2_USART_RX_INT_ON() do {  \
      UCSR1B = ((1 << RXCIE1) |       \
                (1 << RXEN1));        \
  } while (0)
#define PS2_USART_RX_POLL_ON() do { \
      UCSR1B = (1 << RXEN1);          \
  } while (0)
#define PS2_USART_OFF() do {    \
      UCSR1C = 0;                 \
      UCSR1B &= ~((1 << RXEN1) |  \
                  (1 << TXEN1));  \
  } while (0)
#define PS2_USART_RX_READY      (UCSR1A & (1<<RXC1))
#define PS2_USART_RX_DATA       UDR1
#define PS2_USART_ERROR         (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
#define PS2_USART_RX_VECT       USART1_RX_vect
#endif // PS2_USE_USART

#define PS2_MOUSE_ROTATE 180 // compensate for east-facing device orientation
#define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM
#define PS2_MOUSE_SCROLL_DIVISOR_V 3
#define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V
