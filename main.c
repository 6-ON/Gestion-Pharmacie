#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "libs/headers/menu.h"
#include "libs/headers/controller.h"
#define REFRESH_DELAY 2
#define PROD_CODE_START 1000000000

ProductList pl;
PurchaseList purl;
unsigned int currentprodCode;

int main(int argc, char const *argv[])
{

    pl = getProductsData();
    //get records here
    purl = getRecordsData();

    currentprodCode = (pl.length > 0) ? getCurrentCode(pl) : PROD_CODE_START;


    while (true)
    {
        Menu(); //  call the menu
        sleep(REFRESH_DELAY);
    }
    return 0;
}
