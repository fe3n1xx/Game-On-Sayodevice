#include "display.h"
#include "board_config.h"
#include "st7735s.h"
#include <stdio.h>

/*
 * TODO:
 * Include the O3C display driver's header once the controller and interface
 * are confirmed. Do not guess the controller, pins, or SPI/I2C settings.
 */

static bool display_ready = false;

bool display_init(void)
{
    /*
    * TODO:
    * 1. Initialize the verified display interface/driver.
    * 2. Set display_ready = true only if initialization succeeds.
    */
    
    display_ready = false;
    return display_ready;
}

bool display_is_ready(void)
{
    return display_ready;
}

void display_draw_pixel(uint16_t x, uint16_t y, display_color_t color)
{
    (void)x;
    (void)y;
    (void)color;
    
    if (!display_ready) {
        return;
    }

    if (x >= 160 || y >= 80) {
        return;
    }

    // st377hs_draw_pixel(x, y, color);

}

void display_clear(display_color_t color)
{
    (void)color;

    if (!display_ready) {
        return;
    }

    display_fill_rect(0, 0, 160, 80, color);
}

void display_fill_rect(
    uint16_t x,
    uint16_t y,
    uint16_t width,
    uint16_t height,
    display_color_t color)
{
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    (void)color;

    if (!display_ready) {
        return;
    }

    if (x >= 160 || y >= 80) {
        return;
    }
    if (x + width > 160) {
        width = 160 - x;
    }
    if (y + height > 80) {
        height = 80 - y;
    }

    // st377hs_fill_rect(x, y, width, height, color);
}