#include <iostream>

using namespace std;

template <class Any>
Any sum(Any , Any);

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
    cout << "flaot sum : " << sum(w,t) << endl;
    
    return 0;
}

template <class Any>
Any sum(Any a, Any b)
{
    return a + b;
}