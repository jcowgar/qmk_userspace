#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SLEEP // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs

// Enable RGB Matrix effects
#    define ENABLE_RGB_MATRIX_SOLID_COLOR
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#endif
