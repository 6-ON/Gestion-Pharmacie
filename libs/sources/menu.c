#include <stdio.h>
#include <stdlib.h>
#include "../headers/menutils.h"
#include <stdbool.h>

void getInt(int *val)
{
    while (true)
    {
        char buff[255];
        fgets(buff, sizeof(buff), stdin);
        if (sscanf(buff, "%d", val) == WRONG_INPUT)
        {
            puts(ERR_WRONG_INPUT);
            printf("|>> ");
            continue;
        }
        break;
    }
}
void getDouble(double *val)
{
    while (true)
    {
        char buff[255];
        fgets(buff, sizeof(buff), stdin);
        if (sscanf(buff, "%lf", val) == WRONG_INPUT)
        {
            puts(ERR_WRONG_INPUT);
            printf(">> ");
            continue;
        }
        break;
    }
}
void printMenu()
{
    printf(
        AJOUTER"\n"LISTER_PRD"\n"
        ACHETER"\n"SEARCH"\n"
        ESTOCK"\n"SUPP_PROD"\n"
        ST_VNT"\n"QUITTER"\n>> "
    );
}

void showAddProductView(){
    
}
void showListProductsView(){

}
void showPurchaseView(){

}
void showSearchView(){

}
void showStockStateView(){

}
void showDeleteProductView(){

}
void showStatisticsView(){

}
void Menu(){
    system(CLEAR);
    printMenu();
    int choice;
    getInt(&choice);
    switch (choice)
    {
    case CH_AJOUTER :
        showAddProductView();
        break;
    case CH_LISTER_PRD:
        showListProductsView();
        break;
    case CH_ACHETER :
        showPurchaseView();
        break;
    case CH_SEARCH :
        showSearchView();
        break;
    case CH_ESTOCK :
        showStockStateView();
        break;
    case CH_SUPP_PROD :
        showDeleteProductView();
        break;
    case CH_ST_VNT :
        showStatisticsView();
        break;
    case CH_QUITTER :
        puts(QUIT_MESSAGE);
        exit(EXIT_SUCCESS);
        break;
    
    default:
    puts(ERR_WRONG_INPUT);
        break;
    }




}

