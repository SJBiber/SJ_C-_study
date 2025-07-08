/*
    설명 : N개의 수가 주어졌을 때 연속된 부분의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성
    입력 : 1번쨰 줄은 N과 M , 2번째 줄에는 숫자 N개가 주어짐
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N , M;
    int number;
    int remainer = 0;
    int result = 0;
    cin >> N >> M;

    vector<long>S(N , 0);
    vector<long>C(M , 0);

    for(int i = 1; i < N ; i++ )
    {
        cin >> number;
        S[i] = S[i-1] + number; 
    }

    for(int i = 0; i < N ; i ++)
    {
        remainer = S[i] % M;
        if(remainer == 0) result++;
        C[remainer]++;
        
    }

    for(int i = 0; i < M ; i ++)
    {
        if(C[i] > 1)
        {
            result = result + (( C[i] * (C[i] - 1)) / 2);
        }
    }
    cout << result << endl;
    return 0;
}