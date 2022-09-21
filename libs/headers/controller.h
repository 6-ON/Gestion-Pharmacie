#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "product_list.h"
#include "purchase.h"

ProductList getProductsData();
PurchaseList getRecordsData();
void writeData(ProductList*,PurchaseList*);
#endif