#include "../headers/product_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ProductList newProductList()
{
    ProductList pl = {elements : NULL, length : 0};
    return pl;
}

void printProductList(ProductList pl)
{
    for (int i = 0; i < 85; i++)
        putchar('_');
    printf("\n||\tCode\t|\tNOM\t|\tPRIX\t|\tPRIX TTC\t| QUANTITY ||\n");
    for (int i = 0; i < 85; i++)
        putchar('-');
    putchar('\n');
    for (int i = 0; i < pl.length; i++)
    {
        printProductTable(pl.elements[i]);
    }
}

void printShortenProductList(ProductList pl)
{
    for (int i = 0; i < 85; i++)
        putchar('_');
    printf("\n||\tNOM\t|\tPRIX\t|\tPRIX TTC\t||\n");
    for (int i = 0; i < 85; i++)
        putchar('-');
    putchar('\n');
    for (int i = 0; i < pl.length; i++)
    {
        printShortenProductTable(pl.elements[i]);
    }
}

void printLowQuantityProducts(ProductList pl){
    for (int i = 0; i < pl.length; i++)
    {
        Product _current = pl.elements[i];
        if (hasLowQuantity(_current))
        {
            printProductTable(_current);
        }
        
    }
    
}

void addProduct(ProductList *pl, Product prod)
{
    if (pl->elements == NULL)
        pl->elements = calloc(++pl->length, sizeof(Product));
    else
        pl->elements = realloc(pl->elements, ++pl->length * sizeof(Product));

    pl->elements[pl->length - 1]=prod;
}

int findProductByCode(ProductList pl, int _code)
{
    for (int i = 0; i < pl.length; i++)
    {
        if (pl.elements[i].code == _code)
            return i;
    }
    return NOT_FOUND;
}

void removeProductAt(ProductList *pl, int _index)
{
    if (_index < 0 || _index > pl->length)
        return;
    else
    {
        // shift all the elements 1 step to left
        for (int i = _index; i < pl->length - 1; i++)
        {
            copyProduct(pl->elements + i, pl->elements[i + 1]);
        }
        // remove last by realocating the allocated memory
        pl->elements = realloc(pl->elements, --pl->length * sizeof(Product));
    }
}

int removeProductByCode(ProductList *pl, int _code)
{
    int _index = findProductByCode(*pl, _code);
    if (_index == NOT_FOUND)
        return NOT_FOUND;
    else
    {
        removeProductAt(pl, _index);
        return SUCCESS;
    }
}

void sortProductListByPrice(ProductList *pl, bool is_asc)
{

    for (int i = 0; i < pl->length - 1; i++)
    {
        for (int j = i + 1; j < pl->length; j++)
        {
            bool sortCondition = pl->elements[i].price > pl->elements[j].price;
            if (sortCondition && is_asc) // check sort condition and asc or desc
            {
                swapProducts(pl->elements + i, pl->elements + j);
            }
            else if (!sortCondition && !is_asc)
            {
                swapProducts(pl->elements + i, pl->elements + j);
            }
        }
    }
}

void sortProductListByName(ProductList *pl, bool is_asc)
{

    for (int i = 0; i < pl->length - 1; i++)
    {
        for (int j = i + 1; j < pl->length; j++)
        {
            bool sortCondition = strcasecmp(pl->elements[i].name , pl->elements[j].name) > 0;
            if (sortCondition && is_asc) // check sort condition and asc or desc
            {
                swapProducts(pl->elements + i, pl->elements + j);
            }
            else if (!sortCondition && !is_asc)
            {
                swapProducts(pl->elements + i, pl->elements + j);
            }
        }
    }
}




