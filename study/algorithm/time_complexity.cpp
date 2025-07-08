#include <iostream>

using namespace std;

#define MAX 10

int binarySearch(int arr[] , int size , int target , int & count)
{
    int left = 0;
    int right = size-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        count ++;
    }
    return -1;
}

int Search()
{
    int arr[] = {1,3,5,6,7,21,30,40,50,64,70,75,93,100,102,120,140}; // 17개 log 17 => 약 4, 최대 4번만 반복
    int size = sizeof(arr) / sizeof(arr[0]);    // 배열의 총 개수
    int count = 0;  // 반복할때 증가하는 count 정의

    int target;     // 찾고 싶은 숫자 정의
    cout << "찾고싶은 숫자를 입력하시오 . ";
    cin >> target;

    // 이진 탐색 함수 동작 , 배열 , 배열 총 개수 , 찾을 수 , 반복횟수 | 반환 값 : 찾은 수가 있는 배열 인덱스
    int result = binarySearch(arr ,size ,target ,count);

    if(result == -1)
    {
        cout << "숫자 " << target << "는 배열에 없습니다." << endl;
    }
    else{
        cout << "숫자 " << target << "는 인덱스 " << result << "에 있으며 총 반혹 횟수는 " << count << "입니다." << endl;
    }
    return 0;
}
 

int main()
{

    for( int i= 0 ; i < MAX ; i++ )
    {
        cout << "O(n) 반복 횟수 : " << i << endl; 
    }

    
    for( int i= 0 ; i < MAX ; i++ )
    {
        for( int j = 0 ; j < MAX ; j++ )
        {
            cout << "O(n^2) 반복 횟수 : " << i << " | " << j << endl;
        }
         
    }
    
    // log (n) 반복 하기 위한 함수 정의
    Search();

    return 0;

}