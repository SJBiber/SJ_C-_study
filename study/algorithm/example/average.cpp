/*
    설명 : 평균을 조작하는 프로그램 작성 , 자기 점수의 최댓값 M을 고른 후 , 점수 / M * 100로 고친 후 
            새롭게 변경된 점수들의 평균을 구함
    입력 : 1번쨰 줄은 과목의 개수 N(1 <= N <= 1000), 2번째 줄에는 과목들의 성적이 M (0 <= M <= 100)
    결과 : 2번쨰 줄에서 받은 모든 숫자의 합을 구한다.
*/
#include<iostream>

using namespace std;

int main()
{
    int target;     //성적 점수를 받을 target
    int N;          //과목의 개수
    long Max = 0;    //과목들 중 최댓 값
    long sum = 0;    //평균을 구할 과목의 총합
    int M[1000];

    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> M[i];
    }

    for(int i = 0 ; i < N ; i ++)
    {
        if(M[i] > Max) Max = M[i];
        sum += M[i];
    }
    double result = sum * 100.0 / Max / N;
    cout << result << endl;

}

