#include <iostream>
#include <string>   //string 관련 라이브러리

using namespace std;

#define DOUBLE_LINE cout << "===============================" << endl;
#define ONE_LINE    cout << "-------------------------------" << endl;

int main ()
{
    string  STR_NAME        = "My Name is BSJ";
    string  INSERT_STR      = {0x00,};
    string  FIND_STR        = {0x00,};
    char    INSERT_TEXT[16] = {0x00,};
    char    FIND_TEXT[16]   = {0x00,};
    
    // FIND 할 Input 값 받기
    cout << "STR_NAME = " << STR_NAME << endl;

    cout << "STR_NAME에서 찾고싶은 단어를 입력하시오 = ";
    cin.getline(FIND_TEXT, 16);

    // 만약 해당 TEXT에 중복된 단어가 있다면 가장 먼저 찾은 위치가 pos 값이 됨
    size_t  pos = STR_NAME.find(FIND_TEXT);
    cout << "찾은 위치값은 [" << pos << "] 입니다~" << endl;
    // INSERT 후 STR 데이터 출력
    if  (pos < 0 || pos > STR_NAME.length())
    { 
        cout << "STR_NAME 값 범위에 맞지 않은 값이므로 PASS" << endl;
    }
    else
    { 
        DOUBLE_LINE
        // INSERT 할 Input 값 받기
        cout << "Input INSERT Text = ";
        cin.getline(INSERT_TEXT , 16); // 16자리 까지 입력값을 받는것 X 맨끝에는 '\0'(NULL 종료 문자)로 들어감

        ONE_LINE
        // INSERT 전 STR 데이터 출력
        cout << "STR = " << STR_NAME << endl;
        cout << "STR_LEN = " << STR_NAME.length() << endl;

        INSERT_STR = INSERT_TEXT; // char 형을 string 형으로 변환
        STR_NAME.insert(pos,INSERT_STR); 
        ONE_LINE
        cout << "INSERT_STR = " << STR_NAME << endl;
        cout << "INSERT_STR_LEN = " << STR_NAME.length() << endl;
        ONE_LINE
        // 찾은 위치가 INSERT 된 STR의 위치가 되고 , INSERT한 STR 길이 만큼 추출함
        cout << "추출한 부분 = " << STR_NAME.substr(pos , INSERT_STR.length()) <<endl;
        DOUBLE_LINE
        
    }
    return 0;
}