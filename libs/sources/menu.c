#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/menutils.h"
#include "../headers/product_list.h"
#include "../headers/product.h"
#include "../headers/purchase.h"
#include "../headers/controller.h"
#include <stdbool.h>

extern ProductList pl;
extern PurchaseList purl;

// input functions
void getInt(int *val)
{
    while (true)
    {
        char buff[255];
        fgets(buff, sizeof(buff), stdin);
        if (sscanf(buff, "%d", val) == 0)
        {
            puts(ERR_WRONG_INPUT);
            printf(PROMPT_MARK);
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
            printf(PROMPT_MARK);
            continue;
        }
        break;
    }
}

// Prints Menu
void printMenu()
{
    printf(
        AJOUTER "\n" LISTER_PRD "\n" ACHETER "\n" SEARCH "\n" ESTOCK "\n" ALSTOCK "\n" SUPP_PROD "\n" ST_VNT "\n" QUITTER "\n>> ");
}

// done
void showAddProductView()
{
    system(CLEAR);
    char init_name[255];
    int init_quantity;
    double init_price;
renter_count:
    int count;
    printf(PROMPT_NPRODUCTS);
    getInt(&count);
    if (count <= 0)
    {
        puts(ERR_WRONG_INPUT);
        goto renter_count;
    }

    for (int i = 0; i < count; i++)
    {
        printf("-----%d-----\n", i) + 1;
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

    writeData(&pl, &purl);
    puts(PRODUCT_ADDED);
}
// done
void showListProductsView()
{
    system(CLEAR);
    printf(NOM_ASC "\n" PRIX_DESC "\n" RETOUR_MENU "\n" PROMPT_MARK);
    int choice;
renter_choix:
    getInt(&choice);
    switch (choice)
    {
    case CH_ORDER_BY_NAME_ASC:
        sortProductListByName(&pl, true);
        system(CLEAR);
        printProductList(pl);
        puts(RETOUR_MENU);

        break;
    case CH_ORDER_BY_PRICE_DESC:
        sortProductListByName(&pl, true);
        system(CLEAR);
        printProductList(pl);
        puts(RETOUR_MENU);
        break;
    case CH_RTEOUR_MENU:
        return;
        break;

    default:
        puts(ERR_OUT_OF_RANGE);
        printf(PROMPT_MARK);
        goto renter_choix;
        break;
    }
    printf(PROMPT_MARK);
    int input;
    do
    {
        getInt(&input);
    } while (input != 0);
}
// done
void showPurchaseView()
{
    system(CLEAR);
    int code;
renter_code:
    printf(PROMPT_PRODUCT_CODE);
    getInt(&code);
    int index = findProductByCode(pl, code);
    switch (index)
    {
    case NOT_FOUND:
        puts(ERR_PRD_NOT_FOUND);
        goto renter_code;
        break;
    default:
        printProduct(pl.elements[index]);
        int quantity;
    renter_qtty:
        printf(PROMPT_QTTY_CNSM);
        getInt(&quantity);
        if (quantity < 0)
        {
            puts(ERR_NEGATIVE_QTTY);
            printf(PROMPT_MARK);
            goto renter_qtty;
        }
        else if (quantity == 0)
        {
            puts(ERR_WRONG_INPUT);
            printf(PROMPT_MARK);
            goto renter_qtty;
        }

        int result = consumeQuanitity(pl.elements + index, quantity);

        switch (result)
        {
        case ERR_NO_ENOU_QTTY:
            puts(ERR_STOCK);
            goto renter_qtty;
            break;

        case W_LOW_QTTY:
            puts(WA_LOW_QTTY);
            recordPurchase(&purl, newPurchase(pl.elements[index], quantity));
            writeData(&pl, &purl);
            break;
        case SUCCESS:
            puts(PRODUCT_PRCD);
            recordPurchase(&purl, newPurchase(pl.elements[index], quantity));
            writeData(&pl, &purl);
            break;
        }
        break;
    }
}
//done
void showSearchView()
{
    system(CLEAR);
    puts(SRCH_CD "\n" SRCH_QTTY "\n" RETOUR_MENU);
renter_choice:
    printf(PROMPT_MARK);
    int choice;
    getInt(&choice);

    switch (choice)
    {
    case CH_SRCH_CODE:
        system(CLEAR);
    renter_code:
        printf(PROMPT_PRODUCT_CODE);
        int code;
        getInt(&code);
        if (code < 0)
        {
            puts(ERR_WRONG_INPUT);
            goto renter_code;
        }

        int index = findProductByCode(pl, code);
        switch (index)
        {
        case NOT_FOUND:
            puts(ERR_PRD_NOT_FOUND);
            goto renter_code;

        default:
            system(CLEAR);
            printProduct(pl.elements[index]);
            puts(RETOUR_MENU);
            int ch;

            do
            {
                printf(PROMPT_MARK);
                getInt(&ch);
            } while (ch != 0);

            break;
        }
        break;

    case CH_SRCH_QTTY:
        renter_qtty:
        printf(PROMPT_QTTY);
        int qtty;
        getInt(&qtty);
        if (qtty < 0)
        {
            puts(ERR_WRONG_INPUT);
            goto renter_qtty;
        }
        system(CLEAR);
        findProductsByQuantity(pl,qtty);
        puts(RETOUR_MENU);
        int ch;
        do
        {
            printf(PROMPT_MARK);
            getInt(&ch);
        } while (ch !=0);
        
        break;
    case CH_RTEOUR_MENU:
        return;
        break;
    default:
        puts(ERR_OUT_OF_RANGE);
        goto renter_choice;
        break;
    }
}
//almost done
void showStockStateView()
{
    system(CLEAR);
    puts("-----ETAT DE STOCK----");
    
    printLowQuantityProducts(pl);
    puts(RETOUR_MENU);
    int ch;
    do
    {
        printf(PROMPT_MARK);
        getInt(&ch);
    } while (ch!=0);
    
}

void showAddToStockView()
{
    system(CLEAR);
    
}

void showDeleteProductView()
{
    system(CLEAR);
    printf("V6");
}

void showStatisticsView()
{
    system(CLEAR);
    printTodayBrief(purl);
    puts(RETOUR_MENU);
    int ch;
    do
    {
        printf(PROMPT_MARK);
        getInt(&ch);
    } while (ch != 0);
}

void Menu()
{
    system(CLEAR);
    printMenu();

    int choice;
renter_choix:
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
    case CH_AL_STOCK:
        showAddToStockView();
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
        puts(ERR_OUT_OF_RANGE);
        printf(PROMPT_MARK);
        goto renter_choix;
        break;
    }
    puts("retour a menu ...");
}
