SRC += features/mouse_turbo_click.c

# Bootloader selection
BOOTLOADER = rp2040

SPLIT_KEYBOARD = yes


MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

OLED_ENABLE = yes
LTO_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

CAPS_WORD_ENABLE = yes

OS_DETECTION_ENABLE = yes

LAYER_LOCK_ENABLE = yes

AUDIO_ENABLE = yes

POINTING_DEVICE_ENABLE = no
TAP_DANCE_ENABLE = no

# RGB_MATRIX_ENABLE = yes