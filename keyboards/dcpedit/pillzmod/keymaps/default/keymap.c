// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMUX_NEXT = SAFE_RANGE,
    TMUX_SESS,
    CMD_CTL_SPC,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_NEXT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_B);
                unregister_code(KC_LCTL);
                wait_ms(5);
                tap_code(KC_N);
            }
            return false;
        case TMUX_SESS:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_B);
                unregister_code(KC_LCTL);
                wait_ms(5);
                tap_code16(S(KC_0));
            }
            return false;
        case CMD_CTL_SPC:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                tap_code(KC_SPC);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,   KC_SCRL,  KC_PAUS,  KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_KB_MUTE, KC_VOLD, KC_VOLU, QK_BOOT,  QK_BOOTLOADER,
        KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                  KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                         KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                TO(1),    TO(2),                                        TMUX_SESS, TMUX_NEXT,
                                                          KC_SYSTEM_SLEEP,                              CMD_CTL_SPC,
                                      KC_RGUI,  KC_BSPC,  QK_HAPTIC_TOGGLE,                             KC_PGDN,  KC_ENTER, KC_SPC,
        KC_A,     KC_B,     KC_C
    ),
    [1] = LAYOUT(
        TO(0),    QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       AU_TOGG,  HF_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_NUM,   KC_PEQL,  KC_PSLS,  KC_PAST,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                                       KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        KC_LCTL,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_9,     KC_P6,    KC_PPLS,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  _______,
                  _______,  _______,  _______,  _______,                                                         KC_UP,    KC_DOWN,  KC_PDOT,  KC_PENT,
                                                _______,  TO(2),                                        _______,  _______,
                                                          _______,                                      _______,
                                      _______,  _______,  _______,                                      _______,  _______,  KC_P0,
        _______,  _______,  _______
    ),
    [2] = LAYOUT(
        TO(0),    KC_SCRL,  KC_PAUS,  KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_KB_MUTE, KC_VOLD, KC_VOLU, QK_BOOT,  QK_BOOTLOADER,
        KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_BTN1,  KC_G,                                        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                  KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                         KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                TO(1),    _______,                                      KC_RGUI,  KC_RCTL,
                                                          KC_HOME,                                      KC_PGUP,
                                      KC_RGUI,  KC_BSPC,  KC_END,                                       KC_PGDN,  KC_ENTER, KC_SPC,
        KC_A,     KC_B,     KC_C
    ),
};
