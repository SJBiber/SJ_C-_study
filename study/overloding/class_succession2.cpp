#include <iostream>
// overloding의 디렉토리에 있는 time 관련 함수를 불러옴
#include "time.h"

using namespace std;

const int MAX = 3;

int main()
{
    Time* times[MAX];
    int day;
    int hours;
    int mins;
    int check;
    
    for(int i = 0; i < MAX ; i++)
    {
        cout << i+1 << "번쨰 원소를 정의합니다." << endl;
        cout << "시간을 입력하세요 : " ;
        cin >> hours;
        cout << endl;

        cout << "분을 입력하세요 : " ;
        cin >> mins;
        cout << endl;

        cout << "일 정보가 있다면 1 , 없다면 0을 입력하세요 : " ;
        cin >> check;
        cout << endl;

        if(check == 0)
        {
            times[i] = new Time(hours,mins);
        }
        else{
            cout << "일을 입력하세요 : " ;
            cin >> day;
            cout << endl;
            times[i] = new NewTime(hours,mins, day);
        }
    }

    for(int i = 0 ; i < MAX ; i ++)
    {
        cout << i+1 << "번쨰 정보입니다." << endl;
        times[i]->show();
    }

    for(int i = 0 ; i < MAX ; i ++)
    {
        delete times[i];
    }
    return 0;
}
