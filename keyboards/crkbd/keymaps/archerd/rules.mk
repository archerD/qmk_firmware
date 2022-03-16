OLED_ENABLE  = yes
OLED_DRIVER     = SSD1306
RGBLIGHT_ENABLE = yes
# RGB_MATRIX_ENABLE = yes

BOOTLOADER = qmk-dfu

# from miryoku rules.mk
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
WPM_ENABLE = yes


# from keyboard rules.mk
# if firmware size over limit, try this option
CFLAGS += -flto

