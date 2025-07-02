#include <iostream>

using namespace std;


void forloop(int &number)
{
    for(int i ; i < 5 ; i++)
    {
        number ++;
        cout << "number : "<< number << endl;
    }
}

int whileloop(int &number)
{
    int a = 0;

    while(number)
    {
        number --;
    }
    a = 1;
    return a;
}

int main()
{
    int num = 0;
    int ret = 0;
    forloop(num);
    
    cout << "forloop END num : "<< num << endl;

    ret = whileloop(num);
    
    cout << "whileloop END ret : "<< ret << endl;

    return 0;
}