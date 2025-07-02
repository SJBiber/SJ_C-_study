#include <iostream>

using namespace std;

template <class Any>
Any sum(Any , Any);
template <class Any>
Any sum(int , Any);


int main()
{
    int x , y;
    float w, t;
    cout << "원하는 x의 수를 입력 하세요 .\n";
    cin >> x;

    // 해당 라인은 에러
    // 첫번째 Any , Any 에도 매칭이 되고 , 두번째 int , Any에도 매칭이 되기 때문에 에러 발생
    // 컴파일러가 둘중 하나를 못골라서 , 결정장애발생으로 인한 에러!!(넝담~)
    // cout << "int sum : " << sum(x,y) << endl; 

    cout << "원하는 w의 수를 입력 하세요 .\n";
    cin >> w;
    cout << "원하는 t의 수를 입력 하세요 .\n";
    cin >> t;
    cout << "flaot sum : " << sum(w,t) << endl;
    
    cout << "int flaot sum : " << sum(x,t) << endl;
    return 0;
}

template <class Any>
Any sum(Any a, Any b)
{
    return a+b;
}
template <class Any>
Any sum(int a, Any b)
{
    return a+b;
}