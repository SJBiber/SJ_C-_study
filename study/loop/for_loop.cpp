#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int a = 0;
    int b = 0;
    int number = 0;
    cout << a++ << endl;  
    cout << ++b << endl;
    for (int i = 0; i < 5 ; i ++)
    {
        number ++;
        cout << " i = "      << setw(4) << i;
        cout << " || number = " << setw(4) << number << "\n";
    }

    // 1차원 배열
    int test[10] = {1,2,5,7,8};
    for (int i : test)
    {
        cout << i ;
    }

    cout << "\n";
    // 2차원 배열
    int array[5][5] = { {1,2},
                        {4,5},
                        {7,8} };

    for (const auto& row : array)
    {
        for(int val : row)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}