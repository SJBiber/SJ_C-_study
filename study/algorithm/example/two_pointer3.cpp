/*
문제 : 좋은 수 구하기 (백준 골드 4 1253번)
 주어진 N 개의 수에서 다른 두 수의 합으로 표현되는 수가 있다면 그 수를 '좋은 수' 라고 한다 . N개의 수 중 좋은 수가 총 몇개인지 출력
입력 : 수의 개수 N , N개의 수의 값
출력 : 좋은 수 의 개수 출력
* 슈도 코드 *
N(배열의 데이터 개수)
A(데이터 저장 배열)

for(N 만큼 반복){
    배열 A에 데이터 저장
}
배열 A 오름차순 정렬

for(N 만큼 반복){
    변수 초기화(찾고자 하는 값 find = A[k] , 시작 지점 포인터 i , 종료 지점 포인터 j)
    while(i < j)
    {
        if(A[i] + A[j] == find)
        {
            if( i != k && j != k) count ++ 후 종료
            else if( i == k ) i 증가 반복
            else if( j == k ) j 감소 반복
        }
        else if(A[i] + A[j] < find) { i 증가 }
        else { j 감소 }
    }
}
좋은 수 개수 출력
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A (N , 0);

    for(int i = 0 ; i < N ; i ++)
    {
        cin >> A[i];
    }

    int count = 0;
    sort(A.begin(),A.end());

    for(int k = 0 ; k < N ; k ++)
    {   
        long find = A[k];
        int i = 0;
        int j = N-1;
        while( i < j )
        {
            if(A[i] + A[j] == find)
            {
                if(i != k && j != k)
                {
                    count ++;
                    break;
                }
                else if( i == k ) i++;
                else if( j == k ) j--;
            }
            else if(A[i] + A[j] < find)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    cout << "좋은 수의 개수 : " << count << endl;
}
