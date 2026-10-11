#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stdint.h>

/* 
 * Normalized Input Event Types
 * Maps raw key and knob actions into generic game/menu actions [1].
 */
typedef enum {
    INPUT_EVENT_NONE = 0,
    INPUT_EVENT_UP,
    INPUT_EVENT_DOWN,
    INPUT_EVENT_SELECT,
    INPUT_EVENT_BACK
} input_event_type_t;

/* Input event container passed to polling callers [4] */
typedef struct {
    input_event_type_t type;
    uint32_t timestamp_ms;
} input_event_t;

/**
 * @brief Initializes MCU input GPIO pins and rotary knob interfaces.
 * @return true if hardware initialization succeeds, false otherwise.
 */

bool input_init(void);
/**
 * @brief Polls the hardware for new button presses or knob rotation [4].
 * @param event Pointer to an input_event_t struct to store the detected event.
 * @return true if a new event was captured, false if no event occurred.
 */
bool input_poll(input_event_t *event);
#endif /* INPUT_H */