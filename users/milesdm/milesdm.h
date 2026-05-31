#pragma once

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

#define KC_CAD	LALT(LCTL(KC_DEL))
#define KC_SLSF LSFT_T(KC_SLSH)

#define MILES_COLOR 30, 218, 118
#define MILES_COLOR_CAPS 0, 0, 118