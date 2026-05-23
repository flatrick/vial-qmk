/* Vial keymap for Planck rev4 — Svorak A1 (Swedish Dvorak) base layout.
 * Adapted from flatrick's existing planck_rev5_flatrick_2u keymap.
 *
 * 2u spacebar handling: matrix position (3,6) is set to KC_NO on the base
 * layer because some Planck PCBs bridge (3,5) and (3,6) electrically — a
 * single 2u keypress closes both, which would register KC_SPC twice if both
 * positions were mapped to it. LAYOUT_planck_1x2uC has the same effect by
 * simply omitting (3,6), but Vial requires the full matrix.
 *
 * Grid (2x1u) users without bridging can remap (3,6) in the Vial app.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
    _SVORAK,
    _LOWER,
    _RAISE,
    _SPARE  // empty 4th layer reserved for Vial use
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Svorak A1 base
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   [  |   '  |   ;  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   ,  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   .  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Bksp |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SVORAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_LBRC, KC_QUOT, KC_SCLN, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower (MO1) — symbols, F-keys, media
 * Note: AltGr+digits produce Swedish-layout-specific characters (@, $, etc).
 */
[_LOWER] = LAYOUT_planck_grid(
    RALT(KC_2), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_UNDS,
    RALT(KC_4), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_NO,   KC_NO,   KC_PIPE,    KC_PLUS,
    KC_NO,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NUBS, S(KC_NUBS), KC_RBRC,
    KC_NO,      KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_MPLY, _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_NO,      KC_NO
),

/* Raise (MO2) — numbers, navigation, more symbols */
[_RAISE] = LAYOUT_planck_grid(
    KC_NO, KC_1,      KC_2,    KC_3,       KC_4,       KC_5,      KC_6,      KC_7,    KC_8,          KC_9,    KC_0,          RALT(KC_E),
    KC_NO, KC_ASTR,   KC_LPRN, RALT(KC_7), RALT(KC_0), LCA(KC_8), LCA(KC_9), KC_AMPR, RALT(KC_MINS), KC_RBRC, RALT(KC_NUBS), RALT(KC_M),
    KC_NO, S(KC_EQL), KC_EQL,  KC_AT,      KC_NUHS,    KC_MINS,   KC_SLSH,   KC_PIPE, RALT(KC_RBRC), KC_RPRN, KC_GT,         KC_LT,
    KC_NO, KC_NO,     KC_NO,   KC_NO,      KC_INS,     KC_DEL,    _______,   _______, KC_HOME,       KC_PGUP, KC_PGDN,       KC_END
),

/* Spare layer — fully transparent. Program freely in Vial. */
[_SPARE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
