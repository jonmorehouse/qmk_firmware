// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "haptic.h"

#define NUM_LAYER     1

// Initialize solenoid pin as early as possible to prevent floating
void keyboard_pre_init_user(void) {
  setPinOutput(B0);
  writePinLow(B0);
}

void matrix_init_user(void) {
  setPinOutput(LED_LAYER_PIN);
}

void keyboard_post_init_user(void) {
  // Force haptic/solenoid ON at startup
  haptic_enable();
}

// Initialize your default layer
layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, NUM_LAYER)) {
#ifdef LED_ACTIVE_LOW
    writePinLow(LED_LAYER_PIN);
#else
    writePinHigh(LED_LAYER_PIN);
#endif
  }
  else {
#ifdef LED_ACTIVE_LOW
    writePinHigh(LED_LAYER_PIN);
#else
    writePinLow(LED_LAYER_PIN);
#endif
  }

  return state;
}