#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "../headers/product.h"

#define NOT_FOUND -404


typedef struct 
{
    Product *elements;
    int length;
}ProductList;

ProductList newProductList();

void addProduct(ProductList*,Product);

// returns product index in the product list if found
// otherwise returns NOT_FOUND 
int findProductByCode(ProductList,unsigned int);

// print Product with the same quantity
void findProductsByQuantity(ProductList,unsigned int);
// return SUCCESS if product removed otherwise returns NOT_FOUND 
int removeProductByCode(ProductList*,int);

//returns sorted ProductList by Name asc or desc
void sortProductListByName(ProductList*,bool);

//returns sorted ProductList by Price asc or desc
void sortProductListByPrice(ProductList*,bool);

//returns sorted ProductList by code asc or desc
void sortProductListByCode(ProductList*,bool);

//prints product list
void printProductList(ProductList);
// print product list name,price price ttc
void printShortenProductList(ProductList);

void printLowQuantityProducts(ProductList);

unsigned int getCurrentCode(ProductList);
#endif