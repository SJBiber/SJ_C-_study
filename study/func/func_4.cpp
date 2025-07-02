#include <iostream>

using namespace std;

struct num_list
{
    int num1;
    int num2;
    int num3;
};


#if 1
/*
    구조체 주소값을 활용한 case
*/
void forloop(num_list &num , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        num.num1 ++;
        num.num2 ++;
        num.num3 ++;
        cout << "number1 : "<< num.num1 << endl;
        cout << "number2 : "<< num.num2 << endl;
        cout << "number3 : "<< num.num3 << endl;
    }
}

int whileloop(num_list &num)
{
    int a = 0;
    int i = 0;
    while(i < sizeof(num)/sizeof(int))
    {
        cout << num.num1++ << endl; 
        cout << num.num2++ << endl; 
        cout << num.num3++ << endl; 
        i++;
    }
    a = 1;
    return a;
}
#else
/*
    구조체 주소값을 활용하지 않은 case
*/
void forloop(num_list num , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        num.num1 ++;
        num.num2 ++;
        num.num3 ++;
        cout << "number1 : "<< num.num1 << endl;
        cout << "number2 : "<< num.num2 << endl;
        cout << "number3 : "<< num.num3 << endl;
    }
}

int whileloop(num_list num)
{
    int a = 0;
    int i = 0;
    while(i < sizeof(num)/sizeof(int))
    {
        cout << num.num1++ << endl; 
        cout << num.num2++ << endl; 
        cout << num.num3++ << endl; 
        i++;
    }
    a = 1;
    return a;
}
#endif
int main()
{   
    num_list a[1] = {0x00 ,};
    int ret = 0;

    forloop(a[0] , 5);    
    cout << "forloop END num1 : "<< a[0].num1 << endl;
    cout << "forloop END num2 : "<< a[0].num2 << endl;
    cout << "forloop END num3 : "<< a[0].num3 << endl;


    ret = whileloop(a[0]);    
    cout << "whileloop END ret : "<< ret << endl;

    return 0;
}