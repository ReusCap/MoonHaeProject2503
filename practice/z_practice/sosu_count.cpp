#include <iostream>
#include <vector>
using namespace std;

class Sieve {
public:
    int maximumValue;
    vector<bool> isPrime;

    Sieve (int maximumValue) : maximumValue(maximumValue) {
        isPrime.assign(maximumValue+1, true);  // 초기에는 모두 소수로 가정
        fillSieve();
    }

    // isPrime에 저장된 소수인지 true, false 반환해주는 함수
    bool isPrimeNumber(int num) const {
        return isPrime[num];
    }

private:
    void fillSieve() {
        isPrime[0] = isPrime[1] = false;

        // 2부터 범위 내에 모두 적용
        for (int num = 2; num * num <= maximumValue; ++num) {
            // 소수가 아니면 일단 재끼고
            if (!isPrime[num]) continue;

            // 소수이면 그 제곱부터 모든 값다 false로 적용시켜
            for (int j = num*num; j <=maximumValue; j+=num) {
                isPrime[j] = false;
            }
        }
    }
};

// [from, to] 구간의 소수를 모두 반환
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
    vector<int> primes;
    for (int num = from; num <= to; ++num) {
        if (sieve.isPrimeNumber(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

// 테스트 케이스 하나 처리
void process(int caseIndex, const Sieve& sieve) {
    int L, R;   
    cin >> L >> R;

    vector<int> primes = getAllPrimeNumbers(L, R, sieve);

    cout << "Case #" << caseIndex << ":\n";
    cout << primes.size() << '\n';
}

// 메인함수에서는 상수 정해두고
// Sieve클래스 객체 생성
// 케이스사이즈 받고, 테스트케이스만큼 process함수 실행
int main() {

    const int MAX_VALUE = 1000000;
    Sieve sieve(MAX_VALUE);

    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        process(i, sieve);
    }

    return 0;
}
