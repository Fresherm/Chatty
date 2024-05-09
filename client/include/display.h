#include <stdint.h>

#ifndef _DISPLAY_H
#define _DISPLAY_H 1

#define clearScreen() \
    { printf("\033[2J"); }
#define setCur(line, column) \
    { printf("\033[%d;%dH", line, column); }
#define saveCur() \
    { printf("\0337"); }
#define restoreCur() \
    { printf("\0338"); }

#ifdef __cplusplus
extern "C" {
#endif

struct curPosition {
    uint16_t row, col;
};

void positionPrint(struct curPosition position, struct curPosition limit, char *format, ...);

void clear(struct curPosition start, struct curPosition limit);

void clearInput();

#ifdef __cplusplus
}
#endif
#endif
