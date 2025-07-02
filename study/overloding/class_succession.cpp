#include <iostream>

// overloding의 디렉토리에 있는 time 관련 함수를 불러옴
#include "time.h"

int main()
{
    Time temp1(30 , 2);
    NewTime temp2(3,39,2);
    temp1.show();
    temp2.show();
    return 0;
}
