// Copyright 2024 OLKB
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Generated with: python3 util/vial_generate_keyboard_uid.py
#define VIAL_KEYBOARD_UID {0x2C, 0x7A, 0x52, 0x12, 0x3F, 0x28, 0x01, 0xDF}

// Unlock combo: hold the top-left key (Esc on the Svorak base layer) + the
// spacebar (row 3, col 5) for 5 seconds. The top-left key is also the
// Bootmagic Lite trigger — holding it alone during USB connect enters the
// bootloader, which is a useful coincidence: same physical key, two roles.
#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

// 4 layers keeps EEPROM usage comfortable on the ATmega32u4's 1KB EEPROM.
// Increase cautiously — each additional layer costs (MATRIX_ROWS * MATRIX_COLS * 2) bytes.
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// Bump debounce from the QMK default of 5 ms to 10 ms. The default algorithm
// (sym_defer_g) waits for the matrix to be stable for this long before reporting
// a change, so doubling it gives a wider margin against bouncy switches /
// stabilizer wobble at the cost of 5 ms of extra input latency (imperceptible
// for typing). Can be raised further (15–20) if double-tap symptoms persist.
#define DEBOUNCE 10
