#ifndef STORAGE_H
#define STORAGE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * @brief Initializes storage subsystems or built-in script references.
 * @return true if storage is available, false otherwise.
 */
bool storage_init(void);

/**
 * @brief Checks if storage has been initialized.
 * @return true if storage is ready, false otherwise.
 */
bool storage_is_ready(void);

/**
 * @brief Gets the total number of installed or available game scripts.
 * @return Number of available game files.
 */
size_t storage_get_game_count(void);

/**
 * @brief Retrieves the script data buffer for a given game index.
 * @param index The zero-based index of the game.
 * @param out_script Pointer to receive the script buffer address.
 * @param out_size Pointer to receive the size of the script in bytes.
 * @return true if game script was retrieved successfully, false otherwise.
 */
bool storage_get_game_script(size_t index, const char **out_script, size_t *out_size);

#endif /* STORAGE_H */