#include <iostream>

using namespace std;

int sum (int , int);
float sum (float , float);

int sum (int a, int b)
{
    return a+b;
}

float sum (float a, float b)
{
    return a+b;
}


int main()
{
    int x , y;
    float w, t;
    cout << "원하는 x의 수를 입력 하세요 .\n";
    cin >> x;
    cout << "원하는 y의 수를 입력 하세요 .\n";
    cin >> y;
    cout << "int sum : " << sum(x,y) << endl;

    cout << "원하는 w의 수를 입력 하세요 .\n";
    cin >> w;
    cout << "원하는 t의 수를 입력 하세요 .\n";
    cin >> t;
    cout << "float sum : " << sum(w,t) << endl;

    return 0;
}