/*
백터란 ?
 - vector는 c++ 표준 라이브러리에 있는 자료주고 컨테이너중 하나로 , 사용자가 손쉽게 사용하기 위해 정의도니 클래스
 - 배열의 특징을 가지며 배열의 단점을 보완한 동적 배열의 형태라고 보면 된다!
특징
 - 동적으로 원소를 추가할 수 있음 , 즉 크기가 자동으로 늘어남
 - 맨 마지막 위치에 데이터를 삽입하거나 삭제할 떄는 문제가 없지만 중간 데이터의 삽입/삭제는 배열과 겉은 메커니즘으로 동작한다
 - 배열과 마찬가지로 인덱스를 이용하여 각 데이터에 접근한다.
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int target = 0;
    vector<int> A;

    for(int i = 0 ; i < 10 ; i++ )
    {
        cout << "A[" << i << "] " << "숫자를 입력하시오 : ";
        cin >> target;
        A.push_back(target); //배열의 마지막에 추가함 , 동적으로 크기가 늘어남
    }
    cout << "A의 크기 (메모리 단위): " << sizeof(A) << endl;
    cout << "A의 원소 개수: " << A.size() << endl;
    
    cout << "입력한 숫자들: ";
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    A.pop_back(); // 마지막 값 삭제
    A.erase(A.begin()+2); // index 2에 해당하는 값 삭제
    
    cout << "처리한 숫자들: ";
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}