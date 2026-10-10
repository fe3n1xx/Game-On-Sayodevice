#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t display_color_t;

#define DISPLAY_COLOR_BLACK ((display_color_t)0x00000000u)
#define DISPLAY_COLOR_WHITE ((display_color_t)0x00FFFFFFu)
#define DISPLAY_COLOR_RED ((display_color_t)0x00FF0000u)
#define DISPLAY_COLOR_GREEN ((display_color_t)0x0000FF00u)
#define DISPLAY_COLOR_BLUE ((display_color_t)0x000000FFu)

bool display_init(void);
void display_draw_pixel(uint16_t x, uint16_t y, display_color_t color);
void display_clear(display_color_t color);

void display_fill_rect(
    uint16_t x,
    uint16_t y,
    uint16_t width,
    uint16_t height,
    display_color_t color
);

/* Add text drawing with font, refer to todo and howtodo.txt */


#endif /* DISPLAY_H */