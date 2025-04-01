#include<cstdio>    // C 스타일 입출력을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력을 위한 헤더 파일

using namespace std;

// 1부터 i까지의 모든 수를 더하는 함수
int getRangeSumFromOne(int i){
    // 1부터 i이하하까지 모두 더한 수수 저장하는 변수 answer 
    int answer = 0;

    // 1부터 i이하까지 for문으로 전부 더한다.
    for (int j=1; j<=i; j++){
        answer+=j;
    }
    return answer;
}

// 1이상 N이하의 모든 자연수 합 구하는 함수
long long getAnswer(int N){
    // answer값을 long long타입 0으로 초기화
    long long answer=0;

    // for문으로 1부터 N이하 모든 값 getRangeSumFromOne함수 실행해서 answer에 더해줌
    for (int i=1; i<=N; i++){
        int rangesum = getRangeSumFromOne(i);   
        answer += rangesum;
    }

    // 최종 answer값 반환
    return answer;
}

int main(){
    int n;  //사용자 입력값 저장 변수

    // scanf로 n값 입력
    scanf("%d", &n);   

    // answer변수에 getAnswer(n)함수 실행 값 저장 
    long long answer = getAnswer(n);

    // long long 타입 출력 위해 %lld사용해 answer 출력
    printf("%lld\n", answer);

    return 0;
}