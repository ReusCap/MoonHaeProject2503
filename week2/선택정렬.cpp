#include<cstdio>    // C 스타일 입출력 사용을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력 사용을 위한 헤더 파일

using namespace std;

// 해당 범위의 가장 작은 요소의 인덱스 찾는 함수 
int getMinIndexInRange(int data[], int n, int begin, int end){
    // 최소값의 인덱스 저장 변수 index를 begin으로 초기화
    int index = begin;

    // begin부터 end까지 최솟값 인덱스 찾아서 업데이트트
    for (int i=begin; i <= end; i++){
        if(data[index]> data[i]){
            index=i;
        }
    }

    // 최소값의 인덱스 반환
    return index;
}

// 선택 정렬 함수
void selectionSort(int data[],int n){
    for (int i=0; i<n; i++){
        // i부터 n-1구간까지 getMinIndexInRange함수 실행
        int minIndex=getMinIndexInRange(data, n,i,n-1);

        // 2개 숫자를 변경 
        int temp = data[minIndex];
        data[minIndex]=data[i];
        data[i]= temp;
    }
}

int main(){
    int n;  //배열의 크기
    int *data;  //동적 할당을 위한 정수형 포인터

    // scanf로 n값 입력
    scanf("%d", &n);
    // 동적 메모리 할당
    data = new int[n];

    // for문으로 n개의 정수 입력받아 배열에 저장장
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // selectionSort함수 실행행
    selectionSort(data,n);

    // 정렬된 배열 값들 공백을 두고 출력
    for(int i=0; i<n; i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", data[i]);
    }

    // 동적 메모리 해제
    delete[] data;

    return 0;
}