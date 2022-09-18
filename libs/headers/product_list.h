#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "../headers/product.h"

#define NOT_FOUND -404

extern unsigned int currentprodCode;

typedef struct 
{
    Product *elements;
    int length;
}ProductList;

ProductList newProductList();

void addProduct(ProductList*,Product);

// returns product index in the product list if found
// otherwise returns NOT_FOUND 
int findProductByCode(ProductList,int);

int removeProductByCode(ProductList*,int);

//returns sorted ProductList by Name asc or desc
void sortProductListByName(ProductList*,bool);

//returns sorted ProductList by Price asc or desc
void sortProductListByPrice(ProductList*,bool);


void printProductList(ProductList);

void printShortenProductList(ProductList pl);

void printLowQuantityProducts(ProductList pl);

#endif