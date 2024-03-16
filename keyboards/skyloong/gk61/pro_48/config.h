// Copyright 2023 linlin012 (@linlin012)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define IS31FL3743A_I2C_ADDRESS_1 IS31FL3743A_I2C_ADDRESS_GND_GND
#define IS31FL3743A_SDB_PIN A4

#define CAPS_LOCK_INDEX 28
#define FN1_MOD_INDEX 59
#define FN2_MOD_INDEX 63
#define FN3_MOD_INDEX 52
#define SDB A4

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS


#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define g_suspend_state rgb_matrix_get_suspend_state()
