#include QMK_KEYBOARD_H
/* #include "colors.h" */

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    NEW_SAFE_RANGE
};

enum my_keycodes {
    MY_UNDS = NEW_SAFE_RANGE, //Use instead of KC_UNDS to avoid shift applying to next keypress
    /* MY_ALBS, */
};

#define MY_CTES LCTL_T(KC_ESC)
#define MY_SFBS LSFT_T(KC_BSPC)
#define MY_HYSP HYPR_T(KC_SPC)
#define MY_SFCA RSFT_T(KC_CAPS)
#define MY_ESLT LT(4, KC_ESC)
/* #define MY_SFBS LSFT_T(LALT(KC_BSPC)) */
/* #define MY_ALBS LALT(KC_BSPC) */
/* #define MY_ALBS (QK_LALT | KC_BSPC) */
/* #define MY_SFBS LSFT_T(MY_ALBS) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TG(3),   \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
        MY_CTES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        MY_SFBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_SFCA,          KC_UP,   KC_PGDN, \
        /* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_SFCA,          KC_UP,   KC_PGDN, \ */
        /* MO(2),   KC_LALT, KC_LGUI,                            MY_HYSP,                            MY_UNDS, MO(15),  KC_LEFT, KC_DOWN, KC_RGHT  \ */
        MO(2),   KC_LALT, KC_LGUI,                            MY_HYSP,                            MY_UNDS, MO(15),  KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_65_ansi_blocker( // Mouse keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,          _______, _______, \
        _______, KC_WH_L, _______, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [2] = LAYOUT_65_ansi_blocker( // Numpad
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,  _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______,          _______, _______, \
        KC_NLCK, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAST, _______,          _______, _______, \
        _______, _______, _______,                            KC_KP_0,                            _______, _______, _______, _______, _______  \
    ),
    [3] = LAYOUT_65_ansi_blocker( // Gaming
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        MY_ESLT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        KC_LCTL, KC_EQL,  KC_LALT,                            _______,                            _______, KC_LGUI, _______, _______, _______  \
    ),
    [4] = LAYOUT_65_ansi_blocker( // Gaming arrows/mirror image
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_P,    KC_UP,   KC_I,    KC_U,    KC_Y,    _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_J,    KC_H,    _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_ENT,                             _______, _______, _______, _______, _______  \
    ),
    [15] = LAYOUT_65_ansi_blocker( // Function; ALT swaps ALT with CMD, CMD resets it
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, MD_BOOT, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        TG(1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    /*
    [X] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CTES:
        case MY_HYSP:
        case MY_ESLT:
            return true;
        default:
            return false;
    }
}

// Indicate layer with RGB matrix effect
// https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1: // Mouse keys
        rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
        break;
    case 2: // Numpad
    case 3: // Gaming
    case 4: // Gaming arrows/mirror image
    case 15: // Function
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        break;
    default:
        rgb_matrix_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
        break;
    }
  return state;
}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        case MY_UNDS:
            if (record->event.pressed) {
                SEND_STRING("_");
            }
            return false;
        /* case MY_ALBS: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_BSPC) SS_UP(X_LALT)); */
        /*         /1* SS_DOWN(KC_LALT); *1/ */
        /*         /1* SS_TAP(KC_BSPC); *1/ */
        /*         /1* SS_UP(KC_LALT); *1/ */
        /*     } */
        /*     /1* if (record->event.pressed) { *1/ */
        /*     /1*     /2* register_code16(LALT(KC_BSPC)); *2/ *1/ */
        /*     /1*     register_code16((QK_LALT | KC_BSPC)); *1/ */
        /*     /1* } else { *1/ */
        /*     /1*     /2* unregister_code16(LALT(KC_BSPC)); *2/ *1/ */
        /*     /1*     unregister_code16((QK_LALT | KC_BSPC)); *1/ */
        /*     /1* } *1/ */
        /*     return false; */
        default:
            return true; //Process all other keycodes normally
    }
}
