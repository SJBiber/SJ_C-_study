#include <iostream>

using namespace std;

int main()
{
    bool    flag = true;
    int     number = 0;

    while (flag)
    {
        number++;
        cout << "number = " << number << endl;
        if(number == 5)
        {
            cout << "END" << endl;
            //flag = false;
            // or
            break;
        }
    }

    return 0;
}