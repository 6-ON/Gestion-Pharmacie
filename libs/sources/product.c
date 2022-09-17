#include "../headers/product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TTC 15

// private functions declarations

// returns priceTTC
double getPriceTTC(double);

Product newProduct(char *_name, double _price, unsigned int _inital_quantity)
{
    int _priceTTC = getPriceTTC(_price);
    Product p = {code : 1, name : NULL, price : _price, priceTTC : _priceTTC, quantity : _inital_quantity};
    p.name = calloc(strlen(_name) + 1, sizeof(char)); // alocate memory for the name
    strcpy(p.name, _name);                            // copy it
    return p;
}

void printProduct(Product p)
{
    printf("---PRODUIT---\n"
           "Code %d\n"
           "LABEL %s\n"
           "Prix %.2lf\n"
           "Prix TTC: %.2lf\n"
           "Quantité: %d\n",
           p.code, p.name, p.price, p.priceTTC, p.quantity);
}

void printProductTable(Product p)
{
    printf(
        "|| %d "
        "|| %s "
        "|| %.2lf "
        "|| %.2lf "
        "|| %d ||",
        p.code, p.name, p.price, p.priceTTC, p.quantity);
}

void copyProduct(Product *_dest, Product _src)
{
    _dest->code = _src.code;
    _dest->price = _src.price;
    _dest->priceTTC = _src.priceTTC;
    _dest->quantity = _src.quantity;
    int _src_name_len = strlen(_src.name);
    (_dest->name != NULL) ? realloc(_dest->name, _src_name_len) : calloc(_src_name_len + 1, sizeof(char));
}

bool hasLowQuantity(Product p)
{
    return p.quantity > 3;
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





double getPriceTTC(double _price) { return _price + (double)TTC * _price / (double)100; }