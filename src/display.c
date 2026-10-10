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
    
}