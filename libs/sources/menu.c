#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/menutils.h"
#include "../headers/product_list.h"
#include "../headers/product.h"
#include "../headers/controller.h"
#include <stdbool.h>

extern ProductList pl;

// input functions
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
// Prints Menu
void printMenu()
{
    printf(
        AJOUTER "\n" LISTER_PRD "\n" ACHETER "\n" SEARCH "\n" ESTOCK "\n" SUPP_PROD "\n" ST_VNT "\n" QUITTER "\n>> ");
}

// done
void showAddProductView()
{
    system(CLEAR);
    char init_name[255];
    int init_quantity;
    double init_price;
    int count;
    printf(PROMPT_NPRODUCTS);
    getInt(&count);
    for (int i = 0; i < count; i++)
    {
        printf("%d\n",i);
        printf(PROMPT_PRODUCT_NAME);

        fgets(init_name, sizeof(init_name), stdin);
        init_name[strcspn(init_name, "\n")] = 0;
    renter_price:
        printf(PROMPT_PRODUCT_PRICE);
        getDouble(&init_price);
        if (init_price < 0)
        {
            puts(ERR_NEGATIVE_PRICE);
            goto renter_price;
        }

    renter_quantite:
        printf(PROMPT_QTTY);
        getInt(&init_quantity);
        if (init_quantity < 0)
        {
            puts(ERR_NEGATIVE_QTTY);
            goto renter_quantite;
        }
        addProduct(&pl, newProduct(init_name, init_price, (unsigned int)init_quantity));
    }

    writeData(&pl);
    puts(PRODUCT_ADDED);
}
void showListProductsView()
{
    system(CLEAR);
    printProductList(pl);
    puts("<--0");
    puts(">>");
    int input;
    do
    {
        getInt(&input);
    } while (input != 0);
}
void showPurchaseView()
{
    system(CLEAR);
}
void showSearchView()
{
    system(CLEAR);
    printf("V4");
}
void showStockStateView()
{
    system(CLEAR);
    printf("V5");
}
void showDeleteProductView()
{
    system(CLEAR);
    printf("V6");
}
void showStatisticsView()
{
    system(CLEAR);
    printf("V7");
}

void Menu()
{
    system(CLEAR);
    printMenu();
    int choice;
    getInt(&choice);
    switch (choice)
    {
    case CH_AJOUTER:
        showAddProductView();
        break;
    case CH_LISTER_PRD:
        showListProductsView();
        break;
    case CH_ACHETER:
        showPurchaseView();
        break;
    case CH_SEARCH:
        showSearchView();
        break;
    case CH_ESTOCK:
        showStockStateView();
        break;
    case CH_SUPP_PROD:
        showDeleteProductView();
        break;
    case CH_ST_VNT:
        showStatisticsView();
        break;
    case CH_QUITTER:
        puts(QUIT_MESSAGE);
        exit(EXIT_SUCCESS);
        break;

    default:
        puts(ERR_WRONG_INPUT);
        break;
    }
    puts("retour a menu ...");
}
