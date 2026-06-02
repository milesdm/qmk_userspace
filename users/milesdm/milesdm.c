#ifdef RGBLIGHT_ENABLE
// Helper function to apply colors and effects based on current layer state
void update_underglow_state(void) {
    if (host_keyboard_led_state().caps_lock) {
        return;
    }

    if (layer_state_is(2)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); 
        rgblight_setrgb_noeeprom(MILES_LAYER2_COLOR);
    } else if (layer_state_is(1)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); 
        rgblight_setrgb_noeeprom(MILES_LAYER1_COLOR);
    } else {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb_noeeprom(MILES_COLOR);
    }
}

// 1. Set initial state on boot
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); 
    update_underglow_state();
}

// 2. Trigger color and effect updates when layers shift
layer_state_t layer_state_set_user(layer_state_t state) {
    if (host_keyboard_led_state().caps_lock) {
        return state;
    }

    if (layer_state_cmp(state, 2)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        rgblight_setrgb_noeeprom(MILES_LAYER2_COLOR);
    } else if (layer_state_cmp(state, 1)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        rgblight_setrgb_noeeprom(MILES_LAYER1_COLOR);
    } else {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb_noeeprom(MILES_COLOR);
    }

    return state;
}

// 3. Trigger color updates when Caps Lock toggles
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); 
        rgblight_setrgb_noeeprom(MILES_CAPS_COLOR); 
    } else {
        update_underglow_state();
    }
    return true;
}

#endif
