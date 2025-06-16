#include <iostream>
using namespace std;

// 주어진 좌표가 반지름 R의 원 안에 있는지 여부
bool isInside(long long x, long long y, long long R) {
    return x * x + y * y < R * R;
}

// 각 테스트 케이스 실행 함수
void testcase(int caseIndex) {
    long long R;
    cin >> R;

    long long sum = 0;
    long long y = R;

    for (long long x = 0; x <= R; ++x) {
        while (y >= 0 && !isInside(x, y, R)) {
            --y;
        }
        sum += y + 1;  // y가 -1이면 height = 0
    }

    cout << "#" << caseIndex << '\n';
    cout << sum * 4 << '\n';
}

int main() {
    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        testcase(i);
    }

    return 0;
}
