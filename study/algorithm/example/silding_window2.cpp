/*
문제 : 최솟값 찾기 ( 백준 플레티넘 , 11003번)
N개의 수 와 L이 주어진다 A[i-L+]~A[i]중 최솟값을 D[i]라고 할때 D에 저장된 수를 출력하는 프로그램을 작성하시오
입력 : 수 N , 슬라이딩 윈도우 크기 L , N개의 수 A 배열

* 슈도 코드 *
N(데이터 개수)
L(최솟값을 구하는 범위)
Node 타입 선언 (int , int)
deque<Node> mydeque(데이터를 담을 덱 자료구조)

for(N만큼 반복)
{
    now(현재 데이터)
    덱의 마지막 위치에서부터 now보다 큰값은 덱에서 제거
    덱의 마지막 위치에 now 값 저장
    덱의 첫 번째 위치에서 부터 L의 범위를 벗어난 값(now index -L <= index)을 덱에서 제거
    덱의 첫번쨰 데이터 출력
}
*/

#include<iostream>  // 입출력
#include<deque>     // deque 자료 구조 사용

using namespace std;

typedef pair<int, int> Node;    //Node라는 타입 이름을 pair<int ,int>의 별칭으로 정의   
                                //Node는 두 개의 int를 묶은 자료형 (value , index로 사용됨)

int main()
{
    int N = 0;
    int L = 0;

    cin >> N >> L;

    deque<Node> mydeque;

    for(int i = 0; i < N ; i++)
    {
        int now;
        cin >> now;

        //mydeque의 현재 사이즈 및 mydeque의 맨뒤 Node 값의 value를 now랑 비교
        while(mydeque.size() && mydeque.back().first > now) 
        {
            //참이면 맨뒤 Node 값 제거
            mydeque.pop_back();
        }

        //맨뒤에 now값을 value , i 값을 index로 큐에 삽입
        mydeque.push_back(Node(now,i));

        //mydeque의 맨앞 index값을 i-L의 범위에 있는지 비교
        if(mydeque.front().second <= i-L)
        {
            //index가 i-L의 범위가 아닐시 맨앞 Node 데이터 제거
            mydeque.pop_front();
        }

        // 맨앞 Node의 value 값 출력
        cout << mydeque.front().first << ' ';

    }
}
