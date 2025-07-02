#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // new 연산자
    /*
    어떤 데이터형을 원하는지 new 연산자에게 알려주면
    new 연산자는 그에 알맞은 크기의 메모리 블록을 찾아내고 그 블록의 주소를 리턴
    */ 
    int     a;
    int*    b = &a;

    int*    pointer = new int;

    cout << a <<  endl;
    cout << &b << endl;

    cout << &a << endl;
    cout << b << endl;

    cout << pointer << endl;
    cout << &pointer << endl;

    delete pointer;

    int*    array = new int[3];
    
    array[0] = 3;
    array[1] = 55;
    array[2] = 7;


    cout << setw(8) << array[0] << " || " << &array[0] << endl;
    cout << setw(8) << array[1] << " || " << &array[0]+1 << endl;
    cout << setw(8) << array[2] << " || " << &array[0]+2 << endl;

    delete[] array;

    cout << setw(8) << array[0] << " || " << &array[0] << endl;
    cout << setw(8) << array[1] << " || " << &array[1] << endl;
    cout << setw(8) << array[2] << " || " << &array[2] << endl;

    return 0;
}