#include <iostream>
#include "time.h"

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

    Time total3;
    total3 = day1.operator+(day2);

    total.show();
    total2.show();
    total3.show();

}