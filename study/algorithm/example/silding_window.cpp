/*
문제 : DNS 비밀번호 ( 백준 실버 5 , 12891번 )
DNS 문자열은 모든 문자열에 등장하는 문자가 {'A' , 'C' , 'G' , 'T'}인 문자열이며
각각 몇번 이상 등장해야 비밀번호로 사용할 수 있는지 , 순서대로 주어졌을때 민호가 만들수 있는 비밀 번호의 종료의 수를 구하는
프로그램을 작성하시오.
입력 : DNS 문자열의 길이 S , 부분 문자열의 길이 P , DNS 문자열 A , 부분 문자열에 포함되어야 할 checkArr 배열

* 슈도 코드 *
checkArr(비밀번호 체크 배열)
myArr(현재 상태의 배열)
checkSecret(몇 개의 문자에 대한 개수를 충족했는지 판단하는 변수)
S(문자열의 크기) , P(부분 문자열의 크기)
A(문자열 데이터)

for(i를 P에서 S 까지 반복)
{
    j 선언(i-P)
    Add(A[i])
    Remove(A[j])
    현재 부분 문자열이 유효한 비밀번호인지(checkSecret == 4) 판단하여 결괏값 업데이트    
}
결과값 출력

Add(문자 더하기 함수)
{
    새로 들어온 문자에 대해 myArr업데이트 및 checkSecret 값 변경
}

Remove(문자 빼기 함수)
{
    제거되는 문자에 대해 myArr 업데이트 및 checkSecret 값 변경
}

*/

#include<iostream>

using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main()
{
    int S = 0;
    int P = 0;
    int count = 0;
    string A;
    
    cin >> S >> P;
    cin >> A;

    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> checkArr[i];
        if(checkArr[i] == 0)
        {
            checkSecret++;
        }
    }

    for(int i = 0 ; i < P ; i++)
    {
        Add(A[i]);
    }
    if(checkSecret == 4)
    {
        count++;
    }

    for(int i = P ; i < S ; i++)
    {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);

        if(checkSecret == 4)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

void Add(char c)
{
    switch (c)
    {
        case 'A':
            myArr[0]++;
            if(myArr[0] == checkArr[0])
            {
                checkSecret++;
            }
            break;
        case 'C':
            myArr[1]++;
            if(myArr[1] == checkArr[1])
            {
                checkSecret++;
            }
            break;
        case 'G':
            myArr[2]++;
            if(myArr[2] == checkArr[2])
            {
                checkSecret++;
            }
            break;
        case 'T':
            myArr[3]++;
            if(myArr[3] == checkArr[3])
            {
                checkSecret++;
            }
        break;
    }
}

void Remove(char c)
{
    switch (c)
    {
        case 'A':
            if(myArr[0] == checkArr[0])
            {
                checkSecret--;
            }
            myArr[0]--;
        break;
        case 'C':
            if(myArr[1] == checkArr[1])
            {
                checkSecret--;
            }
            myArr[1]--;
        break;
        case 'G':
            if(myArr[2] == checkArr[2])
            {
                checkSecret--;
            }
            myArr[2]--;
        break;
        case 'T':
            if(myArr[3] == checkArr[3])
            {
                checkSecret--;
            }
            myArr[3]--;
        break;
    }
}

