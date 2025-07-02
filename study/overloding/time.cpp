#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time day1(1,30);
    Time day2(2,54);

    day1.show();
    day2.show();

    Time total;
    total = day1.sum(day2);

    Time total2;
    
    total2 = day1 + day2;
    // total2 = day1.operator+(day2); 와 같은 동작을 함

    Time total3;
    total3 = day1.operator+(day2);

    total.show();
    total2.show();
    total3.show();

    // C++ fruend
    //이항 연산자 : 두 개의 피연산자를 요구하는 연산자
    // operator*
    Time o_t1(1,20);
    Time o_t2;

    o_t2 = 3 * o_t1;
    o_t2.show();

    o_t2 = operator*(3,o_t1);
    //o_t2.show();

    cout << o_t2;
    return 0;

}