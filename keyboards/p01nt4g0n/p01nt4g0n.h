// Copyright 2022 Tristan Chong (@t33chong)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
    K60,                                                                       \
    K00, K07, K10, K17, K20, K27,      K61,      K30, K37, K40, K47, K50, K57, \
    K01, K06, K11, K16, K21, K26,                K31, K36, K41, K46, K51, K56, \
                                       K70,                                    \
    K02, K05, K12, K15, K22, K25, K71, K77, K76, K32, K35, K42, K45, K52, K55, \
                                       K72,                                    \
    K03, K04, K13, K14, K23, K24, K73, K75, K74, K33, K34, K43, K44, K53, K54  \
) { \
  { K00, K10, K20, K30, K40, K50, K60,   K70 }, \
  { K01, K11, K21, K31, K41, K51, K61,   K71 }, \
  { K02, K12, K22, K32, K42, K52, KC_NO, K72 }, \
  { K03, K13, K23, K33, K43, K53, KC_NO, K73 }, \
  { K04, K14, K24, K34, K44, K54, KC_NO, K74 }, \
  { K05, K15, K25, K35, K45, K55, KC_NO, K75 }, \
  { K06, K16, K26, K36, K46, K56, KC_NO, K76 }, \
  { K07, K17, K27, K37, K47, K57, KC_NO, K77 }  \
}

/* #define LAYOUT_planck_grid( \ */
/*     K00, K07, K10, K17, K20, K27, K30, K37, K40, K47, K50, K57, \ */
/*     K01, K06, K11, K16, K21, K26, K31, K36, K41, K46, K51, K56, \ */
/*     K02, K05, K12, K15, K22, K25, K32, K35, K42, K45, K52, K55, \ */
/*     K03, K04, K13, K14, K23, K24, K33, K34, K43, K44, K53, K54  \ */
/* ) { \ */
/*   { K00, K10, K20, K30, K40, K50 }, \ */
/*   { K01, K11, K21, K31, K41, K51 }, \ */
/*   { K02, K12, K22, K32, K42, K52 }, \ */
/*   { K03, K13, K23, K33, K43, K53 }, \ */
/*   { K04, K14, K24, K34, K44, K54 }, \ */
/*   { K05, K15, K25, K35, K45, K55 }, \ */
/*   { K06, K16, K26, K36, K46, K56 }, \ */
/*   { K07, K17, K27, K37, K47, K57 }  \ */
/* } */

/* #define LAYOUT_1x1(K00) { { K00 } } */
