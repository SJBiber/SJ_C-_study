/*
    삽입 정렬 : 이미 정렬된 데이터 범위에 정렬되지않은 데이터를 적절한 위치에 삽입해 정렬하는 방식
    시간 복잡도 : N^2
    방법
    1. 현재 index에 있는 데이터 값을 선택
    2. 현재 선택한 데이터가 정렬된 데이터 범위에 삽입될 위치를 탐색
    3. 삽입 위치부터 index에 있는 위치까지 shift 연산 수행
    4. 삽입 위치에 현재 선택한 데이터를 삽입하고 index ++ 연산 수행
    5. 전체 데이터의 크기만큼 index가 커질 때까지 , 즉 선택할 데이터가 없을때까지 반복
    * 적절한 삽입 위치를 탐색하는 부분에서 이진 탐색 등과 같은 탐색 알고리즘을 사용하면 시간 복잡도를 줄일수 있음

    문제 : ATM 인출시간 계산하기
    줄을 서있는 사람의 수 N 과 각 사람이 돈을 일출하는데 걸리는 시간 P[i]가 주어졌을때 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 구현하시오
    입력 : 1번째 줄에 사람의 수 N , 2번째 줄에 각 사람이 돈을 인출하는데 걸리는 시간 P[i]
    출력 : 모든 사람이 돈을 뽑는데 걸리는 최소시간
    *슈도 코드*
    N(사람의 수)
    A(자릿수 별로 구분하여 저장한 배열)
    S(합배열 A -> 각 사라믜 인출 완료를 위해 필요한 시간을 저장)

    for(N만큼 반복){
        배열 A 저장
    }

    for(i를 N만큼 반복){
        for(j를 i-1~0까지 뒤에서 부터 반복){
            현재 범위에서 삽입 위치 찾기
        }

        for(j를 i ~ insert_point + 1 까지 뒤에서 부터 반복){
            삽입을 위해 삽입 위치부터 i까지 데이터를 한칸씩 뒤로 밀기
        }

        삽입 위치에서 현재 데이터 삽입하기
    }
    for(N만큼 반복){
        배열 A를 통한 합 배열 S 만들기
    }
    배열 S 각 데이터의 값을 모두 합하여 결과 출력
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N ;
    cin >> N;
    vector<int>A(N,0);
    vector<int>S(N,0);
    
    for(int i = 0 ; i < N ; i ++)
    {
        cin >> A[i];
    }
#if 0
    for(int i = 0 ; i < N ; i ++)
    {
        int insert_point = i;
        int insert_value = A[i];
        for(int j = i-1 ; j >=0 ; j --)
        {
            if(A[j] < A[i])
            {
                insert_point = j+1;
                break;
            }
            if(j == 0)
            {
                insert_point = 0;
            }
        }
        for(int j = i; j > insert_point ; j--)
        {
            A[j] = A[j-1];
        }
        A[insert_point] = insert_value;
    }
#else // 다른 방법

    for(int i = 1 ; i < N ; i++)
    {
        int insert_value = A[i];
        int j = i-1;

        while(j>=0 && A[j] > insert_value)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = insert_value;
    }

#endif
    
    S[0] = A[0];
    int sum = S[0];
    for(int i = 1 ; i < N ; i ++)
    {
        S[i] = A[i] + S[i-1];
        sum = sum + S[i];
    }

    cout << sum ;


}