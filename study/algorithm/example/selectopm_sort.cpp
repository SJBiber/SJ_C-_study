/*
    선택 정렬 : 데이터에서 최대나 최소 데이터를 나열된 순으로 찾아가며 선택하는 방법
    시간 복잡도 : N^2

    방법
    1. 남은 정렬 부분에서 최솟값 또는 최댓값을 찾는다.
    2. 남은 정렬 부분에서 가장 앞에 있는 데이터와 선택된 데이터를 swap 한다.
    3. 가장 앞에 있는 데이터의 위치를 변경해(index++) 남은 정렬 부분의 범위를 축소시킨다.
    4. 전체 데이터 크기만큼 index가 커질 때까지, 즉 남은 정렬 부분이 없을 때까지 반복한다.

    문제 : 내림차순으로 자릿수 결정하기(백준 실버5 1427번)
    입력 : 1번째 줄에 정렬할 수 N이 주어짐                 ex : 2143
    출력 : 1번째 줄에 자릿수를 내림차순 정렬한 수를 출력    ex : 4321

    *슈도 코드*
    str(정렬할 수)
    A(자릿수별로 구분하여 저장한 배열)

    for(str의 길이만큼 반복)
    {
        배열 A 저장 -> str.substr()사용
    }

    for(i : 0 ~ N)
    {
        for(j : i+1 ~ N)
        {
            현재 범위에서 Max 값 찾기
        }
        현재 i의 값과 Max값 중 Max값이 더 크면 swap 진행
    }
    배열 A 출력
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str;
    int Max = 0;
    cin >> str;

    vector<int>A(str.size(),0);

    for(int i = 0 ; i < str.size() ; i++)
    {
        A[i] = stoi(str.substr(i,1));
    }
    
    for(int i = 0 ; i < str.size() ; i++)
    {
        for(int j = i+1 ; j < str.size() ; j ++)
        {
            if(A[j] > A[Max])   //내림차순으로 최솟값 사용!
            {
                Max = j;
            }
        }

        if(A[i] < A[Max])
        {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for(int i = 0 ; i < str.size(); i ++)
    {
        cout << A[i];
    }
    return 0;
}