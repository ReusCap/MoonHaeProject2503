#include <iostream>
#include <vector>
using namespace std;

// 전역 피보나치 벡터를 만든다.
const int MAX_N = 1000000;   // 피보나치 최대 항 수
const int MOD = 100000000;   // 8자리 수 제한
vector<int> FIBONACCI_TABLE; // 전역 벡터

// 전처리 - 피보나치 수열 테이블 생성
vector<int> makeFibonacciTable(int n) {
    vector<int> ret(n + 1);
    // 1번 인덱스부터 0으로 채우기!
    // 그리고 전역에 설정하는 이유는 그래야지 초기화시 0이 들어감 값이
    ret[1] = 0;
    ret[2] = 1;

    for (int i = 3; i <= n; i++) {
        ret[i] = (ret[i - 1] + ret[i - 2]) % MOD;
    }
    return ret;
}

int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        int n;
        cin >> n;
        // 해당 피보나치 순서 반환
        cout << FIBONACCI_TABLE[n] << '\n';
    }

    FIBONACCI_TABLE.clear();
    return 0;
}
