#include "headers/product.h"

double getPriceTTC(double);

double getPriceTTC(double _price){
    return _price + (double)15*_price/(double)100;
}

Product newProduct(char* _name,double _price,unsigned int _inital_quantity){
    int _priceTTC=getPriceTTC(_price);
    Product p={.code:1,.price:_price,.priceTTC:_priceTTC,.quantity:_inital_quantity};

    return p;
}