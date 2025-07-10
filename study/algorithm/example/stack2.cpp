/*
 문제 : 오큰수 구하기 (백준 골드 4 17298번)
 입력 : 1번째 줄 수열 N의 크기
        2번째 줄 수열 A의 원소
 출력 : 각각 A[i]의 오큰수들을 나열
 오큰수 : 오른쪽에 있으면서 A[i]보다 크고 가장 왼쪽에 있는 수
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int>A(N,0);
    vector<int>result(N,0);

    stack<int>myStack;
    for(int i = 0; i < N ; i ++)
    {
        cin >> A[i];
    }

    myStack.push(0);
    for(int i = 1; i < N ; i++)
    {
        int number = A[i];
        while(myStack.size() > 0 && A[myStack.top()] < A[i])
        {
            result[myStack.top()] = number;
            myStack.pop();
        }
        myStack.push(i);
    }

    while(myStack.size() > 0)
    {
        result[myStack.top()] = -1;
        myStack.pop();
    }

    for(int i = 0 ; i < N ; i++)
    {
        cout << result[i] << " ";
    }


}
