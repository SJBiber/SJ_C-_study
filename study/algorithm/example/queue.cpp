/*
 큐 : 선입 선출
 문제 : 카드게임
 설명 : N장의 카드가 있다 , 각각 카드는 차례대로 N이 가장 밑  , 1이 가장 위에 올려져 있다.
        먼저 가장 위의 카드를 버린다 , 그다음 가장 위카드를 가장 밑으로 넣는다. 다음 동작을 반복해서
        마지막에 남는 숫자를 출력하라.
 입력 : 카드의 개수 N
 출력 : 마지막에 남는 카드의 숫자 출력
*/
#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int result;
    queue<int>A;
    for(int i = 1 ; i <= N ; i++)
    {
        A.push(i);
    }

    while(A.size() > 1)
    {
        cout << A.back() << ' ' << A.front() << endl;
        A.pop();            //처음엔 버리고
        A.push(A.front());  //그다음엔 맨밑으로 넣고
        A.pop();            //버리고    
    }

    cout << A.front() ; 

}