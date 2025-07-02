#include <iostream>
#include <string>   //string 관련 라이브러리
#include <cstring>  //strlen , strcat , strcmp , strpcy 등 c에서 사용한 string 관련 라이브러리

using namespace std;

#define DOUBLE_LINE cout << "===============================" << endl;
#define ONE_LINE    cout << "-------------------------------" << endl;

int main ()
{

    string STR_NAME = "My Name is BSJ";
    string INPUT_TEXT;
    char TEXT[16] = {0x00,};
    char COPY_TEXT[16] = {0x00 ,};
    DOUBLE_LINE
    // TEXT Input 값 받기
    cout << "Text = " ;    
    cin.getline(TEXT , 16); // 16자리 까지 입력값을 받는것 X 
                            // 맨끝에는 '\0'(NULL 종료 문자)로 들어감
    ONE_LINE
    cout << "STR = " << STR_NAME << endl;
    cout << "STR_LEN = " << STR_NAME.length() << endl;

    INPUT_TEXT = TEXT;      // char 형을 string 형으로 변환
    ONE_LINE
    cout << "TEXT = " << TEXT << endl;
    cout << "TEXT_LEN = " << strlen(TEXT) << endl;
    ONE_LINE
    cout << "INPUT_TEXT = " << INPUT_TEXT << endl;
    cout << "INPUT_TEXT_LEN = " << INPUT_TEXT.length() << endl;
    ONE_LINE
    cout << "string -> C string" << endl;
    snprintf (COPY_TEXT , sizeof(COPY_TEXT) , "%s", INPUT_TEXT.c_str());
    cout << "C String TEXT = " << COPY_TEXT << endl; 
    cout << "C String TEXT_LEN = " << strlen(COPY_TEXT) << endl; 
    DOUBLE_LINE

}