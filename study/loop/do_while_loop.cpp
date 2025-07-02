#include <iostream>

using namespace std;

int main()
{
    bool    flag = true;
    int     number = 0;

    do {
        cout << "do start \n";
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
    while (flag);

    return 0;
}