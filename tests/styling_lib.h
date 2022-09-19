#ifndef SYLING_LIBS_H
#define SYLING_LIBS_H
#include <ncurses.h>
#include <curses.h>
#define ASPECT_RATIO(h) h * 2
#define CENTER_VH(pw, cw) (pw - cw) / 2

//color pairs
#define SELECTED_PAIR 1
#define ERROR_PAIR 2
#define WARNING_PAIR 3
#define INFO_PAIR 4
#define SUCCESS_PAIR 5

void init_curses();

void wprintStyled(WINDOW *_w, char *_str, int y, int x, int pair);
#endif 