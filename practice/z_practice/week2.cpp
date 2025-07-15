#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
// 개념0. iostream, cstdio, string, vector, stack, queue, set, 이정도만
// 개념1. && || !로 and or not표현
// 개념2. 탐색하기1처럼 초기값 -1로 설정도 유의
// 개념3. scanf로는 string을 받아오지 못함 cin사용
// 개념4. scanf뒤에는 무조건 &를 붙여야함.
// 개념5. int형일때는 / 사용을 유의해서 분모를 곱한값을 차라리 구해라.
// 개념6. abs함수 = 절댓값

int main(){
    // 포인터 변수
    int* ptr = new int;      // int 하나 할당
    *ptr = 42;
    delete ptr;              // 해제
    
    // 포인터 배열
    int* arr = new int[10];  // int 10개짜리 배열 동적 할당
    arr[0] = 1; arr[1] = 2;  // 배열처럼 사용 가능
    delete[] arr;            // 배열은 반드시 delete[]

    vector<int> arr(10);   // new 필요 없음
    arr[0] = 42;

    
    return 0;
}

void hello(){
    int n;
    scanf("%d", &n);
    int *data = new int[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &data[i]);
    }
}