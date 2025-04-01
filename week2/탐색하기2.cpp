#include<stdio.h>   // C 스타일 입출력 사용을 위한 헤더 파일
#include<string>    // C++ string 클래스를 사용하기 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력 사용을 위한 헤더 파일

using namespace std;

// AJOU가 등장하는 첫번째 인덱스와 마지막 인덱스스를 출력하는 함수
void printIndexes(string school[], int n){
    int first = -1;     // AJOU 처음 등장한 위치 저장 변수 (초기값: -1)
    int last = -1;      // AJOU 마지막으로 등장한 위치 저장 변수 (초기값: -1)
    
    // 배열 순회하며 AJOU 문자열 위치 찾음
    for (int i=0; i<n; i++)
    {   
        // 해당 인덱스값이 AJOU와 일치하는 경우 
        if(school[i]=="AJOU"){
            // first는 1번만 입력하도록 설정
            if(first==-1){
                // 배열인덱스는 0부터 n-1까지니까 i+1인 값을 first에 대입시킨다. 
                first=i+1;
            }
            // last는 계속 갱신되도록 설정
            last=i+1;
        }
    }
    // first와 last 값 출력
    printf("%d %d\n", first, last);
}

int main(){
    int n;  // 배열의 크기 n
    char buff[11];  // 문자열을 임시 저장할 버퍼 (최대 길이 10글자 + NULL 문자)
    string* school; // 동적 할당할 문자열 배열의 포인터

    // scanf로 n값 입력받기
    scanf("%d", &n);
    // 동적 메모리 할당
    school = new string[n];

    // 사용자로부터 문자열 입력 받기
    for (int i=0; i<n; i++)
    {
        scanf("%s", buff);  // buff에 문자열 임시로 받고고
        school[i] = buff;   // string 객체에 저장
    }

    // printIndexes함수 실행
    printIndexes(school, n);
    // 동적 메모리 해제
    delete[] school;

    return 0;
}