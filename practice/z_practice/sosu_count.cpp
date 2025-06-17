#include <iostream>
#include <vector>
using namespace std;

class Sieve {
public:
    int maximumValue;
    vector<bool> isPrime;

    Sieve(int maximumValue) : maximumValue(maximumValue) {
        isPrime.assign(maximumValue + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maximumValue; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j <= maximumValue; j += i) {
                isPrime[j] = false;
            }
        }
    }
};

void process(int caseIndex, const Sieve& sieve) {
    int L, R;
    cin >> L >> R;
    // 숫자 새는 카운트 변수
    int count = 0;
    for (int i = L; i <= R; ++i) {
        if (sieve.isPrime[i]) ++count;
    }

    cout << "Case #" << caseIndex << ":\n";
    cout << count << '\n';
}

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
