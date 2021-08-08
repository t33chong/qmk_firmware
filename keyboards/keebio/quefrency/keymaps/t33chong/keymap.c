#include "t33chong.h"

#define LAYOUT_t33chong( \
  LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, \
  LB3, LB4, LB5, LB6, LB7, LB8,           RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, \
  LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6,      RC8, \
  LD3,      LD5, LD6, LD7, LD8, LD9,      RD1, RD2, RD3, RD4, RD5,      RD7, RD8, \
  LE3, LE4, LE5, LE6,      LE8,                RE2, RE3, RE4, RE5,      RE7, RE8 \
  ) \
  { \
    { KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 }, \
    { KC_NO, KC_NO, LB3, LB4, LB5, LB6, LB7, LB8, KC_NO }, \
    { KC_NO, KC_NO, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { KC_NO, KC_NO, LD3, KC_NO, LD5, LD6, LD7, LD8, LD9 }, \
    { KC_NO, KC_NO, LE3, LE4, LE5, LE6, KC_NO, LE8, KC_NO }, \
    { RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, KC_NO }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, KC_NO }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO, RC8, KC_NO }, \
    { RD1, RD2, RD3, RD4, RD5, KC_NO, RD7, RD8, KC_NO }, \
    { KC_NO, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, KC_NO } \
  }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT_LAYER] = _layout(_DEFAULT_MAP),
  [_NUMERALS_LAYER] = _layout(_NUMERALS_MAP),
  [_MOUSEKEYS_LAYER] = _layout(_MOUSEKEYS_MAP),
  [_FUNCTION_LAYER] = _layout(_FUNCTION_MAP),
  [_QUANTUM_LAYER] = _layout(_QUANTUM_MAP),
};
