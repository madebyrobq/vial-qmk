// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// make madebyrobq/ortho4x10tkl:vial

#include QMK_KEYBOARD_H

enum layers {
    DEFAULT_LAYER,
    RAISE_LAYER,
};

#define SPC_RSE LT(RAISE_LAYER, KC_SPC)

#define KCZ_SFT LSFT_T(KC_Z)
#define KC7_SFT LSFT_T(KC_7)

#define KCM_SFT RSFT_T(KC_M)

#define KC0_CMD LCMD_T(KC_0)
#define DOT_CMD LCMD_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐┌───────┬───────┬───────┐
     * │   Q (TAB) W   │   E   │   R   │   T   │   Y   │   U   ││   I   │   O (DEL) P   │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┘├───────┼───────┼───────┤
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┐│   K   │   L (ENT) ;   │
     * │   A (ESC) S   │   D   │   F   │   G   │   H   │   J   │└───────┴───────┴───────┘
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┤┌───────┬───────┬───────┐
     * │  Z(⇧) │   X   │   C   │   V   │   B   │   N   │  M(⇧) ││  PGDN │   Up  │  PGUP │
     * ├───────┼───────┼───────┴───────┴───────┼───────┼───────┤├───────┼───────┼───────┤
     * │   ⌥   │   ⌘   │         Space         │SPC/RSE│SPC/RSE││  Left │  Down │ Right │
     * └───────┴───────┴───────────────────────┴───────┴───────┘└───────┴───────┴───────┘
     */
    [DEFAULT_LAYER] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KCZ_SFT, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KCM_SFT, KC_PGDN, KC_UP,   KC_PGUP,
        KC_LALT, KC_LCMD, KC_SPC,  KC_SPC,  KC_SPC,  SPC_RSE, SPC_RSE, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [RAISE_LAYER] = LAYOUT_ortho_4x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_MINS, KC_PPLS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
        KC_4,    KC_5,    KC_6,    KC_0,    KC_PSLS, KC_PAST, KC_EQL,  KC_LPRN, KC_RPRN, _______,
        KC7_SFT, KC_8,    KC_9,    KC_DOT,  KC_PIPE, KC_AMPR, KC_QUES, XXXXXXX, _______, XXXXXXX,
        KC_LALT, KC0_CMD, _______, _______, _______, KC_COMM, KC_DOT,  KC_LT,   _______, KC_GT
    ),
};
