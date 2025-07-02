#include <iostream>
#include <string>   //string 관련 라이브러리

using namespace std;

#define DOUBLE_LINE cout << "===============================" << endl;
#define ONE_LINE    cout << "-------------------------------" << endl;

int main ()
{
    string  STR_NAME        = "My Name is BSJ";
    string  APPEN_STR       = {0x00,};
    char    APPEN_TEXT[16]  = {0x00,};

    DOUBLE_LINE
    // APPEN 할 Input 값 받기
    cout << "Input Append Text = ";
    cin.getline(APPEN_TEXT , 16); // 16자리 까지 입력값을 받는것 X 맨끝에는 '\0'(NULL 종료 문자)로 들어감

    ONE_LINE
    // APPEN 전 STR 데이터 출력
    cout << "STR = " << STR_NAME << endl;
    cout << "STR_LEN = " << STR_NAME.length() << endl;

    APPEN_STR = APPEN_TEXT; // char 형을 string 형으로 변환
    ONE_LINE
    // APPEN 후 STR 데이터 출력
    STR_NAME.append(APPEN_STR);
    cout << "APPEND_STR = " << STR_NAME << endl;
    cout << "APPEND_STR_LEN = " << STR_NAME.length() << endl;
    DOUBLE_LINE

}