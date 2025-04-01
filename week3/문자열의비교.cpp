#include<cstdio>    // C 스타일 입출력을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력을 위한 헤더 파일
#include<cstring>   // 문자열 처리를 위한 헤더 파일
#include<string>    // C++ string 클래스 사용을 위한 헤더 파일
#include<algorithm> // 알고리즘 관련 함수(min) 사용을 위한 헤더 파일

using namespace std;

const int MAX_LENGTH = 100000;  // 최대 문자열 길이 설정

// 클래스 MyString선언
class MyString{

// 멤버 변수는 클래스 내부에서만 접근 가능 (캡슐화)
private:
    char *characters;   // 문자열을 저장할 동적 배열
    int length; // 문자열 길이 저장

// 클래스 외부에서도 접근 가능
public:
    // 생성자: const char* 타입 문자열을 입력받아 객체 초기화
    MyString(const char * str)
    {   
        this->length = strnlen(str, MAX_LENGTH);    // char 배열 타입이라 strnlen함수로 으로 최대 검사할 길이를 설정
        this->characters = new char[this -> length];    // 길이만큼 동적 할당한다.
        for (int i=0; i<this->length; i+=1)
        {
            this->characters[i] = str[i];   // 문자열 복사
        }
    }

    // 생성자: string 타입 문자열을 입력받아 객체 초기화
    MyString(const string & original)
    {   
        this->length = original.length();   // 문자열 길이를 저장, string 타입이라 .length() 사용 가능능
        this->characters = new char[this -> length];    // 길이만큼 동적 할당
        for (int i=0; i<this->length; i+=1)
        {
            this->characters[i] = original[i];  // 문자열 복사
        }
    }

    // 소멸자: 동적 할당된 메모리 해제
    ~MyString()
    {
        delete[]characters;
    }

    // 연산자 오버로딩: "<" (사전순 비교)
    // 리턴타입 operator 연산자(매개변수) const{}형태이다.
    bool operator < (const MyString & o) const{
        // algorithm헤더에 포함된 min함수 사용
        int n = min (this->length, o.length);   // 연산자 기준 좌, 우 중 작은 문자열 길이를 n에 저장
        // 이제 n만큼 for문으로 배열 인덱스별 아스키코드 비교를 한다.
        for (int i=0; i<n; i++){
            if(this->characters[i] < o.characters[i]) {
                return true;
            }else if(this->characters[i] > o.characters[i]){
                return false;
            }
        }
        // 앞부분이 같다면 길이로 비교
        // < 연산자에 맞게 오른쪽이 더 길면 true로 리턴, 아니면 false
        if (this->length <o.length) {
            return true;
        }else{
            return false;
        }
    } 

    // 연산자 오버로딩: ">" (사전순 비교 반대 방향)
    bool operator > (const MyString & o) const{
        int n = min (this->length, o.length);   // 연산자 기준 좌, 우 중 작은 문자열 길이를 n에 저장
        // 이제 n만큼 for문으로 배열 인덱스별 아스키코드 비교를 한다.
        for (int i=0; i<n; i++){
            if(this->characters[i] < o.characters[i]) {
                return false;
            }else if(this->characters[i] > o.characters[i]){
                return true;
            }
        }
        // 앞부분이 같다면 길이로 비교
        // > 연산자에 맞게 왼쪽이 더 길면 true로 리턴, 아니면 false
        if (this->length > o.length) {
            return true;
        }else{
            return false;
        }
    } 

    // 연산자 오버로딩: "==" (문자열이 같은지 비교)
    bool operator == (const MyString & o) const{
        // this와 o의 길이가 다르면 false를 반환 
        if (this->length != o.length)
            return false;
        // 이제 길이가 같다면, 문자가 전부 같은지 비교 
        for (int i=0; i < this->length; i++){
            if (this->characters[i] != o.characters[i]){
                return false;   
            }
        }
        // 만약 길이도 같고 문자도 다 동일하면 true반환환
        return true;
    } 
};


// 메인함수
int main(){
    // 문자열 두개 선언
    string s1;
    string s2;
    cin >> s1 >> s2;    // 두 개의 문자열 입력, 추출연산자 사용

    // 입력 받은 문자열로 MyString 객체 생성
    MyString mys1(s1); 
    MyString mys2(s2);

    if (mys1 < mys2){   // s1이 사전순으로 앞선 경우
        printf("-1");
    }
    else if(mys1 > mys2){   // s1이 사전순으로 뒤에 있는 경우
        printf("1");    
    }
    else{   // 두 문자열이 같은 경우
        printf("0");
    }
    
    return 0;
    
}   