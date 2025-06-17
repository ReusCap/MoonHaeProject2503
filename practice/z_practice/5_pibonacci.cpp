#include <iostream>
#include <vector>
using namespace std;

// 전체 피보나치 인덱스 개수랑, 값 크기 제한
const int MAX_N = 1000000;     // 피보나치 최대 항 수
const int MOD = 100000000;     // 8자리 수 제한
vector<int> FIBONACCI_TABLE;   // 전역 벡터

// 피보나치 수열 계산 함수
vector<int> makeFibonacciTable(int n){
    vector<int> ret(n+1);
    ret[1] = 0;
    ret[2] = 1;

    for(int i=3; i<=n; i++){
        ret[i] = (ret[i-1] + ret[i-2])%MOD;
    }
    return ret;
}

// n번째 피보나치 수 반환
int getFibo(int n) {
    return FIBONACCI_TABLE[n];
}

// 메인 함수
int main() {

    FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        int n;
        cin >> n;
        cout << getFibo(n) << '\n';
    }

    FIBONACCI_TABLE.clear();
    return 0;
}
