/*
문제 : 주몽의 명령 (백준 실버 4 1940번)
입력 : 갑옷은 2개의 재료로 만드는데 2가지 재료의 고유한 번호를 합침
       재료의 개수 N , 갑옷의 최종 번호 M , N개의 재료들이 가진 고유 넘버 X
출력 : 고유 넘버 X를 합하여 M이 되는 개수를 출력하시오.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N; 
    int M;
    cin >> N;
    cin >> M;

    vector<int>A(N,0);

    for(int i = 0; i < N; i ++)
    {
        cin >> A[i];
    }
    
    int i = 0;
    int j = N-1;
    int count = 0;

    sort(A.begin(),A.end());

    while(i < j)
    {
        if(A[i] + A[j] < M)
        {
            i++;
        }
        else if(A[i] + A[j] > M)
        {
            j--;
        }
        else
        {
            count++;
            i++;
            j--;
        }
    }
    cout << count << endl;



}



