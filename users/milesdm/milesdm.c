#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    RGB_user_wants_enabled = rgblight_config.enable;
    RGB_current_mode = rgblight_config.mode;
    RGB_current_hue  = rgblight_config.hue;
    RGB_current_sat  = rgblight_config.sat;
    RGB_current_val  = rgblight_config.val;
}

// Restore user settings
void restore_user_rgb_settings(void) {
    // First, enable RGB
    if (RGB_user_wants_enabled && !rgblight_config.enable) {
        rgblight_enable();
    } else if (!RGB_user_wants_enabled && rgblight_config.enable) {
        rgblight_disable();
    }

    // Restore settings
    rgblight_sethsv(RGB_current_hue, RGB_current_sat, RGB_current_val); // Restore underglow RGB color
    rgblight_mode(RGB_current_mode); // Restore RGB mode
};

void toggle_rgb_caps_lock(bool isActive) {
    if (rgblight_config.enable) {
        if (isActive) {
            // Set underglow color if CAPS_LOCK enabled
            rgblight_sethsv(MILES_COLOR_CAPS);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING +3);
        } else {
            restore_user_rgb_settings();
        }
    }

};

bool led_update_user(led_t led_state) {
    toggle_rgb_caps_lock(led_state.caps_lock);
    return true;
};
#endif