#include "../headers/purchase.h"
#include <stdio.h>
#include <stdlib.h>

Purchase newPurchase(Product prd, unsigned int qtty)
{
    time_t curr_time = time(NULL);
    struct tm curr_time_info = *localtime(&curr_time);
    Purchase pur = {pr_time : curr_time_info, price : prd.priceTTC * (double)qtty, codePrd : prd.code};
    return pur;
    // should i free the adress of curr_time_info  ?
}
Purchase initPurchase(unsigned int _code, double _price, unsigned int _phour, unsigned int _pmday, unsigned int _pmo, unsigned int _pyear)
{
    struct tm curr_time_info = {.tm_hour = _phour, .tm_mday = _pmday, .tm_mon = _pmo, .tm_year = _pyear};
    Purchase pur = {pr_time : curr_time_info, price : _price, codePrd : _code};
    return pur;
}

void printPurchase(Purchase pur)
{
    // fix asctime not working as epected
    time_t purchase_time_t = mktime(&pur.pr_time);
    struct tm purchase_tm = *localtime(&purchase_time_t);

    printf("code : %d | prixTTC: %.2lf | Date: %s", pur.codePrd, pur.price, asctime(&purchase_tm));
}

PurchaseList newPurchaselist()
{
    PurchaseList purl = {elements : NULL, length : 0};
    return purl;
}

void recordPurchase(PurchaseList *purl, Purchase p)
{
    purl->elements = (purl->elements == NULL) ? calloc(++purl->length, sizeof(Purchase)) : realloc(purl->elements, ++purl->length * sizeof(Purchase));
    purl->elements[purl->length - 1] = p;
}

void printTodayBrief(PurchaseList purl)
{
    time_t curr_time = time(NULL);
    struct tm curr_time_info = *localtime(&curr_time);
    double sum = 0, min, max, count = 0;
    bool first_match = true;
    for (int i = 0; i < purl.length; i++)
    {
        Purchase p = purl.elements[i];
        if (curr_time_info.tm_year == p.pr_time.tm_year)
        {
            if (curr_time_info.tm_mon == p.pr_time.tm_mon)
            {
                if (curr_time_info.tm_mday == p.pr_time.tm_mday)
                {
                    if (first_match)
                    {
                        min = p.price;
                        max = p.price;
                    }
                    else
                    {
                        min = (min > p.price) ? p.price : min;
                        max = (max < p.price) ? p.price : max;
                    }

                    printPurchase(p);
                    count++;
                    sum += p.price;
                }
            }
        }
    }
    printf("\nSOM : %.2lf | MAX : %.2lf | MIN : %.2lf | MOY : %.2lf\n",
           sum, max, min, sum / count);
}