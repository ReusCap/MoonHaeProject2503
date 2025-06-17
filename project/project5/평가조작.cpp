#include <cstdio>       // scanf, printf를 사용하기 위한 헤더
#include <vector>       // 벡터 자료구조를 사용하기 위한 헤더

using namespace std;

// X/Y 형태의 분수를 저장하기 위한 구조체
struct Fraction {
    // num : 분자
    // den : 분모
    // den == 0이면 무한대니까 생성자는 1로 초기화시켜줌
    long long num;
    long long den;
    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {}
};

// 두 분수 a, b에 대해 a < b 여부를 판단하는 함수
bool lessFrac(const Fraction &a, const Fraction &b) {
    return a.num * b.den < b.num * a.den;
}

// 두 분수 a, b에 대해 a > b 여부를 판단하는 함수
bool greaterFrac(const Fraction &a, const Fraction &b) {
    return a.num * b.den > b.num * a.den;
}

// X와 Y를 적절히 골라서 점수 순서가 S1 > S2 > ... > SN 이 되도록 만들 수 있는지 여부 판단하는 함수
// A: 1학기 점수, B: 2학기 점수
bool canCommitFraud(int N, const vector<long long> &A, const vector<long long> &B) {
    // X/Y 값이 만족해야 할 최소(lower bound), 최대(upper bound) 범위 초기화
    // LB는 0부터 시작 (0/1), UB는 무한대 (1/0 → 분모가 0이면 무한)
    Fraction LB(0, 1);
    Fraction UB(1, 0);

    // 연속된 모든 쌍에 대해 Si > Si+1 이 되도록 조건을 유도
    for (int i = 0; i + 1 < N; ++i) {
        long long C = A[i] - A[i+1]; // Ai - Ai+1
        long long D = B[i] - B[i+1]; // Bi - Bi+1

        // 점수 식: Si = X*Ai + Y*Bi, Sj = X*Aj + Y*Bj
        // 조건: Si > Si+1 → X*C + Y*D > 0

        if (C == 0) {
            // X*C가 0이므로 D > 0 이어야만 S[i] > S[i+1] 조건 성립
            if (D <= 0) return false; // 성립 불가 → "NO"
        }
        else if (C > 0) {
            // 불등식: X*C + Y*D > 0  →  X/Y > -D/C
            // 즉, X/Y의 하한 조건이 추가됨
            Fraction f(-D, C); // f = -D/C
            if (greaterFrac(f, LB)) LB = f; // LB를 최대한 크게 설정
        }
        else {
            // C < 0 → 불등식: X/Y < -D/C → X/Y의 상한 조건이 추가됨
            Fraction f(D, -C); // f = D/(-C)
            if (UB.den == 0 || lessFrac(f, UB)) UB = f; // UB를 최소한으로 좁힘
        }
    }

    // UB가 여전히 무한대라면 (UB.den == 0), 아무리 커도 상관 없으므로 항상 가능
    if (UB.den == 0) return true;

    // 그렇지 않다면 엄격하게 LB < UB 이어야 조건 만족
    return lessFrac(LB, UB);
}

// 메인 함수
// 입력: N, A1~AN, B1~BN
// 출력: 조건 만족 가능하면 YES, 아니면 NO
int main() {
    int N;
    // 학과 수 입력
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    vector<long long> A(N), B(N); // A[i]: 1학기 점수, B[i]: 2학기 점수

    // A 배열 입력
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }

    // B 배열 입력
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &B[i]);
    }

    // 조건 만족 가능 여부 판단 후 결과 출력
    printf(canCommitFraud(N, A, B) ? "YES\n" : "NO\n");

    return 0;
}
