#include <unistd.h>
#include <stdbool.h>

#define REFRESH_DELAY 2


int main(int argc, char const *argv[])
{
    while (true)
    {
        Menu(); //  call the menu 
        sleep(REFRESH_DELAY);
    }
    return 0;
}

