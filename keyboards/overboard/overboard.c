// Copyright 2022 Tristan Chong (@t33chong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "overboard.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// Key Matrix to LED Index
  { 5,      4,      3,      2,      1,      0,      NO_LED, NO_LED, NO_LED, NO_LED, 47,     46,     45,     44,     43,     42     },
  { 6,      7,      8,      9,      10,     11,     NO_LED, NO_LED, NO_LED, NO_LED, 36,     37,     38,     39,     40,     41     },
  { 17,     16,     15,     14,     13,     12,     NO_LED, NO_LED, NO_LED, NO_LED, 35,     34,     33,     32,     31,     30     },
  { 18,     19,     20,     21,     22,     23,     NO_LED, NO_LED, NO_LED, NO_LED, 24,     25,     26,     27,     28,     29     },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
// LED Index to Physical Position
  {  88, 14 }, {  73, 13 }, {  58, 11 }, {  43,  9 }, {  29,  8 }, {  14,  6 },
  {  12, 19 }, {  27, 21 }, {  42, 22 }, {  56, 24 }, {  71, 25 }, {  86, 27 },
  {  84, 40 }, {  69, 38 }, {  55, 37 }, {  40, 35 }, {  25, 33 }, {  10, 32 },
  {   8, 45 }, {  23, 46 }, {  38, 48 }, {  53, 49 }, {  68, 51 }, {  83, 53 },
  { 141, 53 }, { 156, 51 }, { 171, 49 }, { 186, 48 }, { 201, 46 }, { 216, 45 },
  { 214, 32 }, { 199, 33 }, { 184, 35 }, { 169, 37 }, { 155, 38 }, { 140, 40 },
  { 138, 27 }, { 153, 25 }, { 168, 24 }, { 182, 22 }, { 197, 21 }, { 212, 19 },
  { 210,  6 }, { 195,  8 }, { 181,  9 }, { 166, 11 }, { 151, 13 }, { 136, 14 }
}, {
// LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif // RGB_MATRIX_ENABLE
