#include QMK_KEYBOARD_H
//#include "solenoid.h"

float imperial_march[][2] = SONG(IMPERIAL_MARCH);
float startup_sound[][2] = SONG(STARTUP_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_ortho_1x1(KC_A)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    /* tap_code_delay(KC_VOLU, 10); */
    tap_code16(HPT_BUZ);
  } else {
    /* tap_code_delay(KC_VOLD, 10); */
    tap_code16(HPT_OFF);
  }
  return false;
};
#endif // ENCODER_ENABLE

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Hello world"), false);
    return false;
}
#endif // OLED_ENABLE

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/* #ifdef HAPTIC_ENABLE */
/*   solenoid_fire(); */
/* #endif */
  switch (keycode) {
    case KC_A:
      if (record->event.pressed) {
        /* PLAY_SONG(imperial_march); */
        PLAY_SONG(startup_sound);
      }
      return true;

    default:
      /* if (record->event.pressed) { */
      /* } else { */
      /* } */
      return true; // Process all other keycodes normally
  }
}
