#include<stdio.h>   // C 스타일 입출력 사용을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력 사용을 위한 헤더 파일

using namespace std;

// m과 같은 값이 있는 인덱스 찾는 함수
int findIndex(int data[], int n, int m){
    int index = -1; // 초기값을 -1로 설정 (찾지 못한 경우 -1)

    // 배열을 순회하면서 m과 같은 값을 찾음
    for(int i=0; i<n; i++){
        if(data[i]==m){
            // 만약 m과 같은 값 찾으면 index를 업데이트
            index = i;
        }
    }
    // index 반환
    return index;
}

int main(){
    int n, m;   // n은 배열크기, m은 찾고자 하는 값
    int *data;  // 동적 할당할 정수형 배열 포인터

    // scanf로 n과 m값 입력받기기
    scanf("%d %d", &n, &m);

    // 동적 메모리 할당
    data = new int[n];

    // 배열 원소 입력받기기
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }
    // findIndex함수 호출해서 answer변수에 저장
    int answer = findIndex(data, n, m);
    printf("%d\n", answer);
    // 동적 메모리 해제제
    delete[] data;

    return 0;
}