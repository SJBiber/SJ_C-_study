#include <iostream>
#include <iomanip>

using namespace std;

#define DOUBLE_LINE cout << "================================" << endl;

int main ()
{
    DOUBLE_LINE
    cout << "OutPut list" << endl;
    cout << "정수 :" << 42 << endl;
    cout << "10진수 :" << hex << 42 << endl;
    cout << "8진수 :" << oct << 42 << endl;

    cout << fixed << setprecision(2);  // 고정 소수점

    cout << "소수 출력 : " << 3.141592 << endl;

    cout << fixed << setprecision(4);  // 고정 소수점
    cout << "소수 출력 : " << 3.141592 << endl;

    cout << setw(10) << setfill('*') << right << "END" << endl;

    cout << boolalpha << (5 > 3) << endl;
    cout << noboolalpha << (5 > 3) << endl;
    DOUBLE_LINE

    return 0;
}