#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdbool.h>

#define SUCCESS 200 
#define W_LOW_QTTY 300 
#define ERR_NO_ENOU_QTTY 401 

typedef struct 
{
   int code;
   char *name;
   double price;
   double priceTTC;
   unsigned int quantity;
}Product;

// initialize new product
Product newProduct(char*,double,unsigned int);

// print the product
void printProduct(Product);

//print pro
void printProductTable(Product);

// copy a product in another one
void copyProduct(Product*,Product);

// compare two products code PS:(compare only id)
bool compareProducts(Product,Product);

// update price 
void updatePrice(Product*,double);

// returns true if the quantity is under 3
bool hasLowQuantity(Product);

// updates Quantity
void addQuantity(Product*,unsigned int);

// consume quantity 
// retuns SUCCESS if the quantity is consumed and left more than 3
// retuns W_LOW_QTTY if the quantity is consumed and left less than 3
// retuns W_LOW_QTTY if the quantity is consumed and left less than 3
int consumeQuanitity(Product*,unsigned int);

#endif 