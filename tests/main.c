#include <ncurses.h>
#include <curses.h>
#include <string.h>

#define SELECTED_PAIR 1
#define ERROR_PAIR 2
#define WARNING_PAIR 3
#define INFO_PAIR 4
#define SUCCESS_PAIR 5

#define APP_NAME " GESTIONAIRE DE PHARMACIE "

#define CREAOTR " Created By Amine GITHUB:6-ON "

// menu options
#define CHOICE_1 "Ajouter nouveau produits"
#define CHOICE_2 "Lister tous les produit" // Par prix et Nom
#define CHOICE_3 "Acheter produit"
#define CHOICE_4 "Rechercher les produits"  // par code et quantite
#define CHOICE_5 "Afficher l'etat du stock" // low quantity
#define CHOICE_6 "Supprimer Produit"
#define CHOICE_7 "Statistique de vente" // min max avg total

void setupPairs()
{
    start_color(); 

    init_pair(SELECTED_PAIR, COLOR_BLACK, COLOR_WHITE); // init selected pair

    init_pair(ERROR_PAIR, COLOR_WHITE, COLOR_RED); // init error pair

    init_pair(WARNING_PAIR, COLOR_WHITE, COLOR_YELLOW); // init warning pair

    init_pair(INFO_PAIR, COLOR_WHITE, COLOR_BLUE); // init info pair

    init_pair(SUCCESS_PAIR, COLOR_WHITE, COLOR_GREEN); // init SUCESS pair
}

int main()
{
    initscr();   // initiate screen
    noecho();    // prevent printing user input
    curs_set(0); // remove the insertion cursor
    setupPairs();
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax); // get terminal dimens

    int winH = yMax - 2; // set the height
    int winW = winH * 2; // set the width

    int winY = yMax / 2 - winH / 2; // set Y
    int winX = xMax / 2 - winW / 2; // set X

    WINDOW *menuWin = newwin(winH, winW, winY, winX); // create menu window

    box(menuWin, 0, 0); // add border

    wattron(menuWin, COLOR_PAIR(SELECTED_PAIR));                      // set the pair on
    mvwprintw(menuWin, 0, winW / 2 - strlen(APP_NAME) / 2, APP_NAME); // Print app name in the top center
    wattroff(menuWin, COLOR_PAIR(SELECTED_PAIR));                     // set the pair off

    wattron(menuWin, COLOR_PAIR(INFO_PAIR));                               // set the pair on
    mvwprintw(menuWin, winH - 1, winW / 2 - strlen(CREAOTR) / 2, CREAOTR); // Print app name in the buttom center
    wattroff(menuWin, COLOR_PAIR(INFO_PAIR));                              // set the pair off

    mvwprintw(menuWin, 4, 5, CHOICE_1);
    while(wgetch(menuWin)!=KEY_UP){
        waddch(menuWin,'a');
    }

    endwin();
}