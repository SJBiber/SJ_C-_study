/*
    퀵정렬 : 기준값을 선정해 해당 값보다 작은 데이터와 큰 데이터로 분류하는것을 반복해 정렬하는 알고리즘
    시간복잡도 : 기준값을 어떻게 선정하는지가 nlogn 이 될수있고 최악의 경우 N^2가 될수 있음
    
    방법
    1. 데이터를 분할하는 pivot을 설정한다.
    2. pivot을 기준으로 다음 a~e과정을 거쳐 데-이터를 2개의 집합으로 분리
        a. start가 가리키는 데이터가 pivot이 가리키는 데이터보다 작으면 start를 오른쪽으로 1칸 이동한다.
        b. end가 가리키는 데이터가 pivot이 가리키는 데이터보다 크면 end를 왼쪽으로 1칸 이동한다.
        c. start가 가리키는 데이터가 pivot이 가리키는 데이터보다 크고 , end가 가리키는 데이터가 pivot이 가리키는 데이터보다 작으면 start,end가 기리키는
        데이터를 swap하고 start는 오른쪽 , end는 왼쪽으로 1칸씩 이동한다.
        d. start와 end가 만날때까지 a~c를 반복한다.
        e. start와 end가 만나면 만난 지점에서 가리키는 데이터와 pivot이 가리키는 데이터를 비교하여 pivot이 가리키는 데이터가 크면 만난 지점의 오른쪽에,
        작으면 왼쪽에 pivot이 가리키는 데이터를 삽입한다.
    3. 분리 집합에서 각각 다시 pivot을 설정한다.
    4. 분리 집합이 1개 이하가 될때까지 과정 1~3을 반복한다.

    문제 : K번쨰 수 구하기 (백준 실버 5 11004번)
    A를 오름차순 정렬했을 때 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오
    입력 : 1번째 줄 N ~번째 K, 2번째 줄에 A1 ~ AN
    출력 : A를 정렬했을 때 K번째 있는 수를 출력

    * 슈도 코드 *
    N(숫자의 개수) , K(K번째 수)
    A(숫자 데이터 저장 배열)

    for(N만큼 반복){
        배열 A 저장
    }

    퀵 정렬 실행
    K 번째 데이터 출력

    // 함수
    퀵 정렬 함수(시작 , 종료 , K)
    {
        피벗 구하기 함수(시작 , 종료)
        if(피벗 == k) 종료
        else if(K < 피벗) 퀵 정렬 수행(시작 인덱스 , 피벗 -1 , K)
        else 퀵 정렬 수행 (피벗 +1, 종료 인덱스 , K) 
    }

    피벗 구하기 함수(시작 , 종료)
    {
        데이터가 2개인 경우는 바로 비교하여 정렬
        M(중앙 값)
        중앙 값을 시작 위치와 swap
        pivot을 시작 위치 값 A[S] 저장
        i(시작) , j(종료)

        while i <= j:
            피벗보다 큰 수가 나올때 까지 i증가
            피벗보다 작은 수가 나올때 까지 j감소
            찾으 i와 j 데이터를 swap
        피벗 데이터를 나눈 두 그룹의 경계 index에 저장하기
        경계 index 반환
    }
*/
#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int> &A , int S , int E , int K);
int partition(vector<int>&A , int S , int E);
void swap(vector<int>&A , int i , int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;           
    cin >> N >> K ;
    vector<int>A(N,0);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> A[i];
    }

    quickSort(A,0,N-1,K-1); // 퀵 정렬 함수 실행 , 배열 A , 0 = start , N-1 = end , K-1 = 찾고 싶은 위치
    cout << A[K-1];
}

void quickSort(vector<int> &A , int S , int E , int K)
{
    int pivot = partition(A,S,E);   //pivot 구함
    if(pivot == K)                  //pivot과 K의 위치가 같다면 return
    {
        return;
    }
    else if(K < pivot)              //pivot이 K보다 크면
    {
        quickSort(A,S,pivot-1,K);   //end 포인트를 왼쪽으로 한칸 밀음
    }
    else                            // pivot이 K보다 작다면
    {  
        quickSort(A,pivot+1,E,K);   //start 포인트를 오른쪽으로 한칸 밀음
    }

}

int partition(vector<int>&A , int S , int E)
{
    if(S+1 == E)    //start 바로 옆에 end가 있다면
    {
        if(A[S] > A[E])     //start 데이터가 end 데이터보다 크면
        {
            swap(A,S,E);    //start 데이터와 end 데이터 위치 변경
        }
        return E;           //pivot을 end 포인트로 설정
    }

    //start 바로 옆에 end가 없다면
    int M = (S + E) /2 ;    //start와 end의 중간지점을 찾음
    swap(A,S,M);            //start 데이터와 중간지점 데이터를 swap
    int pivot = A[S];       //시작 지점 데이터를 pivot으로 설정
    int i = S+1 , j = E;    // i = start+1 , J는 end

    while(i <= j){          //만약 start+1 이 end 지점보다 작다면 
        while(j>= S+1 && pivot < A[j]) //j가 start 바로 옆지점보다 크고 , pivot이 end지점 데이터보다 작으면 j을 뺌
        {   // pivot이 end 지점 데이터보다 클때까지 반복
            j--;
        }
        while(i<= E && pivot > A[i])  //i가 end 지점보다 작거나 같고 , pivot이 start 지점 데이터보다 크면 i증가
        {   // pivot이 start 지점 데이터보다 작을때까지 반복
            i++;
        }

        if( i < j)                    //만약 i가 j보다 작으면
        {
            swap(A, i++ , j--);       // swap한 후 i++ , j--
        }
        else{
            break;
        }
    }
    A[S] = A[j];        
    A[j] = pivot;
    return j;
} 

void swap(vector<int>&A , int i , int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp ;
}
