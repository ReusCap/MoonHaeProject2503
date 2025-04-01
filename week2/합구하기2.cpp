#include<stdio.h>   // C 스타일 입출력 함수 사용을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력 사용을 위한 헤더 파일

using namespace std;

// 체중 제한 조건 계산 함수
void solve(int data[], int n, int p, int q){
    int count=0;    // 최대 뭄무게 p 이하인 원소 개수를 저장 변수
    int weight_sum=0;   // 최대몸무게 p 이하인 원소들의 합 저장 변수
    for(int i=0; i<n; i++){
        if(data[i]<=p){ // 값이 p 이하인 경우
            count++;    // count 개수 증가
            weight_sum+=data[i];    // weight_sum에 무게 추가가
        }
    }
    // count와 weight_sum 출력력
    printf("%d %d\n", count, weight_sum);

    // weight_sum의 합이 q 이하이면 "YES" 출력, 그렇지 않으면 "NO" 출력
    if(weight_sum<=q){
        printf("YES");
    }
    else{
        printf("NO");
    }
}

int main(){
    int n, p, q;    // n: 사람 수, p: 최대 몸무게, q: 최대 몸무게 총합합
    int *data;      // 동적 할당할 정수형 배열의 포인터

    // scanf로 입력받기
    scanf("%d %d %d", &n, &p, &q);

    // 동적 메모리 할당 (크기가 n인 정수형 배열)
    data = new int[n];

    // 배열에 원소 입력받기
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // solve함수 실행행
    solve(data, n, p, q);

    // 동적 메모리 해제
    delete[] data;

    return 0;
}