/*
    구간합 : 배열을 이용하여 시간 복잡도를 더 줄이기 위해 사용하는 특수한 목적의 알고리즘
        - 활용하기 위해 합 배열을 구해야함!
    문제 : 수 N 개가 주어졌을 때 i번째 수에서 j번째 수까지의 합을 구하는 프로그램을 작성!
    입력 : 1번째 줄에 개수 N(1 <= N <= 100000 ), 합을 구해야하는 횟수 M(1 <= M <= 100000), 
           2번째 줄에 N개의 수 arr[]( 0 <= arr[] <= 1000)
           3번째 줄에 M개의 줄의 합을 구하는 구간 i , j
*/

#include <iostream>

using namespace std;

int main()
{
    int N , M ;                 //수의 개수 , 합하는 동작의 횟수
    int range_start ,range_end; //합을 구하는 구간 , 처음과 끝
    int sum[100001] = {};       //구간합을 담을 sum 배열
    int number;                 //수를 받을 number

    cin >> N >> M ;

    for( int i = 1; i <= N ; i++)
    {
        cin >> number;
        sum[i] = sum[i-1] + number;
    }

    for( int i = 0 ; i < M ; i++)
    {
        cin >> range_start >> range_end;
        cout << sum[range_end] - sum[range_start-1] << endl;
    }
    return 0;
}