#pragma once

#include "quantum.h"

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX

//need to add unicode chars to the correct places in the keymap
// layer 2 F,G,H,J,K,L
enum unicode_names {
    POOP,
    SNEK,
    ROCK,
    ROFLA,
    ROFLB,
    FP
};

const uint32_t PROGMEM unicode_map[] = {
    [POOP] = 0x1F4A9,
    [SNEK] = 0x1F40D,
    [ROCK] = 0x1F918,
    [ROFLA] = 0x1F602,
    [ROFLB] = 0x1F923,
    [FP] = 0x1F926

};

enum custom_keycodes {
    SHRUG = SAFE_RANGE
};

#define KC_CAD	LALT(LCTL(KC_DEL))
#define KC_SLSF LSFT_T(KC_SLSH)


