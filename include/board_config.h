#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

/* Board and Microcontroller Identification */
#define BOARD_NAME                  "SayoDevice O3C (Trial Build)"
#define BOARD_MCU_PART_NUMBER       "CH32V307WCU6"
#define BOARD_CPU_FREQUENCY_HZ      144000000UL

/* Hardware Configuration Status Flags */
#define BOARD_DISPLAY_CONFIGURED    1
#define BOARD_INPUT_CONFIGURED      0
#define BOARD_STORAGE_CONFIGURED    0

/* Display Parameters */
#define BOARD_DISPLAY_WIDTH         160
#define BOARD_DISPLAY_HEIGHT        80
#define BOARD_DISPLAY_CONTROLLER    "ST7735S"
#define BOARD_DISPLAY_INTERFACE     "SPI"

/* 
 * Trial Hardware SPI Pin Mapping (CH32V307 Default Pins)
 */
#define BOARD_TRIAL_SPI_INSTANCE    SPI1
#define BOARD_PIN_SPI_SCK           GPIO_Pin_5  // PA5 (SPI1 SCK)
#define BOARD_PIN_SPI_MOSI          GPIO_Pin_7  // PA7 (SPI1 MOSI)
#define BOARD_PIN_DISPLAY_CS        GPIO_Pin_4  // PA4 (Chip Select)
#define BOARD_PIN_DISPLAY_DC        GPIO_Pin_1  // PB1 (Data/Command)
#define BOARD_PIN_DISPLAY_RESET     GPIO_Pin_0  // PB0 (Reset)

/* Input Controls */
#define BOARD_KEY_COUNT             3

/* Storage Settings */
#define BOARD_STORAGE_TYPE          "Internal Flash"
#define BOARD_STORAGE_CAPACITY_BYTES 480000

/* Compile-Time Safety Guard Checks */
#if BOARD_DISPLAY_CONFIGURED && \
    (!defined(BOARD_DISPLAY_WIDTH) || !defined(BOARD_DISPLAY_HEIGHT))
#error "Define confirmed display width and height in board_config.h"
#endif

#endif /* BOARD_CONFIG_H */

