#include<cstdio>    // C 스타일 입출력을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력을 위한 헤더 파일

using namespace std;

// 배열이 오름차순으로 정렬되어 있는지 확인하는 함수
bool isOrdered(int data[], int n){
    int prevData = data[0]; // 첫 번째 값을 이전 값으로 초기화
    bool result = true;     // 기본적으로 오름차순이라 가정하고 시작

    // 두 번째 요소부터 for문 시작
    for (int i=1; i<n; i++) {
        // 현재 값이 이전 값보다 작으면 오름차순이 아님
        if (data[i] < prevData) {  // 오름차순 아닌 거 발견하면 break
            result = false;
            break;
        }
        // 이전 값을 현재 값으로 갱신
        prevData = data[i];
    }
    // 오름차순 여부 반환
    return result;
}

// 메인함수
int main(){
    int n;      // 학생 수 변수 선언
    int* data;  // 동적 배열 포인터 선언
    
    scanf("%d", &n);    // 학생 수 n 입력받음
    data = new int[n];  // n만큼 배열 동적 할당

    // 학생 키정보 n개만큼 배열에 저장 
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // result변수에 isOrdered함수 리턴값 저장장
    bool result = isOrdered(data,n);

    // result 값에 따라 Yes, No 출력력
    if (result){
        printf("YES");
    }
    else{
        printf("NO");
    }

    // 동적 메모리 해제
    delete[] data;
    return 0;
}