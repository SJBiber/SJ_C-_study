#include <iostream>
#include <string>   //string 관련 라이브러리

using namespace std;

#define DOUBLE_LINE cout << "===============================" << endl;
#define ONE_LINE    cout << "-------------------------------" << endl;

int main ()
{

    string STR_NAME = "My Name is BSJ";
    string INPUT_TEXT;
    char TEXT[16] = {0x00,};

    DOUBLE_LINE
    // TEXT Input 값 받기
    cout << "Text = " ;    
    cin.getline(TEXT , 16); // 16자리 까지 입력값을 받는것 X 
                            // 맨끝에는 '\0'(NULL 종료 문자)로 들어감

    ONE_LINE
    cout << "STR = " << STR_NAME << endl;
    cout << "STR_LEN = " << STR_NAME.length() << endl;
    cout << "STR_EMPTY = " << STR_NAME.empty() << endl; 

    INPUT_TEXT = TEXT;      // char 형을 string 형으로 변환
    ONE_LINE
    cout << "INPUT_TEXT = " << INPUT_TEXT << endl;
    cout << "INPUT_TEXT_LEN = " << INPUT_TEXT.length() << endl;
    cout << "INPUT_TEXT_EMPTY = " << INPUT_TEXT.empty() << endl; 
    DOUBLE_LINE

}