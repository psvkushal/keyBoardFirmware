/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_layers {
    BASE_QWERTY,
    NUMBER,
    UTILS,
    SYMBOL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB  ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ESC ,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM(MOD_LCTL),   OSL(NUMBER),  KC_SPC,     KC_ENT,   OSL(UTILS), OSM(MOD_RCMD)
                                      //`--------------------------'  `--------------------------'

  ),

    [NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD,  KC_EQL, KC_PPLS, KC_LCBR, KC_LPRN, KC_LBRC,                      KC_LT, OSM(MOD_RCMD),   OSM(MOD_RALT),OSM(MOD_RCTL), OSM(MOD_RSFT), QK_LOCK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_PMNS, KC_RCBR, KC_RPRN, KC_RBRC,                      KC_GT, KC_CAPS, _______, _______, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [UTILS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, _______, _______, _______, _______, _______,                      KC_PGUP, KC_VOLU, KC_VOLD, KC_MUTE, KC_MNXT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_LOCK, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LCMD), _______,                      KC_LEFT,  KC_UP, KC_DOWN, KC_UP, KC_MPLY,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_PGUP, KC_BRIU, KC_BRID, KC_MPRV, KC_MPRV, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX , _______, _______, _______, _______, _______,                      _______, _______, _______, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX , KC_EXLM, KC_AT, KC_NUHS, KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX , _______, _______, _______, _______, _______,                      _______, _______, _______, KC_LCBR, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
