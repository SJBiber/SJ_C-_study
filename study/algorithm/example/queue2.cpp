/*
 문제 : 절댓값 힙
 내용 : 배열에 정수 x를 넣고 배열에서 절댓값이 가장 작은 값을 출력한 후 그 값을 배열에서 제거,
        절댓값이 가장 작은 값이 여러개일 경우에는 그중 가장 작은 수를 출력하고 , 그 값을 배열에서 제거한다
 입력 : 1번쨰 줄 개수 N , N번째 줄 , 정수 X
 출력 : 입력에서 0이 주어진 횟수만큼 답을 출력한다 , 만약 배열이 비어있는데 절댓값이 가장 작은 값을 출력하라고 할대는 0을 출력

    * 슈도 코드 *
    N(질의 요청 개수)
    myQue(데이터 저장 우선순위 큐)
    절댓값 기준으로 정렬되도록 설정.
    단 , 절댓값이 같다면 음수 우선 정렬

    for(N만큼 반복)
    {
        요청이 0일때 : 큐가 비어있으면 0 출력 , 아니면 큐의 top을 출력하고 pop;
        요청이 1일때 : 새오룽ㄴ 데이터를 우언순위 큐에 push
    }
*/

#include<iostream>
#include<queue>
using namespace std;

struct compare {
    bool operator()(int o1 , int o2){
        int f_abs = abs(o1);
        int s_abs = abs(o2);
        if(f_abs == s_abs)
        {
            return o1 > o2;
        }
        else
        {
            return f_abs > s_abs;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int request;
    cin >> N;

    priority_queue<int ,vector<int>,compare>myQue;

    for(int i = 0 ; i < N ; i++)
    {
        cin>>request;

        if(request == 0)
        {
            if(myQue.empty())
            {
                cout << "0\n";
            }
            else{
                cout << myQue.top() << '\n';
                myQue.pop();
            }
        }
        else
        {
            myQue.push(request);
        }
    }

    return 0;
}

    


