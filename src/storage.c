#include "storage.h"
#include "board_config.h"

static bool storage_ready = false;

/* 
 * Built-in demo game script used for initial testing before
 * full flash storage/file transfer is implemented.
 */
static const char demo_script[] = 
    "// SayoDevice Demo Game\n"
    "INIT\n"
    "DRAW_RECT 10 10 20 20 RED\n";

bool storage_init(void)
{
    /* 
     * TODO: Later initialize flash memory sectors or filesystem headers.
     * For now, mark as ready to serve the built-in demo script.
     */
    storage_ready = true;
    return storage_ready;
}

bool storage_is_ready(void)
{
    return storage_ready;
}

size_t storage_get_game_count(void)
{
    if (!storage_ready) {
        return 0;
    }

    /* Return 1 for the built-in demo game */
    return 1;
}

bool storage_get_game_script(size_t index, const char **out_script, size_t *out_size)
{
    if (!storage_ready || out_script == NULL || out_size == NULL) {
        return false;
    }

    /* Only index 0 (demo script) is currently supported */
    if (index != 0) {
        return false;
    }

    *out_script = demo_script;
    *out_size = sizeof(demo_script) - 1;
    return true;
}