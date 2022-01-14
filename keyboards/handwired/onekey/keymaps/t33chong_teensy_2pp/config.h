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

/* #define PRODUCT Onekey Teensy 2.0++ */

#define MATRIX_COL_PINS { F4 }
#define MATRIX_ROW_PINS { F5 }
#define UNUSED_PINS

#define BACKLIGHT_PIN B6

#define RGB_DI_PIN F6
#define RGB_CI_PIN B1

#define ADC_PIN F6

// Trackpoint - USART
#ifdef PS2_MOUSE_ENABLE
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

#define PS2_MOUSE_ROTATE 180
#define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM
#define PS2_MOUSE_SCROLL_DIVISOR_V 3
#define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V
#endif // PS2_MOUSE_ENABLE

// Encoder
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { F6 }
#define ENCODER_RESOLUTION 2
#endif // ENCODER_ENABLE

// Audio
#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
/* #define AUDIO_PIN_ALT B5 */
#define STARTUP_SONG SONG(STARTUP_SOUND)
#endif //AUDIO_ENABLE

#ifdef BLUETOOTH_ENABLE
#define ADAFRUIT_BLE_RST_PIN D4
#define ADAFRUIT_BLE_CS_PIN  B4
#define ADAFRUIT_BLE_IRQ_PIN E6
#endif // BLUETOOTH_ENABLE

#ifdef HAPTIC_ENABLE
#define SOLENOID_PIN B5
/* #define HAPTIC_ENABLE_PIN F3 */
/* #define SOLENOID_DEFAULT_DWELL 12 */ 
/* #define SOLENOID_MAX_DWELL 100 */
/* #define SOLENOID_MIN_DWELL 4 */
#endif // HAPTIC_ENABLE
