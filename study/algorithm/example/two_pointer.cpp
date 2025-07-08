/*
투 포인터 : 2개의 포인터를 사용하여 알고리즘의 시간 복잡도를 최적화
 -> 배열이나 리스트에서 두 개의 포인터르 이용하여 효율적으로 탐색하는 알고리즘 기법!
보통 정렬된 배열 또는 연속된 구간(부분합, 구간 내 조건 탐색)을 처리할때 사용

문제 : 연솓된 자연수의 합 구하기 (백준 실버5  2018번)
 어떠한 자연수 N은 몇개의 연속된 자연수의 합으로 나타낼 수 있다. 
 , N을 몇개의 연속된 자연수의 합으로 나타내는 가짓수를 알고싶다.
ex)  N = 15 라면 : 15 , 7+8 , 4+5+6 , 1+2+3+4+5 
     N = 10 이면 : 10 , 1+2+3+4
*/

#include<iostream>

using namespace std;

int main()
{
    int N = 0;
    int start_idx   = 1; // 시작 포인터 값
    int end_idx     = 1; // 종료 포인터 값
    int find_idx  = 1;   // 찾은 개수 , N이 포함되어 1부터 시작
    int sum  = 1;
    cin >> N;

    while(end_idx != N)             // 종료 idx와 최종합 N이 같아질때까지 반복
    {
        if(sum == N)                // 만약 sum이 최종합 N과 같다면
        {
            find_idx ++;            // 찾은 개수 증가
            end_idx ++;             // 종료 idx 증가
            sum = sum + end_idx;    // 종료 idx와 현재까지의 sum을 더함
        }
        else if(sum > N)            // 만약 sum이 최종합 N보다 크면 
        {   
            sum = sum - start_idx;  // sum에서 시작 idx을 뺌
            start_idx ++;           // 시작 idx 증가
        }
        else                        // 만약 sum이 최종합 N보다 작으면 
        {
            end_idx++;              // 종료 idx 증가
            sum = sum + end_idx;    // sum에서 증가된 종료 idx 더함
        }

    }



}

