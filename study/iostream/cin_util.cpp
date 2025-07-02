#include <iostream>

using namespace std;

#define DOUBLE_LINE cout << "================================" << endl;

int main ()
{
    char name[16];      // 이름 값을 받을 Char 변수
    char text[100];     // Text 값을 받을 Char 변수
    int age = 0;        // 나이 값을 받을 int 변수

    cout << "이름을 입력하시오 :";
    cin.getline(name , 16);
    cout << "이름 : " << name << endl;

    cout << "나이를 입력하시오 :";
    cin >> age;

    cout << "나이 :" << age << endl;
    cin.ignore(1000, '\n');

    cout << "부가설명을 입력하시오 :";
    cin.getline(text , 100);

    cout << "설명 :" << text << endl;

    cin.ignore(1000, '\n');

    DOUBLE_LINE
    cout << "input list" << endl;
    cout << name << endl;
    cout << age << endl;
    cout << text << endl;
    DOUBLE_LINE

    return 0;
}