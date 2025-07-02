#include <iostream>
#include "class.h"

int main()
{
    cout << "생성자를 이용하여 temp 객체 생성 \n";
    Stock temp = Stock("win" , 200 , 2000);

    cout << "디폴트 객체 생성\n";
    Stock temp2;

    cout << "temp 를 temp2 에 대입 \n";
    temp2 = temp;

    cout << "temp 와 temp2 출력 \n";
    temp.show();
    temp2.show();

    cout << "생성자를 이용하여 tmep 내용 재설정\n";
    temp = Stock("lose" , 300 ,1000);

    cout << "재설정된 temp 출력 \n";
    temp.show();

    return 0;
}