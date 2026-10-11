#include "input.h"
#include "board_config.h"
#include <stddef.h>

static bool input_ready = false;

/* 
 * -------------------------------------------------------------------
 * Private Hardware Helpers
 * -------------------------------------------------------------------
 */

/* Low-level MCU GPIO initialization for keys and rotary encoder */
static void mcu_gpio_input_init(void)
{
    /* 
     * TODO: Use WCH CH32V307 SDK functions to:
     * 1. Enable GPIO peripheral clocks for keys and knob.
     * 2. Configure Key 1, Key 2, and Key 3 pins as GPIO Inputs (Pull-up/Pull-down).
     * 3. Configure Rotary Knob Phase A / Phase B pins or ADC channels.
     */
}

/* Internal helper to fetch MCU uptime ticks in milliseconds */
static uint32_t get_system_time_ms(void)
{
    /* TODO: Return actual MCU millisecond tick counter (e.g., from SysTick) */
    return 0;
}

/* 
 * -------------------------------------------------------------------
 * Public Input API Functions
 * -------------------------------------------------------------------
 */

bool input_init(void)
{
    // 1. Initialize MCU GPIO hardware pins
    mcu_gpio_input_init();

    /* 
     * TODO: Set input_ready = true once input sensing peripherals 
     * are verified and initialized on the board.
     */  
    input_ready = true;
    return input_ready;
}

bool input_is_ready(void)
{
    return input_ready;
}

bool input_poll(input_event_t *event)
{
    if (!input_ready || event == NULL) {
        return false;
    }

    event->type = INPUT_EVENT_NONE;
    event->timestamp_ms = get_system_time_ms();

    /*
     * TODO: Read MCU GPIO state or rotary encoder registers:
     * 
     * 1. If Knob Turned Clockwise or Key 1 Pressed:
     *    event->type = INPUT_EVENT_UP;
     * 
     * 2. If Knob Turned Counter-Clockwise or Key 2 Pressed:
     *    event->type = INPUT_EVENT_DOWN;
     * 
     * 3. If Key 3 / Knob Click Pressed:
     *    event->type = INPUT_EVENT_SELECT;
     * 
     * 4. If Long Press or Secondary Key Pressed:
     *    event->type = INPUT_EVENT_BACK;
     */

    return (event->type != INPUT_EVENT_NONE);
}