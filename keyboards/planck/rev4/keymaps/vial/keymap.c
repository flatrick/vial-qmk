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
 *
 * =========================================================================
 * LAYER MAPS  —  characters shown are what the OS produces (SE layout)
 * =========================================================================
 *
 * Layer 0 — SVORAK (base)
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * | Esc  |  å   |  ä   |  ö   |  p   |  y   |  f   |  g   |  c   |  r   |  l   |  ,   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  a   |  o   |  e   |  u   |  i   |  d   |  h   |  t   |  n   |  s   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |  .   |  q   |  j   |  k   |  x   |  b   |  m   |  w   |  v   |  z   | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Bksp |[Lwr] |    Space    |[Rse] | Left | Down |  Up  | Rght |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 *
 * Layer 1 — LOWER: symbols, F-keys, media
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * |  @   |  !   |  "   |  #   |  ¤   |  %   |  &   |  /   |  (   |  )   |  =   |  ?  *|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  $   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |  *  *|  `  *|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |  <   |  >   |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ |[Lwr] | Play |      | Prev | Next | Stop |      |      |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 * Keys marked * differ from US intent due to SE layout: KC_UNDS→?, KC_PIPE→*, KC_PLUS→`
 *
 * Layer 2 — RAISE: numbers, brackets, navigation
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  €   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  (   |  )   |  {   |  }   |  [   |  ]   |  /   |  \   |  ^   |  |   |  µ   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `  *|  ´   |  '   |  "   |  +   |  -   |  *  *|  ~   |  =   |  :   |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Ins  | Del  |      |[Rse] | Home | PgUp | PgDn | End  |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 * Keys marked * differ from US intent: S(KC_EQL)→` not +, KC_PIPE→* not |
 * KC_GT/KC_LT send S(.)=: and S(,)=; on SE — used here for : and ;
 *
 * Layer 3 — SPARE (fully transparent; configure freely in Vial)
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 * =========================================================================
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

/* Layer 0 — SVORAK base (SE OS output)
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * | Esc  |  å   |  ä   |  ö   |  p   |  y   |  f   |  g   |  c   |  r   |  l   |  ,   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  a   |  o   |  e   |  u   |  i   |  d   |  h   |  t   |  n   |  s   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |  .   |  q   |  j   |  k   |  x   |  b   |  m   |  w   |  v   |  z   | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Bksp |[Lwr] |    Space    |[Rse] | Left | Down |  Up  | Rght |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 */
[_SVORAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_LBRC, KC_QUOT, KC_SCLN, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, LOWER,   KC_SPC,  KC_NO,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Layer 1 — LOWER: symbols, F-keys, media (SE OS output)
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * |  @   |  !   |  "   |  #   |  ¤   |  %   |  &   |  /   |  (   |  )   |  =   |  ?  †|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  $   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |  *  †|  `  †|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |  <   |  >   |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ |[Lwr] | Play |      | Prev | Next | Stop |      |      |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 * † KC_UNDS→? KC_PIPE→* KC_PLUS→` (SE mismatch; fix with RALT(KC_MINS)=\, S(KC_SLSH)=_)
 */
[_LOWER] = LAYOUT_planck_grid(
    RALT(KC_2), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_UNDS,
    RALT(KC_4), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_NO,   KC_NO,   KC_PIPE,    KC_PLUS,
    KC_NO,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NUBS, S(KC_NUBS), S(KC_RBRC),
    KC_NO,      KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_MPLY, _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_NO,      KC_NO
),

/* Layer 2 — RAISE: numbers, brackets, navigation (SE OS output)
 * ,------+------+------+------+------+------+------+------+------+------+------+------.
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  €   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  (   |  )   |  {   |  }   |  [   |  ]   |  /   |  \   |  ^   |  |   |  µ   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `  †|  ´   |  "   |  '   |  +   |  -   |  *  †|  ~   |  =   |  :   |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Ins  | Del  |      |[Rse] | Home | PgUp | PgDn | End  |
 * `------+------+------+------+------+-------------+------+------+------+------+------'
 * † S(KC_EQL)→` (dead grave), KC_PIPE→* on SE.  KC_GT=S(.)=:  KC_LT=S(,)=; on SE.
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_NO, KC_1,      KC_2,    KC_3,       KC_4,       KC_5,      KC_6,      KC_7,    KC_8,          KC_9,       KC_0,          RALT(KC_E),
    KC_NO, KC_ASTR,   KC_LPRN, RALT(KC_7), RALT(KC_0), LCA(KC_8), LCA(KC_9), KC_AMPR, RALT(KC_MINS), S(KC_RBRC), RALT(KC_NUBS), RALT(KC_M),
    KC_NO, S(KC_EQL), KC_EQL,  KC_NUHS,    KC_AT,      KC_MINS,   KC_SLSH,   KC_PIPE, RALT(KC_RBRC), KC_RPRN,    KC_GT,         KC_LT,
    KC_NO, KC_NO,     KC_NO,   KC_NO,      KC_INS,     KC_DEL,    _______,   _______, KC_HOME,       KC_PGUP,    KC_PGDN,       KC_END
),

/* Layer 3 — SPARE: fully transparent, program freely in Vial */
[_SPARE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
