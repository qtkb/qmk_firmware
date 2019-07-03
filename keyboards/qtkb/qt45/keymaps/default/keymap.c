/* Copyright 2019 Benjamin Davis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define CTL_ESC LCTL_T(KC_ESC)
#define MO_NUM MO(_NUM)
#define MO_SYM MO(_SYM)
#define MO_CFG MO(_CFG)

// Layers
enum
{
  _QWE = 0,
  _NUM = 1,
  _SYM = 2,
  _CFG = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWE] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO_SYM,   \
                      KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO_NUM),
  [_NUM] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  \
    KC_LCTL, KC_5,    KC_6,    KC_7,    KC_8,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, \
    _______,          KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, MO_CFG, \
                      _______, _______,                            _______,                   _______, _______),
  [_SYM] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_DEL,  \
    KC_LCTL, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT,          _______, \
    _______,          KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_DOWN, _______, _______, \
                      _______, _______,                            _______,                   _______, MO_CFG),
  [_CFG] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                      XXXXXXX, XXXXXXX,                            XXXXXXX,                   XXXXXXX, XXXXXXX)
};
