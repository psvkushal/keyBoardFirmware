// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdint.h>
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _NUM,
    _UTIL,
    _SYMBOL
};

enum custom_keycodes {
    OSM_CLR
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM_CLR:
            if (record->event.pressed) {
                // Do something when pressed
                clear_oneshot_mods();
            }
            return false; // Skip all further processing of this key
        default:
            return true;
    }
}

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
    COMBO(ui_combo, KC_TAB),
    COMBO(mcomma_combo, KC_ENT),
};


//All tap dance functions would go here. Only showing this one.
//KC_TRNS == _______ transparent key
//KC_NO   == XXXXXXX no key
//TODO
//make osm keys to come in 8 letters
//eg: OSM(MOD_RGUI) == OSM_RGUI

//Tap Dance Declarations
enum {
    TD_WS0 = 0,
    TD_WS1 = 1,
    TD_WS2 = 2,
    TD_WS3 = 3,
    TD_WS4 = 4,
    TD_WS5 = 5,
    TD_WS6 = 6,
    TD_WS7 = 7,
    TD_WS8 = 8,
    TD_WS9 = 9,
    TD_SCR_UP = 10,
    TD_SCR_DN = 11

};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for sending alt + kc_n , tap twice to send shift + alt + kc_n
  [TD_WS0]  = ACTION_TAP_DANCE_DOUBLE(A(KC_0), LSA(KC_0)),
  [TD_WS1]  = ACTION_TAP_DANCE_DOUBLE(A(KC_1), LSA(KC_1)),
  [TD_WS2]  = ACTION_TAP_DANCE_DOUBLE(A(KC_2), LSA(KC_2)),
  [TD_WS3]  = ACTION_TAP_DANCE_DOUBLE(A(KC_3), LSA(KC_3)),
  [TD_WS4]  = ACTION_TAP_DANCE_DOUBLE(A(KC_4), LSA(KC_4)),
  [TD_WS5]  = ACTION_TAP_DANCE_DOUBLE(A(KC_5), LSA(KC_5)),
  [TD_WS6]  = ACTION_TAP_DANCE_DOUBLE(A(KC_6), LSA(KC_6)),
  [TD_WS7]  = ACTION_TAP_DANCE_DOUBLE(A(KC_7), LSA(KC_7)),
  [TD_WS8]  = ACTION_TAP_DANCE_DOUBLE(A(KC_8), LSA(KC_8)),
  [TD_WS9]  = ACTION_TAP_DANCE_DOUBLE(A(KC_9), LSA(KC_9)),
  [TD_SCR_UP]  = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
  [TD_SCR_DN]  = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END)

// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  XXXXXXX,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_GRV,
  OSM(MOD_LALT),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                            KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
  XXXXXXX,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, XXXXXXX,        XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_BSPC,
                 XXXXXXX,XXXXXXX,KC_LGUI, TL_LOWR,  KC_LCTL,         KC_SPC,TL_UPPR,KC_LSFT,XXXXXXX,XXXXXXX
),
[_NUM] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  _______,_______,_______,    KC_LBRC,KC_LPRN,  KC_TILD,                     KC_PPLS ,KC_RPRN, KC_RBRC ,  KC_EQL,KC_PIPE, _______,
  _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,KC_8,    KC_9,   KC_0,_______,
  _______, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM_CLR,_______,                  _______, KC_MINS, KC_UNDS, _______, _______, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

    // The intention of KC_RGUI is to act as mod for moving between workspaces
[_SYMBOL] = LAYOUT(
XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                          XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
 _______,_______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
 _______,TD(TD_WS1), TD(TD_WS2), TD(TD_WS3), TD(TD_WS4), TD(TD_WS5),                                   TD(TD_WS6), TD(TD_WS8), TD(TD_WS9), TD(TD_WS0),  TD(TD_WS7),_______,
 _______, _______, _______, _______, _______, _______,  _______,              _______, _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[_UTIL] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                            KC_F4, KC_PPLS, KC_UP , KC_BRIU,  KC_VOLU, KC_F8,
      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_EQL,                                            KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MUTE,  KC_F6,
      _______, KC_F1,  KC_F5, _______, _______, KC_F12,  _______,                           _______,KC_PSCR, KC_MINS,KC_F2 ,  KC_BRID,  KC_VOLD,_______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}


void print_msg(void) {
    oled_write_ln_P(PSTR("keep goingThe  work workson   you\n"), false);
}

void print_layer_status(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Nums"), false);
            break;
        case 2:
            oled_write_P(PSTR("Prod"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("WS"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("Utils"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_layer_status();
    } else {
        print_msg();
    }
    return false;
}

#endif
