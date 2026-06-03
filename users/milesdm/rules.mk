ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += milesdm_rgb.c
endif

SRC += milesdm.c

LTO_ENABLE = yes
UNICODEMAP_ENABLE = yes