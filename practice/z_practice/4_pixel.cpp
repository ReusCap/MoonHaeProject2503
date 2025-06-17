#include <cstdio>
using namespace std;

// 각 테스트 케이스 처리 함수
void process(int caseIndex) {
    long long R;
    scanf("%lld", &R);

    long long sum = 0;
    long long y = R;
    // 각 x에 대하여 
    for (long long x = 0; x <= R; x++) {
        // 임시 height 0으로 설정
        long long height = 0;
        // y는 ;y>=0; y--로 조건문에 따라 x**x+y*y < r*r이면 포함되는걸로하고
        // height은 y에 대해 +1이다. 0도 포함하니까
        for (; y >= 0; y--) {
            if (x * x + y * y < R * R) {
                height = y + 1;
                break;
            }
        }
        // 각 x가 끝날때마다 height을 더해줌
        sum += height;
    }

    printf("#%d\n", caseIndex);
    printf("%lld\n", sum * 4);
}

int main() {
    int casesize;
    scanf("%d", &casesize);

    for (int caseIndex = 1; caseIndex < casesize; caseIndex++) {
        process(caseIndex);
    }

    return 0;
}
