#include "quantum.h"

#why am I needing this is c and h?
enum custom_keycodes {
    SHRUG = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHRUG:
            if (record->event.pressed) {
                send_unicode_string("¯\\_(ツ)_/¯");
            }
            return false;
    }
    return true;
}
