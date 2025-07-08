/*
    설명 : N개의 숫자가 공백 없이 쓰여 있는데 , 이 숫자를 모두 합해 출력하는 프로그램 작성
    입력 : 1번쨰 줄은 숫자의 개수 N(1 <= N <= 100), 2번째 줄에는 숫자 N개가 공백없이 주어짐
    결과 : 2번쨰 줄에서 받은 모든 숫자의 합을 구한다.
*/
#include<iostream>

using namespace std;

int main()
{
    int N;              // 1번째줄의 N개
    string  numbers;    // 2번쨰줄의 숫자를 string 형태로 받아옴
    cin >> N;
    cin >> numbers;

    int sum = 0;            // 결과 값을 받을 sum

    for( int i = 0; i < numbers.length(); i++ ) //string에서 받은 number의 총길이가 숫자의 총 개수가 됨
    {
        sum+=numbers[i] - '0';  //numbers에 들어가는 수는 아스키 코드 값이므로 숫자의 시작값인 '0'의 값을 빼주어 정수를 구함
    }

    cout << sum << endl;
}