#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // vector 사용을 위한 STL 헤더
#include <algorithm>    // sort 등 STL 함수 포함 헤더

using namespace std;    // std:: 생략 위해

const int MAX_N = 1000000;  // 피보나치 수열 최대 항 수 (1,000,000번째 항까지 계산)
vector<int> FIBONACCI_TABLE;    // 피보나치 수열 값을 저장할 전역 벡터

vector<int> makeFibonacciTable(int n){
    const int MOD = 100000000;  // 결과값은 8자리 수로 제한

    // 피보나치 수열을 저장할 벡터 생성 (인덱스 0부터 n까지 사용, 총 n+1칸)
    vector<int> ret(n+1);
    ret[1] = 0; // 첫 번째 항은 0이다.
    ret[2] = 1; // 두 번째 항은 1이다.


    // 세 번째 항부터는 피보나치 정의 이용해 계산
    // f(n) = f(n-1)+ f(n-2)
    for(int i = 3; i<=n; ++i){
        ret[i] = ret[i-1] + ret[i-2];

        // 8자리만 남기도록 해준다.
        ret[i] %= MOD;
    }
    return ret;
}

// 미리 계산된 피보나치 테이블에서 n번째 항의 값을 반환환
int getFibo(int n){
    // 피보나치의 값을 미리 계산해 뒀기 때문에 그 값을 반환한다. 
    int answer = FIBONACCI_TABLE[n];
    return answer;
}

// 메인함수
int main(){
    // 피보나치 수열을 미리 MAX_N번째 항까지 계산산
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N);    // 전처리를 통해 미리 계산

    int caseSize;   // 테스트 케이스 수
    scanf("%d", &caseSize); // 테스트 케이스 수 입력받기

    // 입력된 케이스 수만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        int n;  // 사용자가 알고 싶은 피보나치 항 번호
        scanf("%d", &n);

        // 해당 항의 피보나치 수 계산
        int answer = getFibo(n);
        // 출력
        printf("%d\n", answer);
    }
    // 벡터 메모리 해제
    FIBONACCI_TABLE.clear();

    return 0;
}