#ifndef PRODUCT_H
#define PRODUCT_H

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

// copy a product in another one
void copyProduct(Product*,Product);

// compare two products code PS:(compare only id)
bool compareProducts(Product,Product);

// returns true if the quantity is under 3
bool hasLowQuantity(Product);

// updates Quantity
void updateQuantity(Product*,unsigned int);

// update price
void updatePrice(Product*,double);


#endif 