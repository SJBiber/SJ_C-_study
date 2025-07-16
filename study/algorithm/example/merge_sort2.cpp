/*
    병합 정렬 : 분할 정복 방식을 사용해 데이터를 분할하고 분할한 집합을 정렬하며 합치는 아록리즘
    시간복잡도 : nlogn
    *숙지사항 : 투포인터!

    문제 : 버블 정렬 프로그램2 (백준 플레티넘 1517번)
    버블 정렬을 수행할때 swap이 총 몇번 발생하는지 알아내는 프로그램을 구현
    입력 : 1번째 줄에 수의 개수 N , 2번째 줄부터 N개의 줄에 숫자가 주어짐 (1<= N <= 500000) 시간복잡도 N^2이면 상당한 시간 걸리므로 사용 X
    출력 : 1번째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 1줄에 1개씩 출력
    * 슈도 코드 *
    N(수의 개수)
    A(정렬할 배열)
    tmp(정렬시 잠시 사용할 임시 배열 선언)

    for(N만큼 반복){
        배열 A 저장
    }

    병합 정렬 함수 실행
    결괏값 출력

    //함수
    병합 정렬(s,e){
        s(시작점) ,e(종료점),m(중간점)
        //재귀 함수 형태
        병합 정렬(s,m)
        병합 정렬(m+1, e)

        for(s~e)
        {
            임시 배열 tmp 저장
        }
        index1 -> 앞쪽 그룹 시작점
        index2 -> 뒷쪽 그룹 시작점

        while(index1 <= 중간점 && index2 <= 종료점)
        {
            양쪽 그룹의 index가 가리키는 값을 비교하여 더 작은 수를 선택하여 배열에 저장하고
            선택된 데이터의 index값을 한 칸 오른쪽으로 이동함
            이때 뒤쪽 데이터 값이 더 작아지는 경우
            swap이 일어났다고 판단하여 현재 남아있는 앞쪽 데이터 개수 만큼 결과값에 더함
        }
        반복문이 끝난 후 남은 데이터 정리
    }
*/
#include<iostream>
#include<vector>

using namespace std;

void merge_sort(int s , int e);
static vector<int>A;
static vector<int>tmp;
static long count;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N ;
    cin >> N;
    A = vector<int>(N+1,0);
    tmp = vector<int>(N+1,0);
    count = 0;
    for(int i = 1 ; i <= N ; i ++)
    {
        cin >> A[i];
    }    
    
    merge_sort(1,N);
    
    cout<<"===================================\n";
    
    cout<<count;
    
    return 0;
}

void merge_sort(int s , int e)
{
    if(e-s < 1) return;
    int mid = s+(e-s)/2;

    merge_sort(s,mid);
    merge_sort(mid+1,e);

    for(int i = s ; i <= e ; i++)
    {
        tmp[i] = A[i];
    }
    int k = s;
    int index1 = s;
    int index2 = mid+1;

    while(index1 <= mid && index2 <= e)
    {
        if(tmp[index1] > tmp[index2])
        {
            A[k] = tmp[index2];
            k++;
            index2++;
            count = count + index2 - k; 
        }
        else
        {
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }
    while(index1 <= mid)
    {
        A[k] = tmp[index1];
        k++;
        index1++;
    }
    while(index2 <= e)
    {
        A[k] = tmp[index2];
        k++;
        index2++;
    }
}