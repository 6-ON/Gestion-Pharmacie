#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "libs/headers/product_list.h"
#define REFRESH_DELAY 2
#define PROD_CODE_START 1000000000

int main(int argc, char const *argv[])
{

    currentprodCode = PROD_CODE_START; // product codes starts from here
    ProductList pl= newProductList();
    Product p1= newProduct("morphine",23,7);
    Product p2= newProduct("Pomada safra",306.45,7);
    Product p3= newProduct("doliprane",100,2);
    Product p4= newProduct("pOmada d chemch",43.43,2);
    addProduct(&pl,p1);
    addProduct(&pl,p2);
    addProduct(&pl,p3);
    addProduct(&pl,p4);
    // removeProductByCode(&pl,PROD_CODE_START+2);
    // printProductList(pl);
    sortProductListByName(&pl,true);
    // printShortenProductList(pl);
    printLowQuantityProducts(pl);

    // while (true)
    // {
    //     Menu(); //  call the menu 
    //     sleep(REFRESH_DELAY);
    // }
    return 0;
}

