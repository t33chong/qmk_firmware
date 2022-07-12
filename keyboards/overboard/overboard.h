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
    K00, K10, K20, K30, K40, K50,      K60,                K80,      KA0, KB0, KC0, KD0, KE0, KF0, \
    K01, K11, K21, K31, K41, K51, K61, K62, K63,      K81, K82, K83, KA1, KB1, KC1, KD1, KE1, KF1, \
    K02, K12, K22, K32, K42, K52,      K64,   K90,  K91,   K84,      KA2, KB2, KC2, KD2, KE2, KF2, \
    K03, K13, K23, K33, K43, K53,           K92, K93, K94,           KA3, KB3, KC3, KD3, KE3, KF3  \
) { \
  { K00,   K10,   K20,   K30,   K40,   K50,   K60,   KC_NO, K80,   K90,   KA0,   KB0,   KC0,   KD0,   KE0,   KF0   }, \
  { K01,   K11,   K21,   K31,   K41,   K51,   K61,   KC_NO, K81,   K91,   KA1,   KB1,   KC1,   KD1,   KE1,   KF1   }, \
  { K02,   K12,   K22,   K32,   K42,   K52,   K62,   KC_NO, K82,   K92,   KA2,   KB2,   KC2,   KD2,   KE2,   KF2   }, \
  { K03,   K13,   K23,   K33,   K43,   K53,   K63,   KC_NO, K83,   K93,   KA3,   KB3,   KC3,   KD3,   KE3,   KF3   }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K64,   KC_NO, K84,   K94,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
