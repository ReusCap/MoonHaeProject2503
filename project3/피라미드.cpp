#include <iostream> // C++ 스타일 입출력 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <algorithm>    // min, max 함수를 사용하기 위한 헤더파일

using namespace std;

// 주어진 위층 수열에 대해 가능한 아래층 수열의 개수를 계산하는 함수
// x1의 가능 범위 최소값, 최대값을 비교해가며 구해서, 최대값-최소값+1을 반환하는 함수
long long solve(const vector<long long>& upstairs) {
    long long l = 0;       // 현재 왼쪽 수
    long long r = 0;       // 현재 오른쪽 수
    long long maxx = 1e9;  // x1이 될 수 있는 최대값 (초기에는 아주 큼)
    long long minx = 0;    // x1이 될 수 있는 최소값 (초기에는 0)

    int n = upstairs.size(); // 위층 수열의 길이

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // 짝수 번째일 때: 왼쪽 수 l을 구함
            // (l + r = upstairs[i] → l = upstairs[i] - r)
            l = upstairs[i] - r;
            maxx = min(maxx, l); // 가능한 최대값 업데이트
        } else {
            // 홀수 번째일 때: 오른쪽 수 r을 구함
            // (l + r = upstairs[i] → r = upstairs[i] - l)
            r = upstairs[i] - l;
            minx = max(minx, -r); // 가능한 최소값 업데이트
        }
    }

    // 가능한 x1 범위가 없는 경우
    if (minx > maxx) {
        return 0;
    } else {
        // 가능한 x1의 개수는 (최대값 - 최소값 + 1)
        return maxx - minx + 1;
    }
}

int main() {
    // 수열 길이 정수 n 입력
    int n;
    scanf("%d", &n);

    vector<long long> upstairs(n); // 위층 수열 저장
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &upstairs[i]); // 위층 수 입력
    }

    long long result = solve(upstairs); // 가능한 방법 수 계산
    printf("%lld\n", result); // 결과 출력

    return 0;
}
