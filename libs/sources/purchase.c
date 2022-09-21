#include "../headers/purchase.h"
#include <stdio.h>
#include <stdlib.h>
Purchase newPurchase(Product prd)
{
    time_t curr_time = time(NULL);
    struct tm curr_time_info = *localtime(&curr_time);
    Purchase pur = {pr_time : curr_time_info, price : prd.priceTTC, codePrd : prd.code};
    return pur;
    //should i free the adress of curr_time_info  ?
}

void printPurchase(Purchase pur)
{
    printf("%d %lf %s \n", asctime(&pur.pr_time));
}

PurchaseList newPurchaselist()
{
    PurchaseList purl = {elements : NULL, length : 0};
    return purl;
}

void recordPurchase(PurchaseList *purl, Purchase p)
{
    purl->elements = (purl->elements == NULL) ? calloc(++purl->length, sizeof(Purchase)) : realloc(purl->elements, ++purl->length * sizeof(Purchase));
    purl->elements[purl->length] = p;
}
void printTodayBrief(PurchaseList purl)
{
    time_t curr_time =time(NULL);
    struct tm curr_time_info = *localtime(&curr_time);

    for (int i = 0; i < purl.length; i++)
    {
        Purchase p = purl.elements[i];
        if (curr_time_info.tm_year == p.pr_time.tm_year)
        {
            if (curr_time_info.tm_yday == p.pr_time.tm_yday)
            {
                printPurchase(p);
            }
            
        }
        
    }
    //should i free the adress of curr_time_info  ?
}