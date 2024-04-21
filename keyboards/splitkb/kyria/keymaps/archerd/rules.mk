# set default bootloader
BOOTLOADER = qmk-dfu
# convert to the rp2040, since using liatris controller
CONVERT_TO = promicro_rp2040

# enabled featuers
OLED_ENABLE = yes
OLED_DRIVER = ssd1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
LEADER_ENABLE = yes
# SWAP_HANDS_ENABLE = yes
# WPM_ENABLE = yes

# rgb stuff
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no
#RGBLIGHT_ENABLE = no
#RGB_MATRIX_ENABLE = yes

# some features that I may want to enable
#BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
#NKRO_ENABLE = yes           # Enable N-Key Rollover

# disabled features and size reductions
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# already disabled features and size reductions
#BOOTMAGIC_ENABLE = no
#CONSOLE_ENABLE = no
#COMMAND_ENABLE = no
#NKRO_ENABLE = no

