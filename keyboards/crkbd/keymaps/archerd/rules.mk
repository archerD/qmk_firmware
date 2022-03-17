# enabled features
OLED_ENABLE  = yes
OLED_DRIVER     = SSD1306
# RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = yes
WPM_ENABLE = yes
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
LEADER_ENABLE = yes

# set default bootloader
BOOTLOADER = qmk-dfu

# disabled features and size reductions
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
NKRO_ENABLE = no # I don't have a key to set n key rollover, so not very useful

# from miryoku rules.mk
# from keyboard rules.mk
# if firmware size over limit, try this option
LTO_ENABLE = yes

