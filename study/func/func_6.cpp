// 여러개의 함수를 인덱스 처럼 관리해서 호출하기
// 1. 각 함수의 매개변수의 타입은 다를수있음 
//  -> void 형태로 받은 후 타입캐스팅으로 각 맞는 구조체로 변환
// 2. 각 함수의 리턴값은 int로 동일하게 설정
//  -> 나중에 해당 함수의 성공 여부를 리턴 받고싶어서 설정
// 3. 정의된 함수의 개수를 출력
// 4. ENUM 값으로 인덱스에 해당하는 함수 배열의 함수가 동작할수있도록 설정
// 5. 추후 다른 함수에서 구조체 데이터를 void형으로 받은 후에 처리할수있도록 시험 진행
//  -> 각각 구조체 선언 후 void *로 추상화 하고 함수 동작
// * 각 함수에서 void* 형태로 인자를 받지만 해당 동작에 맞는 타입으로 타입캐스팅 필요함!!!
#include <iostream>

using namespace std;

// 각 함수 IDX 값을 ENUM으로 선언
enum function_number
{
    FUNC_ADD = 0,
    FUNC_STRING = 1,
};

// int 형을 저장할 구조체
struct numberlist
{
    int number ;
};

// string 형을 저장할 구조체
struct stringlist
{
    char name[4];
};

// 함수 배열을 typedef으로 선언 , 리턴 형태는 (int) , 매개 인자 타입은 (void*)
typedef int(*FuncPtr)(void*);

// int 형 구조체가 동작할 함수
int func1(void* arg)
{
    // data에 void* arg를 numberlist* 형태로 타입 캐스팅
    auto* data  = static_cast<numberlist*>(arg);
    return data->number+1;
}

// string 형 구조체가 동작할 함수
int func2(void * arg)
{
    // data에 void* arg를 stringlist* 형태로 타입 캐스팅
    auto* data  = static_cast<stringlist*>(arg);
    cout << data->name << endl;
    return 1;
}

// arr 함수 배열에 동작할 함수 선언
FuncPtr arr[] = {func1 , func2};

int main()
{   
    numberlist test1 = {5};
    stringlist test2 = {"ABC"};
    
    cout << "Function Count : "<< sizeof(arr)/sizeof(arr[0]) << endl;

    cout << arr[FUNC_ADD]   ((void*)&test1) << endl;
    cout << arr[FUNC_STRING]((void*)&test2) << endl;

    return 0;
}