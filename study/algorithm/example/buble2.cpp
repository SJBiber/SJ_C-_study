/*
    버블 정렬 : 두 인접한 데이터의 크기를 비교해 정렬하는 방법
    시간복잡도 : N^2
    방법
    1. 비교 연산이 필요한 루프 범위를 설정
    2. 인접한 데이터 값을 비교
    3. swap 조건에 부합하면 swap 연산
    4. 루프 점위가 끝날때 까지 1~3을 반복
    5. 정렬된 영영을 설정 , 다음 루프를 실행할 때는 이 영역을 제외
    6. 비교 대상이 없을때까지 1~5 반복

    문제 : 버블 정렬 프로그램 (백준 : 골드2 1377번)
    입력 : 1번째 줄 수의 개수 , 2번째부터 N번째 줄까지 수
    출력 : 버블 정렬의 swap이 한번도 일어나지 않는 루프가 언제인지 찾는 프로그램

    * 슈도 코드 *
    N(정렬할 수 개수)
    A(수 저장 배열)
    for(N만큼 반복){
        배열 A 저장
    }
    배열 A 정렬
    for(N만큼 반복) {
        배열 데이터(A[i]) 정렬 전 index - 정렬  후 index 계산 값의 최댓값을 찾아 계산
    }

    최댓값 + 1을 정답으로 출력
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    int Max = 0 ;
    cin >> N;

    vector<pair<int,int>>A;
    for(int i = 0 ; i < N ; i ++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(),A.end());

    for(int i= 0; i < N ; i ++)
    {
        if(Max < A[i].second - i)
        {
            Max = A[i].second - i;
        }
    }
    cout << Max+1;
    return 0 ;

}