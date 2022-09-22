#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../headers/controller.h"
#define SAVE_LOAD_FORMAT "%d %s %lf %d\n"
#define SAVE_LOAD_FORMAT2 "%d %lf %d %d %d %d\n"

FILE *openData(char *file_name, char *mode)
{
    FILE *data;
    data = fopen(file_name, mode);
    if (data == NULL)
    {
        fprintf(stderr, "Can't open the data file :%s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return data;
}
// data should be 111111 nnnnn 111.000 13
ProductList getProductsData()
{
    FILE *data = openData("produits.txt", "r");
    unsigned int pcode;
    char pnom[255];
    double pprice;
    unsigned int pqtty;

    ProductList loadedPL = newProductList();
    while (fscanf(data, SAVE_LOAD_FORMAT, &pcode, pnom, &pprice, &pqtty) != EOF)
    {
        Product p = initProduct(pcode, pnom, pprice, pqtty);
        addProduct(&loadedPL, p);
    }

    fclose(data);
    return loadedPL;
}

PurchaseList getRecordsData()
{
    FILE *data = openData("achats.txt", "r");
    PurchaseList loadedPurl = newPurchaselist();
    unsigned int pcode;
    double pprice;
    unsigned int phour;
    unsigned int pmday;
    unsigned int pmo;
    unsigned int pyear;
    
    while (fscanf(data, SAVE_LOAD_FORMAT2, &pcode, &pprice, &phour, &pmday,&pmo,&pyear) != EOF)
    {
        Purchase pur = initPurchase(pcode,pprice,phour,pmday,pmo,pyear);
        recordPurchase(&loadedPurl,pur);
    }
    fclose(data);
    return loadedPurl;
}

void writeData(ProductList *pL, PurchaseList *purL)
{
    // sortProductListByCode(pL, true); // resort by code to insure that the currentprodCode work as expected
    
    // write products
    FILE *prodData = openData("produits.txt", "w");
    for (int i = 0; i < pL->length; i++)
    {
        Product p = pL->elements[i];
        fprintf(prodData, SAVE_LOAD_FORMAT, p.code, p.name, p.price, p.quantity);
    }
    fclose(prodData);

    // write purchases
    FILE *recData = openData("achats.txt", "w");
    for (int i = 0; i < purL->length; i++)
    {
        Purchase pur = purL->elements[i];
        fprintf(recData, SAVE_LOAD_FORMAT2,
                pur.codePrd,
                pur.price,
                pur.pr_time.tm_hour,
                pur.pr_time.tm_mday,
                pur.pr_time.tm_mon,
                pur.pr_time.tm_year);
    }
    fclose(recData);
}