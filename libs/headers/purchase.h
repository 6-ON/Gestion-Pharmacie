#ifndef PURCHASE_H
#define PURCHASE_H

#include <time.h>
#include "product.h"

typedef struct
{
    struct tm pr_time;
    double price;
    unsigned int codePrd;
} Purchase;

typedef struct
{
    Purchase *elements;
    int length;
} PurchaseList;

// create new purchase
Purchase newPurchase(Product,unsigned int);

//init Purchase with custom time
Purchase initPurchase(unsigned int,double,unsigned int ,unsigned int,unsigned int,unsigned int);

// create new purchase List
PurchaseList newPurchaselist();

// Print purchase
void printPurchase(Purchase);


// add purchase to the record list
void recordPurchase(PurchaseList *, Purchase);

// print t max mix avg of today
void printTodayBrief(PurchaseList);

// save records in a log file
void saveRecords();

#endif