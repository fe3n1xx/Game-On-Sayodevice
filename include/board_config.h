#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#define BOARD_MCU_PART_NUMBER "CH32V305CCT6"
#define BOARD_CPU_FREQUENCY_HZ 8000
#define BOARD_DISPLAY_WIDTH 160
#define BOARD_DISPLAY_HEIGHT 80

/* Set to 1 only after the corresponding hardware details are verified. */
#define BOARD_DISPLAY_CONFIGURED 0
#define BOARD_INPUT_CONFIGURED   0
#define BOARD_STORAGE_CONFIGURED 0

#define BOARD_DISPLAY_CONTROLLER "undef"
#define BOARD_DISPLAY_INTERFACE "undef"

#define BOARD_KEY_COUNT 3
#define BOARD_KEY_PINS "undef"
#define BOARD_KNOB_PIN_A "undef"
#define BOARD_KNOB_PIN_B "undef"

#define BOARD_STORAGE_TYPE "Internal Flash"
#define BOARD_STORAGE_CAPACITY_BYTES 480000 /* CHECK */


#if BOARD_DISPLAY_CONFIGURED && \
    (!defined(BOARD_DISPLAY_WIDTH) || !defined(BOARD_DISPLAY_HEIGHT))
#error "Define confirmed display width and height in board_config.h"
#endif

#endif /* BOARD_CONFIG_H */

