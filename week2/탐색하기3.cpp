#include <cstdio>   // C 스타일 입출력 사용을 위한 헤더 파일
#include <cmath>     // C++에서 수학 함수 사용을 위한 헤더 파일
#include <iostream>  // C++ 스타일 입출력 사용을 위한 헤더 파일

using namespace std;

// 배열의 평균과 가장 가까운 요소의 인덱스를 찾는 함수
int findIndex(int data[], int n)
{   
    // 전체 배열의 합을 저장할 변수
    int sum = 0;
    // 가장 가까운 요소의 인덱스를 저장할 변수 (초기값은 0번 인덱스)
    int x = 0;

    // int형을 사용하기 때문에 /의 사용을 피하기 위해
    // (값 - sum/n)이 아니라 (n*값 - sum)을 사용한다. 

    // sum에 data배열 요소 전부 더한다.
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    // for문으로 평균과 가까운 인덱스 값 업데이트트
    for (int i = 0; i < n; i++) {
        // dx는 기존 x인덱스 값과 평균의 차이 저장
        int dx = abs(n * data[x] - sum);
        // di는 현재 i인덱스 값과 평균의 차이 저장
        int di = abs(n * data[i] - sum);
        
        // 새로운 di가 기존 dx보다 차이가 작다면 x를 업데이트한다.
        if (dx > di)
            x = i;
    }

    // 데이터터 번호는 1부터 시작하므로, 배열의 인덱스(0부터 시작)에 +1을 해서 반환
    return x + 1;
}

int main() {
    int n;        // 배열의 크기 저장 변수
    int* data;    // 동적 할당할 정수형 배열 포인터

    // scanf로 n값 입력 받음음
    scanf("%d", &n);

    // 동적 메모리 할당
    data = new int[n];

    // n개의 정수를 입력받아 배열에 저장
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // findIndex 함수 호출하여 answer변수에 값 저장장
    int answer = findIndex(data, n);

    // 찾은 데이터 번호와 그 값을 출력
    printf("%d %d\n", answer, data[answer - 1]);

    // 동적 할당 해제
    delete[] data;

    return 0;
}
