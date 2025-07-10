/*
 스택 : 후입 선출
 문제 : 스택으로 수열 만들기(백준 실버3 1874번)
 입력 : 1번쨰 줄에 수열의 개수 n , 2번째~n번쨰까지 수열의 이루는 수
 출력 : push는 + , pop은 - 로 출력하고 , 불가능한 경우에는 NO를 출력

    * 슈도 코드 *
N(수열의 개수) A[](수열 배열)
수열 배열 채우기
for(N만큼 반복)
{
    if(현재 수열 값 >= 오름차순 자연수) {
        while(값이 같아질 때까지)
        {   
            push()
            (+)저장
        }
        pop()
        (-)저장
    }
    else(현재 수열 값 < 오름차순 자연수){
        pop()
        if(스택 pop 결과값 > 수열의 수) NO 출력
        else (-)저장
    }
}
if(-값을 출력한 적이 없으면) 저장한 값 출력

*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    bool result_idx = true;

    vector<int>A(N,0);
    vector<char>result;
    stack<int>myStack;

    for(int i = 0; i < N ; i ++)
    {
        cin >> A[i];
    }

    int number = 1;

    for(int i = 0; i < N ; i ++)
    {
        int idx = A[i];
        if(idx >= number)
        {
            while(idx >= number)
            {
                myStack.push(number++);
                result.push_back('+');
            }
            myStack.pop();
            result.push_back('-');
        }
        else{
            int n = myStack.top();

            myStack.pop();

            if(n > idx)
            {
                cout << "NO";
                result_idx = false;
                break;
            }
            else
            {
                result.push_back('-');
            }
        }
    }

    if(result_idx)
    {
        for(int i = 0 ; i < result.size() ; i ++)
        {
            cout << result[i] << endl;
        }
    }
    return 0;
}