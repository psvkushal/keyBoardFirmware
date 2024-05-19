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

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC)
};

//KC_TRNS == _______ transparent key
//KC_NO   == XXXXXXX no key
//TODO
//make osm keys to come in 8 letters
//eg: OSM(MOD_RGUI) == OSM_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, XXXXXXX,
  OSM(MOD_LCTL),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                            KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
  XXXXXXX,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, XXXXXXX,        XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_BSPC,
                 XXXXXXX,XXXXXXX,KC_LGUI, TL_LOWR,  KC_ENT,         KC_SPC,TL_UPPR,KC_LSFT,XXXXXXX,XXXXXXX
),
[_NUM] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
  _______, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _______,                    KC_PPLS ,  KC_ENT, KC_TAB, KC_LBRC , KC_RBRC,  _______,
  _______,_______,_______,_______,_______,_______, _______,       _______, KC_MINS, KC_UNDS, KC_PIPE, KC_EQL, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, KC_LALT, _______, _______
),
    // The intention of KC_RGUI is to act as mod for moving between workspaces
[_SYMBOL] = LAYOUT(
XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                          XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
 _______,_______, _______, _______, _______, _______,                                _______, KC_TILD, KC_DQT, KC_LBRC, KC_RBRC, _______,
 _______,KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                   KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
 _______, _______, _______, _______, _______, _______,  _______,              _______, _______, KC_GRV, KC_QUOT, KC_LCBR, KC_RCBR, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[_UTIL] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
      _______, EE_CLR, _______, _______, _______, _______,                                             KC_LT, KC_VOLD, KC_VOLU, KC_MUTE, KC_MNXT, _______,
      _______, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _______,                     KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_MPLY,  _______,
      _______, _______, _______, _______, _______, _______,  _______,                           _______,KC_GT, KC_BRID, KC_BRIU, KC_MPRV, KC_MPRV, _______,
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
            oled_write_ln_P(PSTR("Syms"), false);
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
