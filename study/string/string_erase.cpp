#include <iostream>
#include <string>   //string 관련 라이브러리

using namespace std;

#define DOUBLE_LINE cout << "===============================" << endl;
#define ONE_LINE    cout << "-------------------------------" << endl;

int main ()
{
    string  STR_NAME        = "My Name is BSJ";
    string  ERASE_STR      = {0x00,};
    string  FIND_STR        = {0x00,};
    char    ERASE_TEXT[16] = {0x00,};
    char    FIND_TEXT[16]   = {0x00,};
    
    // FIND 할 Input 값 받기
    cout << "STR_NAME = " << STR_NAME << endl;
    cout << "STR_NAME에서 삭제할할 단어를 입력하시오 = ";
    cin.getline(FIND_TEXT, 16);
    FIND_STR = FIND_TEXT;
    
    // 만약 해당 TEXT에 중복된 단어가 있다면 가장 먼저 찾은 위치가 pos 값이 됨
    size_t  pos = STR_NAME.find(FIND_TEXT);
    cout << "찾은 위치값은 [" << pos << "] 입니다~" << endl;
    // ERASE 후 STR 데이터 출력
    if  (pos < 0 || pos > STR_NAME.length())
    { 
        cout << "STR_NAME 값 범위에 맞지 않은 값이므로 PASS" << endl;
    }
    else
    { 
        DOUBLE_LINE
        // ERASE 전 STR 데이터 출력
        cout << "STR = " << STR_NAME << endl;
        cout << "STR_LEN = " << STR_NAME.length() << endl;

        // ERASE(int 삭제할 위치 값 , 삭제할 길이(ex. is를 삭제하려면 2를 넣어준다))
        STR_NAME.erase(pos,FIND_STR.length()); 
        ONE_LINE
        cout << "ERASE_STR = " << STR_NAME << endl;
        cout << "ERASE_STR_LEN = " << STR_NAME.length() << endl;
        DOUBLE_LINE
    }
    return 0;
}