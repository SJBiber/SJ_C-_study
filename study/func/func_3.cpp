#include <iostream>

using namespace std;


void forloop(int number[] , int n)
{
    for(int i ; i < n ; i++)
    {
        number[i] ++;
        cout << "number : "<< number[i] << endl;
    }
}

int whileloop(int number[] , int n)
{
    int a = 0;
    int i = 0;
    while(i < n)
    {
        cout << number[i] << endl; 
        i++;
    }
    a = 1;
    return a;
}

int main()
{
    int num[5] = {1,7,8,9,5};
    int ret = 0;

    forloop(num , 5);    
    cout << "forloop END num : "<< num << endl;

    ret = whileloop(num , 5);    
    cout << "whileloop END ret : "<< ret << endl;

    return 0;
}