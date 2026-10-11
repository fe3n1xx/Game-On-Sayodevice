#include "display.h"
#include "board_config.h"
#include "st7735s.h"
#include <stdio.h>

static bool display_ready = false;
static lcd_ptr_t display_handle;

/* 
 * -------------------------------------------------------------------
 * Low-Level Hardware Interface & Callbacks
 * -------------------------------------------------------------------
 */

/* MCU-specific SPI and GPIO clock/pin initialization */
static void mcu_spi_gpio_init(void)
{
    /* TODO: Enable APB/AHB clocks and configure SPI/GPIO control lines */
}

/* Transmit command byte over MCU SPI interface */
static void hw_write_cmd(uint8_t cmd)
{
    /* TODO: Transmit command byte over MCU SPI interface */
}

/* Transmit data byte over MCU SPI interface */
static void hw_write_data(uint8_t data)
{
    /* TODO: Transmit data byte over MCU SPI interface */
}

/* Toggle hardware RESET GPIO line */
static void hw_reset(void)
{
    /* TODO: Toggle hardware RESET GPIO line */
}

/* Call MCU millisecond delay routine */
static void hw_delay_ms(uint32_t ms)
{
    /* TODO: Call MCU millisecond delay routine */
}

/* Converts 24-bit 0x00RRGGBB (display_color_t) to 16-bit RGB565 format */
static uint16_t color_to_rgb565(display_color_t color)
{
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

/* 
 * -------------------------------------------------------------------
 * Public Display API Functions
 * -------------------------------------------------------------------
 */

bool display_init(void)
{
    /*
     * 1. Initialize MCU hardware SPI bus and GPIO control lines.
     * 2. Initialize the display driver using display_handle.
     * 3. Set display_ready = true only if initialization succeeds.
     */

    // 1. Initialize MCU SPI/GPIO pins
    mcu_spi_gpio_init();

    // 2. Create and activate settings using the library's supported API
    display_handle = lcd_createSettings(
        BOARD_DISPLAY_WIDTH,
        BOARD_DISPLAY_HEIGHT,
        0,
        0,
        BOARD_PIN_DISPLAY_DC,
        BOARD_PIN_DISPLAY_RESET
    );
    if (display_handle == NULL) {
        display_ready = false;
        return false;
    }

    lcd_setSettingsActive(display_handle);

    // 3. Set display_ready = true only if driver init succeeds
    display_ready = (lcd_initialize() == LCD_OK);
    return display_ready;
}

bool display_is_ready(void)
{
    return display_ready;
}

void display_draw_pixel(uint16_t x, uint16_t y, display_color_t color)
{
    if (!display_ready) {
        return;
    }

    /* Check x/y coordinates against confirmed screen dimensions (160x80) */
    if (x >= BOARD_DISPLAY_WIDTH || y >= BOARD_DISPLAY_HEIGHT) {
        return;
    }

    uint16_t hw_color = color_to_rgb565(color);

    /* Call the display driver's pixel-drawing function using display_handle */
    st7735s_draw_pixel(display_handle, x, y, hw_color);
}

void display_clear(display_color_t color)
{
    if (!display_ready) {
        return;
    }

    /* Fill the full 160x80 screen area */
    display_fill_rect(0, 0, BOARD_DISPLAY_WIDTH, BOARD_DISPLAY_HEIGHT, color);
}

void display_fill_rect(
    uint16_t x,
    uint16_t y,
    uint16_t width,
    uint16_t height,
    display_color_t color)
{
    if (!display_ready) {
        return;
    }

    /* Clip rectangle boundaries to screen limits (160x80) */
    if (x >= BOARD_DISPLAY_WIDTH || y >= BOARD_DISPLAY_HEIGHT) {
        return;
    }
    if (x + width > BOARD_DISPLAY_WIDTH) {
        width = BOARD_DISPLAY_WIDTH - x;
    }
    if (y + height > BOARD_DISPLAY_HEIGHT) {
        height = BOARD_DISPLAY_HEIGHT - y;
    }

    uint16_t hw_color = color_to_rgb565(color);

    /* Call the display driver's rectangle-fill function using display_handle */
    st7735s_fill_rect(display_handle, x, y, width, height, hw_color);
}