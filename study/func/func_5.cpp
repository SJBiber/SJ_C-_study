#include <iostream>

using namespace std;

struct num_list
{
    int flag;
    int num1;
    int num2;
};

void looping (num_list &numbers)
{
    if(numbers.flag > 0)
    {
        numbers.flag --;
        cout << numbers.flag << " || "<< numbers.num1++ << " || " << numbers.num2-- << endl;
        looping(numbers);
    }
}

int main()
{   
    num_list a[1] = {{5,9,5}};

    looping(a[0]);

    return 0;
}