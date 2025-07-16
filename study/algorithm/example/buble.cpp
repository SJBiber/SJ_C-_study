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
    
    문제 : 수정렬하기 1 (백준 : 브론즈 2750번)
    입력 : 1번째 줄 수의 개수 , 2번째부터 N번째 줄까지 수
    출력 : 1번째 줄부터 N개의 줄에 오름차순으로 숫자 정렬

    * 슈도 코드 *
    N(정렬할 수 개수)
    A(수 저장 배열)
    for(i : 0 ~ N-1) {
        for(j : 0 ~ N-1-i) {
            현재의 배열 A 값 보다 한칸 오른쪽 배열값이 더 작으면 두 수 위치 교체    
        }
    }
    배열 출력
*/



#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    vector<int>A(N,0);
    for(int i = 0 ; i < N ; i ++)
    {
        cin >> A[i];
    }


    for(int i= 0; i < N-1 ; i ++)
    {
        for(int j = 0 ; j < N-1-i ; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < N ; i ++)
    {
        cout << A[i] << '\n';
    }

    return 0 ;

}