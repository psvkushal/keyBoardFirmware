// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _NUM,
    _UTIL,
    _SYMBOL
};

//KC_TRNS == _______ transparent key
//KC_NO   == XXXXXXX no key
//TODO
//make osm keys to come in 8 letters
//eg: OSM(MOD_RGUI) == OSM_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_GRV,
  OSM(MOD_LCTL),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                            KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
  KC_TAB,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, XXXXXXX,        XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_BSPC,
                 XXXXXXX,XXXXXXX, KC_LSFT, TL_LOWR,  KC_SPC,         KC_ENT,TL_UPPR,KC_RGUI,XXXXXXX,XXXXXXX
),
[_NUM] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_TILD,
  _______, KC_EQL,KC_PPLS,KC_LCBR,KC_LPRN,KC_LBRC,                       KC_LT, OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), OSM(MOD_RSFT), QK_LOCK,
  _______,KC_PIPE,KC_MINS,KC_RCBR,KC_RPRN,KC_RBRC, _______,       _______, KC_GT, KC_CAPS, _______, _______, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[_UTIL] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
      _______, EE_CLR, _______, _______, _______, _______,                                             KC_PGUP, KC_VOLD, KC_VOLU, KC_MUTE, KC_MNXT, _______,
      _______, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), _______,                     KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_MPLY,  _______,
      _______, _______, _______, _______, _______, _______,  XXXXXXX,                           XXXXXXX,KC_PGUP, KC_BRID, KC_BRIU, KC_MPRV, KC_MPRV, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
  [_SYMBOL] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                          XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
   KC_ESC,_______, _______, _______, _______, _______,                                _______, _______, _______, KC_LBRC, KC_RBRC, _______,
   KC_TAB,KC_EXLM, KC_AT, KC_NUHS, KC_DLR, KC_PERC,                                   KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
   KC_LSFT, _______, _______, _______, _______, _______,  XXXXXXX,              XXXXXXX, _______, _______, _______, KC_LCBR, KC_RCBR, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  )
};
