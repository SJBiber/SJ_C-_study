#include <iostream>
#include "class.h"

using namespace std;

int main ()
{   
    Stock s[5] = {
        Stock("A",1,10)  ,
        Stock("B",2,100) ,
        Stock("C",3,20) ,
        Stock("D",4,760) ,
        Stock("F",1,250)
    };
    Stock first = s[0];
    for (int i = 0 ; i < 5 ; i++)
    {
        s[i].show();
        first = first.topval(s[i]);
    }
    
    cout << "가장 큰 값은 다음과 같습니다. \n   ";
    first.show();

    return 0;
}