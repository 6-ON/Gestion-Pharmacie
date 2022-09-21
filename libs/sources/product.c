#include "../headers/product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TTC 0.15

extern unsigned int currentprodCode;
// private functions declarations

// returns priceTTC
double getPriceTTC(double);
Product newProduct(char *_name, double _price, unsigned int _inital_quantity)
{
    int _priceTTC = getPriceTTC(_price);
    Product p = {code : currentprodCode++, name : NULL, price : _price, priceTTC : _priceTTC, quantity : _inital_quantity};
    p.name = calloc(strlen(_name) + 1, sizeof(char)); // alocate memory for the name
    strcpy(p.name, _name);                            // copy it
    return p;
}
Product initProduct(unsigned int _code ,char *_name, double _price, unsigned int _inital_quantity)
{
    Product p = {code : _code, name : NULL, price : _price, priceTTC : getPriceTTC(_price), quantity : _inital_quantity};
    p.name = calloc(strlen(_name) + 1, sizeof(char)); // alocate memory for the name
    strcpy(p.name, _name);                            // copy it
    return p;
}

void printProduct(Product p)
{
    printf("---PRODUIT---\n"
           "Code %d\n"
           "NOM %s\n"
           "Prix %.2lf\n"
           "Prix TTC: %.2lf\n"
           "Quantité: %d\n",
           p.code, p.name, p.price, p.priceTTC, p.quantity);
}

void printProductTable(Product p)
{
    printf(
        "||  %d  "
        "| %s\t"
        "| %.2lf\t"
        "| %.2lf\t"
        "| %d\t||\n",
        p.code, p.name, p.price, p.priceTTC, p.quantity);
}

void printShortenProductTable(Product p)
{
    printf(
        "| %s\t"
        "| %.2lf\t"
        "| %.2lf\t||\n",
        p.name, p.price, p.priceTTC);
}

void copyProduct(Product *_dest, Product _src)
{
    _dest->code = _src.code;
    _dest->price = _src.price;
    _dest->priceTTC = _src.priceTTC;
    _dest->quantity = _src.quantity;
    int _src_name_sz = strlen(_src.name)+1;
    // allocate or reallocate  name attr if NULL
    _dest->name = (_dest->name != NULL) ? realloc(_dest->name, _src_name_sz*sizeof(char)) : calloc(_src_name_sz, sizeof(char));
    strcpy(_dest->name,_src.name); //copy the name
}

void swapProducts(Product *p1,Product *p2){
    Product temp={name:NULL};
    copyProduct(&temp,*p1);
    copyProduct(p1,*p2);
    copyProduct(p2,temp);

}

bool hasLowQuantity(Product p)
{
    return p.quantity < 3;
}

bool compareProducts(Product p1, Product p2)
{
    return p1.code == p2.code;
}

void updatePrice(Product *p, double _newPrice)
{
    if (_newPrice < 0)
        return;
    p->price = _newPrice;
    p->priceTTC = getPriceTTC(_newPrice);
}

void addQuantity(Product *p, unsigned int _quantity)
{
    if (_quantity <= 0)
        return;
    p->quantity += _quantity;
}

int consumeQuanitity(Product *p, unsigned int _quantity)
{
    if (p->quantity < _quantity)
        return ERR_NO_ENOU_QTTY;
    else
    {
        p->quantity -= _quantity;
        if (p->quantity < 3)
            return W_LOW_QTTY;
        else
            return SUCCESS;
        
    }
}





double getPriceTTC(double _price) { return _price + _price*TTC; }