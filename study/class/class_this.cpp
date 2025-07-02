#include <iostream>
#include "class.h"

using namespace std;

int main ()
{   
    Stock s1("A",1,10);
    Stock s2("B",2,100);

    s1.show();
    s2.show();

    cout << "A와 B중 share_val이 큰 객체는 \n";
    s1.topval(s2).show();
    return 0;
}