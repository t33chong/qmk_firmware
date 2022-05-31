#include QMK_KEYBOARD_H
#include <avr/io.h>
#include "pincontrol.h"

float imperial_march[][2] = SONG(IMPERIAL_MARCH);
float startup_sound[][2] = SONG(STARTUP_SOUND);

/* #define SOLENOID_PIN B5 */
/* #define SOLENOID_DEFAULT_DWELL 12 */
/* #define SOLENOID_MAX_DWELL 100 */
/* #define SOLENOID_MIN_DWELL 4 */

/* // Solenoid */
/* bool solenoid_enabled = true; */
/* bool solenoid_on = false; */
/* bool solenoid_buzz = true; */
/* bool solenoid_buzzing = false; */
/* volatile uint32_t solenoid_start = 0; */
/* uint8_t solenoid_dwell = SOLENOID_DEFAULT_DWELL; */

/* void solenoid_buzz_on(void) { */
/*   solenoid_buzz = true; */
/* } */

/* void solenoid_buzz_off(void) { */
/*   solenoid_buzz = false; */
/* } */

/* void solenoid_dwell_minus(void) { */
/*   if (solenoid_dwell > 0) solenoid_dwell--; */
/* } */

/* void solenoid_dwell_plus(void) { */
/*   if (solenoid_dwell < SOLENOID_MAX_DWELL) solenoid_dwell++; */
/* } */

/* void solenoid_toggle(void) { */
/*   solenoid_enabled = !solenoid_enabled; */
/* } */

/* void solenoid_stop(void) { */
/*   digitalWrite(SOLENOID_PIN, PinLevelLow); */
/*   solenoid_on = false; */
/*   solenoid_buzzing = false; */
/* } */

/* void solenoid_fire(void) { */
/*   if (!solenoid_enabled) return; */

/*   if (!solenoid_buzz && solenoid_on) return; */
/*   if (solenoid_buzz && solenoid_buzzing) return; */

/*   solenoid_on = true; */
/*   solenoid_buzzing = true; */
/*   solenoid_start = timer_read32(); */
/*   digitalWrite(SOLENOID_PIN, PinLevelHigh); */
/* } */

/* void solenoid_check(void) { */
/*   uint16_t elapsed = 0; */

/*   if (!solenoid_on) return; */

/*   elapsed = timer_elapsed32(solenoid_start); */

/*   //Check if it's time to finish this solenoid click cycle */
/*   if (elapsed > solenoid_dwell) { */
/*     solenoid_stop(); */
/*     return; */
/*   } */

/*   //Check whether to buzz the solenoid on and off */
/*   if (solenoid_buzz) { */
/*     if (elapsed / SOLENOID_MIN_DWELL % 2 == 0){ */
/*       if (!solenoid_buzzing) { */
/*         solenoid_buzzing = true; */
/*         digitalWrite(SOLENOID_PIN, PinLevelHigh); */
/*       } */
/*     } */
/*     else { */
/*       if (solenoid_buzzing) { */
/*         solenoid_buzzing = false; */
/*         digitalWrite(SOLENOID_PIN, PinLevelLow); */
/*       } */
/*     } */
/*   } */

/* } */

/* void solenoid_setup(void) { */
/*   pinMode(SOLENOID_PIN, PinDirectionOutput); */
/*   timer_init(); */
/* } */

/* void matrix_init_user(void) { */
/*   solenoid_setup(); */
/* } */

/* void matrix_scan_user(void) { */
/*   solenoid_check(); */
/* } */

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* LAYOUT_ortho_1x1(KC_BTN3) */
  LAYOUT_ortho_1x1(KC_A)
  /* LAYOUT_ortho_1x1(BL_TOGG) */
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code_delay(KC_VOLU, 10);
    } else {
      tap_code_delay(KC_VOLD, 10);
    }
  } else {
    if (clockwise) {
      tap_code_delay(KC_BRMU, 10);
    } else {
      tap_code_delay(KC_BRMD, 10);
    }
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

#ifdef POINTING_DEVICE_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  mouse_report.h = mouse_report.x;
  mouse_report.v = -mouse_report.y;
  mouse_report.x = mouse_report.y = 0;
  return mouse_report;
}
bool is_blue = true;
uint8_t pointing_device_handle_buttons(uint8_t buttons, bool pressed, pointing_device_buttons_t button) {
  if (pressed) {
    if (is_blue) {
      pimoroni_trackball_set_rgbw(255, 0, 0, 0);
    } else {
      pimoroni_trackball_set_rgbw(0, 0, 255, 0);
    }
    is_blue = !is_blue;
  }
  return buttons;
}
void keyboard_post_init_user(void) {
  pimoroni_trackball_set_rgbw(0, 0, 255, 0);
  rgblight_setrgb(RGB_WHITE);
}
#endif // POINTING_DEVICE_ENABLE

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (record->event.pressed) { */
  /*   solenoid_fire(); */
  /* } */
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
