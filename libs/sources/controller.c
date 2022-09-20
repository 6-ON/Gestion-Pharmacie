#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../headers/controller.h"
#define SAVE_LOAD_FORMAT "%d %s %lf %d\n"

FILE *openData(char *mode)
{
    FILE *data;
    data = fopen("data.txt", mode);
    if (data == NULL)
    {
        fprintf(stderr, "Can't open data.txt file :%s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return data;
}
// data should be 111111 nnnnn 111.000 13
ProductList getData()
{
    FILE *data = openData("r+");
    unsigned int pcode;
    char pnom[255];
    double pprice;
    unsigned int pqtty;


    ProductList loadedPL = newProductList();
    while (fscanf(data,SAVE_LOAD_FORMAT , &pcode, pnom, &pprice, &pqtty) != EOF)
    {
        Product p = initProduct(pcode,pnom,pprice,pqtty);
        addProduct(&loadedPL, p);
    }

    fclose(data);
    return loadedPL;
}

void writeData(ProductList *pL){
    FILE *data = openData("w+");
    sortProductListByCode(pL,true); // resort by code to insure that the currentprodCode work as expected
    for (int i = 0; i <pL->length ; i++)
    {
        Product p = pL->elements[i];
        fprintf(data,SAVE_LOAD_FORMAT,p.code,p.name,p.price,p.quantity);
    }
    fclose(data);
    
}