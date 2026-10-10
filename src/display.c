#include "display.h"

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

    /*
    * TODO:
    * Check x/y against the confirmed display dimensions.
    * Convert color to the hardware's pixel format.
    * Call the display driver's pixel-drawing function.
    */
}

void display_clear(display_color_t color)
{
    (void)color;

    if (!display_ready) {
        return;
    }

    /*
    * TODO: Call the driver's screen-fill/clear function.
    */
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

    /*
    * TODO:
    * Clip the rectangle to screen bounds, then call the driver.
    */
}