// Copyright 2025 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_INIT_DELAY
#define AUDIO_PIN B7
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#define SOLENOID_PIN   B0
#define NO_HAPTIC_MOD

#define SOLENOID_DEFAULT_DWELL 12

#define HAPTIC_OFF_IN_LOW_POWER 1
#define HAPTIC_ENABLE_STATUS_LED F1

// SPI configuration
#define SPI_MATRIX_DIVISOR 16
#define SPI_MODE 0

// GPIO config for main SPI config needs to match up with the SPI bus you are using
#define SPI_MISO_PIN NO_PIN

// GPIO config for CS/latch pins can be any GPIO
#define SPI_MATRIX_LATCH_PIN B6

// custom matrix config
#define MATRIX_COLS_SHIFT_REGISTER_COUNT 1

// LED for layer indicator
#define LED_LAYER_PIN F0

#ifdef AUTO_SHIFT_ENABLE
#define AUTO_SHIFT_TIMEOUT 500
#endif
