#define APP_NAME " GESTIONAIRE DE PHARMACIE "

#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <menu.h>
#include <string.h>

#include "styling_lib.h"



#define CREAOTR " Created By Amine GITHUB:6-ON "

// menu options
#define AJOUTER "Ajouter nouveau produits"
#define LISTER_PRD "Lister tous les produit" // Par prix et Nom
#define ACHETER "Acheter produit"
#define SEARCH "Rechercher les produits"  // par code et quantite
#define ESTOCK "Afficher l'etat du stock" // low quantity
#define SUPP_PROD "Supprimer Produit"
#define ST_VNT "Statistique de vente" // min max avg total
#define QUITTER "Quitter"              // min max avg total

#define N_CHOICES 8
#define CH_AJOUTER 0
#define CH_LISTER_PRD 1
#define CH_ACHETER 2
#define CH_SEARCH 3
#define CH_ESTOCK 4
#define CH_SUPP_PROD 5
#define CH_ST_VNT 6
#define CH_QUITTER 7

int calcCenterH(WINDOW *_w, char *_str) { return getmaxx(_w) / 2 - strlen(_str) / 2; }

int main()
{
    init_curses();
    int termH, termW;
    getmaxyx(stdscr, termW, termH); // get terminal dimens

    int winH = termW - 2;          // set the height
    int winW = ASPECT_RATIO(winH); // set the width

    // int winY = termW / 2 - winH / 2; // set Y
    // int winX = termH / 2 - winW / 2; // set X
    int winY = CENTER_VH(termW, winH); // set Y
    int winX = CENTER_VH(termH, winW); // set X

    WINDOW *menuWin = newwin(winH, winW, winY, winX); // create menu window
    box(menuWin, 0, 0);                               // add border

    wprintStyled(menuWin, APP_NAME, 0, calcCenterH(menuWin, APP_NAME), SELECTED_PAIR);

    wprintStyled(menuWin, CREAOTR, winH - 1, calcCenterH(menuWin, CREAOTR), INFO_PAIR);

    keypad(menuWin, TRUE); // to make window read special keys

    ITEM **menuItems;
    MENU *mainMenu;

    menuItems = calloc(N_CHOICES + 1, sizeof(ITEM *)); // still not understood why the additional item
    char *choices[] = {AJOUTER, LISTER_PRD,
                       ACHETER, SEARCH,
                       ESTOCK, SUPP_PROD,
                       ST_VNT, QUITTER};
    for (int i = 0; i < N_CHOICES; i++)
        menuItems[i] = new_item(choices[i], "");

    menuItems[N_CHOICES] = (ITEM *)NULL; // now i undestand why we allocate additional item
    mainMenu = new_menu(menuItems);

    wmove(menuWin, 5, 5);
    set_menu_win(mainMenu, menuWin);
    set_menu_sub(mainMenu, derwin(menuWin, N_CHOICES * 2, mainMenu->width, 5, 5));
    set_menu_spacing(mainMenu, 0, 2, 1);
    set_menu_mark(mainMenu, ">");
    post_menu(mainMenu);

    int c;
    while ((c = wgetch(menuWin)) != '\n')
    {
        switch (c)
        {
        case KEY_UP:
            menu_driver(mainMenu, REQ_UP_ITEM);
            break;
        case KEY_DOWN:
            menu_driver(mainMenu, REQ_DOWN_ITEM);
            break;
        }
    }
    int selectedIndex = mainMenu->curitem->index;
    unpost_menu(mainMenu);
    free_menu(mainMenu);                // deallocate menu memory
    for (int i = 0; i < N_CHOICES; ++i) // decallocate  items memory
        free_item(menuItems[i]);
    endwin();

    switch (selectedIndex)
    {
    case CH_AJOUTER:
        puts("you selected " AJOUTER);
        break;
    case CH_LISTER_PRD:
        puts("you selected " LISTER_PRD);
        break;
    case CH_ACHETER:
        puts("you selected " ACHETER);
        break;
    case CH_SEARCH:
        puts("you selected " SEARCH);
        break;
    case CH_ESTOCK:
        puts("you selected " ESTOCK);
        break;
    case CH_SUPP_PROD:
        puts("you selected " SUPP_PROD);
        break;
    case CH_ST_VNT:
        puts("you selected " ST_VNT);
        break;
    case CH_QUITTER:
        puts("you selected " QUITTER);
        break;

    }






    return 0;
}