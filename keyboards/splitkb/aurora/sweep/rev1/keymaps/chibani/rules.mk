# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

RGBLIGHT_ENABLE = yes # Enables QMK's RGB code
RGBLIGHT_DRIVER = ws2812
WS2812_DRIVER_REQUIRED = yes
WS2812_DRIVER = vendor # Use the RP2040's PIO interface

OLED_ENABLE = yes
OLED_VERBOSE = no
WPM_ENABLE = yes

UNICODEMAP_ENABLE = yes

CONSOLE_ENABLE = no

SRC += $(USER_PATH)/chibani.c

include $(USER_PATH)/oled/rules.mk
