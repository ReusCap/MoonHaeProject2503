#include <cstdio>
#include <vector>
using namespace std;

// 에라토스테네스의 체 클래스
class Sieve {
public:
    int maxVal;
    vector<bool> isPrime;

    Sieve(int maxVal) : maxVal(maxVal), isPrime(maxVal + 1, true) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j <= maxVal; j += i) {
                isPrime[j] = false;
            }
        }
    }

    bool isPrimeNumber(int num) const {
        return isPrime[num];
    }
};

// [from, to] 범위 내 소수 목록 반환
vector<int> getAllPrimes(int from, int to, const Sieve& sieve) {
    vector<int> primes;
    for (int i = from; i <= to; ++i) {
        if (sieve.isPrimeNumber(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 테스트 케이스 처리
void process(int caseIndex, const Sieve& sieve) {
    int L, R;
    scanf("%d%d", &L, &R);

    vector<int> primes = getAllPrimes(L, R, sieve);
    printf("Case #%d:\n%d\n", caseIndex, (int)primes.size());
}

int main() {
    const int MAX = 1000000;
    Sieve sieve(MAX);

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        process(i, sieve);
    }
    return 0;
}
