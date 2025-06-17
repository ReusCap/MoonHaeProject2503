#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 전화번호의 최대값을 10000으로 상수 정의 
const int MAX_TABLE_LENGTH = 10000;

// 전화번호 빈도수 table에 기록하는 함수
void fillFrequencyTable(int data[], int n, int table[]){

    // 테이블을 0으로 초기화
    for (int i = 0; i<MAX_TABLE_LENGTH; i++){
        table[i]= 0;
    }
    // 입력된 번호의 빈도수를 테이블에 기록
    for (int i = 0; i<n; i++){
        table[data[i]] +=1;
    }
}

// 가장 자주 등장하는 전화번호 반환 함수 
int getFrequentNumber(int data[], int n){
    // 자주 등장한 숫자 0 초기화 
    int frequent_number = 0;

    int table[MAX_TABLE_LENGTH];    // 0부터 9999까지의 숫자의 횟수를 count하는 히스토그램 
    fillFrequencyTable(data, n, table); // fililFrequencyTable함수 실행

    // 최대 번호만큼 for문 돌려서, 가장 큰 숫자 반환
    for (int i=0; i<MAX_TABLE_LENGTH; i++)
    {   
        // 횟수가 같은 번호가 2개이더라도, 작은 수부터 > 등호이기 때문에 조건 성립
        if(table[i] > table[frequent_number]) 
            frequent_number = i;
    }

    // frequent_number 반환
    return frequent_number;
} 

// 메인함수
int main()
{   
    // 데이터 개수 n변수 선언
    int n;

    // 데이터 개수 n 입력받기
    scanf("%d", &n);

    // n개의 동적 배열 생성
    int *data = new int[n];

    // n개만큼 배열에 입력받는다.
    for (int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    // getFrequentNumber함수 실행
    int answer = getFrequentNumber(data, n);

    // 네 자리로 출력
    printf("%04d", answer);

    // 동적 메모리 해제
    delete[] data;
    
    return 0;
}