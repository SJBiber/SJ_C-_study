#include <iostream>
#include "class.h"

int main()
{
    Stock temp;
    temp.acquire("win" , 100 , 1000);
    temp.show();
    temp.buy(10,1200);
    temp.show();
    temp.sell(5,900);
    temp.show();
    
    return 0;
}