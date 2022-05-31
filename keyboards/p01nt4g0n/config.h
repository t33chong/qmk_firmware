// Copyright 2022 Tristan Chong (@t33chong)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x7EEC
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x0001
#define MANUFACTURER t33chong
#define PRODUCT      P01NT4G0N

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8
/* #define MATRIX_ROWS 1 */
/* #define MATRIX_COLS 1 */

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B2, F1, F6, F7, C7, C6, C1, B1 }
#define MATRIX_COL_PINS { B4, E0, E1, C0, C2, D7, B3, C5 }
/* #define MATRIX_ROW_PINS { B2, F1, F6, F7, C7, C6, C1, B1 } */
/* #define MATRIX_COL_PINS { B4, E0, E1, C0, C2, D7 } */
/* #define MATRIX_ROW_PINS { B2 } */
/* #define MATRIX_COL_PINS { B4 } */
/* #define UNUSED_PINS { D6, C3, F5, F4, F3, A7, A6, A5, A4, A3, A2, A1, A0, B0, E7, E6, F0, F2 } */

/* #define DIODE_DIRECTION COL2ROW */
#define DIODE_DIRECTION ROW2COL

// Audio
#ifdef AUDIO_ENABLE
#define AUDIO_PIN C4
#define STARTUP_SONG SONG(STARTUP_SOUND)
#endif //AUDIO_ENABLE

#ifdef DIP_SWITCH_ENABLE
#define DIP_SWITCH_MATRIX_GRID { {5,6}, {6,6}, {7,6} } // List of row and col pairs
#endif //DIP_SWITCH_ENABLE

// Encoder
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { D4, D4 }
#define ENCODERS_PAD_B { B5, D3 }
#define ENCODER_RESOLUTION 2
#endif // ENCODER_ENABLE

// Haptic Feedback
#ifdef HAPTIC_ENABLE
#define SOLENOID_PIN B7
#define SOLENOID_DEFAULT_DWELL 12
#define SOLENOID_MAX_DWELL 100
#define SOLENOID_MIN_DWELL 4
#endif // HAPTIC_ENABLE

/* // OLED Display */
/* #ifdef OLED_ENABLE */
/* #define OLED_DISPLAY_128X32 */
/* #endif // OLED_ENABLE */

#ifdef PS2_MOUSE_ENABLE

#ifdef PS2_USE_BUSYWAIT
#define PS2_CLOCK_PIN   D5
#define PS2_DATA_PIN    D2
#endif // PS2_USE_BUSYWAIT

#ifdef PS2_USE_INT
#define PS2_CLOCK_PIN   D5
#define PS2_DATA_PIN    D2

#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC21) |      \
              (0<<ISC20));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT2);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT2);        \
} while (0)
#define PS2_INT_VECT   INT2_vect
#endif // PS2_USE_INT

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

/* #define PS2_MOUSE_ROTATE 128 */
/* #define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE) */
/* #define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM */
/* #define PS2_MOUSE_SCROLL_DIVISOR_V 3 */
/* #define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V */
#endif // PS2_USE_USART

#endif // PS2_MOUSE_ENABLE

#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B6
#define RGBLED_NUM 48
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B6
#define DRIVER_LED_TOTAL 48
#endif // RGB_MATRIX_ENABLE

/* --- */

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
/* #define DEBOUNCE 5 */

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
/* #define NO_ACTION_MACRO */
/* #define NO_ACTION_FUNCTION */
