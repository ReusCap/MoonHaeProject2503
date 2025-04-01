#include<cstdio>    // C 스타일 입출력을 위한 헤더파일
#include<iostream>  // C 스타일 입출력을 위한 헤더파일

using namespace std;

// 특정 달에 태어난 도토리들 중 가장 키가 큰 도토리의 키를 반환하는 함수 
int getMaximumHeight(int height[], int month[], int n, int m){
    int maxHeight=-1; // 생일이 m인 도토리가 없으면 -1 출력하도록 초기값 설정정

    // 실제 연산량 줄이는 방향으로 오름차순 배열로 되어 있으니, 가장 큰 키부터 0까지 순서대로 진행한다.
    for(int i=n-1; i>=0; i--){
        // 만약 태어난 달이 m인 키 발견시 maxHeight에 해당 값 저장 후 break
        if (month[i] == m){
            maxHeight=height[i];
            break;
        } 
    }

    // maxHeight값 리턴
    return maxHeight;
}

int main(){
    int n, m;   // n은 도토리 수, m은 현재 달
    int* height;    // 도토리 키 저장할 동적 배열
    int* month;     // 해당 도토리 별 생일 저장할 동적 배열

    scanf("%d", &n);    // 도토리 수 n입력
    height = new int[n];    // height 동적 할당 
    month = new int[n];     // month 동적 할당

    // height 배열 값 입력력
    for (int i=0; i<n; i++)
    {
        scanf("%d", &height[i]);
    }

    // month 배열 값 입력력
    for (int i=0; i<n; i++)
    {
        scanf("%d", &month[i]);
    }

    // 현재 달 입력력
    scanf("%d", &m);

    // answer변수에 getMaximumHeihgt함수 반환값 저장장
    int answer = getMaximumHeight(height, month, n, m);
    
    // answer값 출력
    printf("%d\n", answer);

    // 동적 메모리 해제
    delete[] height;
    delete[] month;
    return 0;
}