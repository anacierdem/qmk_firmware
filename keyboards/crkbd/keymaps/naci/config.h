/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
// This will make sure it detects master/slave with the KVM setup I have
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_USB_DETECT
// Read hand information from EEPROM
#define EE_HANDS

#define SPLIT_LAYER_STATE_ENABLE
#define TAPPING_TOGGLE 3

#ifdef POINTING_DEVICE_ENABLE
    #define SPLIT_POINTING_ENABLE
    #define POINTING_DEVICE_RIGHT
    #define MOUSE_EXTENDED_REPORT
    #define PIMORONI_TRACKBALL_SCALE 5

    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
    #define POINTING_DEVICE_ROTATION_90
#endif

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180

    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
