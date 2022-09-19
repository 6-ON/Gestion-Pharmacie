
#include "styling_lib.h"

void init_curses()
{
    initscr();   // initiate screen
    noecho();    // prevent printing user input
    curs_set(0); // remove the insertion cursor

    start_color();

    init_pair(SELECTED_PAIR, COLOR_BLACK, COLOR_WHITE); // init selected pair

    init_pair(ERROR_PAIR, COLOR_WHITE, COLOR_RED); // init error pair

    init_pair(WARNING_PAIR, COLOR_WHITE, COLOR_YELLOW); // init warning pair

    init_pair(INFO_PAIR, COLOR_WHITE, COLOR_BLUE); // init info pair

    init_pair(SUCCESS_PAIR, COLOR_WHITE, COLOR_GREEN); // init SUCESS pair
}

void wprintStyled(WINDOW *_w, char *_str, int y, int x, int pair)
{

    wattron(_w, COLOR_PAIR(pair));  // set the pair on
    mvwprintw(_w, y, x, _str);      // Print the stin
    wattroff(_w, COLOR_PAIR(pair)); // set the pair off
}
