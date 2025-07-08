/*
    문제 : N * M 개의 수가 N * N 크기의 표에 채워져 있다면 , 표의 인수 중 X1, Y1에서 X2, Y2까지의 합을 구하려 한다.
            X , Y는 각각 행과 열을 의미함
    입력 : 1번째 줄 : 표의 크기 N , 구하는 횟수 M
            N번째 줄 : 표에 채워져 있는 수가 1행부터 차례대로 주어짐
            M개의 줄 : 4개의 정수 X1, Y1 , X2 , Y2가 주어짐 
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N , M;

    cin >> N >> M;

    vector<vector<int>>arr(N+1, vector<int>(N+1 ,0));
    vector<vector<int>>sum(N+1, vector<int>(N+1 ,0));

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j]; // 대각선의 구간합 구하는 공식
        }
    }
    
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    for(int i  = 0 ; i < M ; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        cout << result << endl;
    }
    return 0;
}