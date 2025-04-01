#include<cstdio>    // C 스타일 입출력을 위한 헤더 파일
#include<iostream>  // C++ 스타일 입출력을 위한 헤더 파일

using namespace std;

// 화보의 종류 수 구하는 함수수
int getElementTypeCount(int data[], int n){
    // 만약 n이 0이면 종류수가 0이니 0을 리턴한다.
    if (n==0){
        return 0;
    }
    // countType라는 종류 개수 저장할 변수 선언
    int countType = 1;  // 초기값은 1
    for (int i=1; i<n; i++){
        // 중복이 있는지 조사, 중복이 있을경우 count증가하도록, 오름차순 정렬되어있다는 특징 활용
        if (data[i-1] != data[i])    // 중복되지 않을때마다 count추가
        {
            countType++;
        }
    }
    // 종류 개수 리턴턴
    return countType;
}   

// 메인함수수
int main(){
    int n;  // 입력받을 화보 수 n 
    int* data;  // 동적 배열 포인터 생성
    
    scanf("%d", &n);    // scanf로 n 입력 받음
    data = new int[n];  // 길이 n만큼 메모리 동적 할당
    
    // n만큼 화보의 고유번호 입력받기
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // answer에 getElementTypeCount함수 리턴값 저장
    int answer = getElementTypeCount(data, n);

    // answer 출력
    printf("%d\n", answer);

    // 동적 메모리 해제
    delete[] data;
    return 0;
}   