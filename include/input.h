#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stdint.h>

/* 
 * Normalized Input Event Types
 * Maps raw key and knob actions into generic game/menu actions [2, 3].
 */
typedef enum {
    INPUT_EVENT_NONE = 0,
    INPUT_EVENT_UP,
    INPUT_EVENT_DOWN,
    INPUT_EVENT_SELECT,
    INPUT_EVENT_BACK
} input_event_type_t;

/* Input event container passed to polling callers [2] */
typedef struct {
    input_event_type_t type;
    uint32_t timestamp_ms;
} input_event_t;

/**
 * @brief Initializes MCU input GPIO pins and rotary knob interfaces [2, 4].
 * @return true if hardware initialization succeeds, false otherwise.
 */
bool input_init(void);

/**
 * @brief Returns whether the input module has been successfully initialized [1].
 * @return true if input hardware is ready, false otherwise.
 */
bool input_is_ready(void);

/**
 * @brief Polls the hardware for new button presses or knob rotation [2, 5].
 * @param event Pointer to an input_event_t struct to store the detected event.
 * @return true if a new event was captured, false if no event occurred.
 */
bool input_poll(input_event_t *event);

#endif /* INPUT_H */