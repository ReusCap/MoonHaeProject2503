#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // vector 사용을 위한 헤더
#include <algorithm>    // sort 등 STL 함수 포함 헤더

using namespace std;    // std:: 생략 위해

const int MAX_SERIAL_NUMBER = 100000;   // 시리얼 넘버의 최대값

// 주어진 data 벡터의 각 시리얼 넘버가 몇 번 등장하는지를 table에 기록 함수 
void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table)
{
    table.clear();
    // 0으로 쉽게 초기화 가능. 사이즈는 MAX_SERAIL_NUMBER로 
    table.resize(MAX_SERIAL_NUMBER + 1, 0);
    
    for ( int i=0; i<n; i++){
        int serial = data[i];   // 시리얼 넘버 읽기
        table[serial] += 1; // 해당 시리얼 넘버 등장 횟수 증가
    }
} 

// 시리얼 넘버 중에서 한 번만 등장한 숫자들만 오름차순으로 반환
vector<int> getUniqueElements(const vector<int>& data, int n){
    // 정답을 저장할 벡터
    vector<int> ret; 
    // 시리얼 넘버별 등장 횟수 테이블
    vector<int> table;
    fillFrequencyTable(data, n, table);

    // 존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회
    for (int number = 1; number <= MAX_SERIAL_NUMBER; number +=1){
        // 전체 데이터에서 한 번만 등장한 number를 차례로 정답 리스트에 추가된다.
        if (table[number]==1){
            ret.push_back(number);  // ret라는 벡터배열에 마지막 원소 추가
        }
    }

    // 오름차순으로 추가했기 때문에 따로 정렬은 필요 없다. 
    return ret;
}

// 메인함수
int main()
{   
    // 시리얼 넘버 개수
    int n;
    // 입력받기
    scanf("%d", &n);

    // 시리얼 넘버들 저장할 벡터 생성
    vector<int> data = vector<int>(n);

    // n개의 시리얼 넘버 입력받기
    for (int i=0; i<n; ++i){
        scanf("%d", &data[i]);
    }

    // answer에 getUniqueElements함수 결과값 반환
    const vector<int> answer = getUniqueElements(data, n);

    // 각 원소들을 출력한다.
    for (int i = 0; i< answer.size(); ++i){
        if (i>0){   // 첫번째 원소가 아니면 공백 추가 
            printf(" ");
        }
        printf("%d", answer[i]);
    }

    return 0;
}