#include <cstdio>   // C 스타일 입출력
#include <vector>   // 벡터 사용
#include <algorithm>    // min 함수 사용
using namespace std;

// 무승부를 최소화하며 가능한 경기 점수 조합을 구하는 클래스
class MatchDrawSolver {
    int n, a, b;           // 경기 수, 총 득점, 총 실점
    int minDraws;          // 최소 무승부 수
    vector<int> bestX, bestY; // 최적 점수 저장용
    vector<int> pathX, pathY; // 현재 DFS 탐색 중 점수 경로

    // DFS 함수
    void dfs(int idx, int sumX, int sumY, int draws) {
        // 가지치기: 점수 초과
        if (sumX > a || sumY > b) return;

        // 가지치기: 무승부 수 초과
        if (draws > minDraws) return;

        // 가지치기: 남은 경기로 목표 점수 도달 불가
        int remain = n - idx;
        if (sumX + remain * 10 < a || sumY + remain * 10 < b) return;
        if (sumX + remain * 0 > a || sumY + remain * 0 > b) return;

        // 종료 조건: 모든 경기 소화
        if (idx == n) {
            if (sumX == a && sumY == b) {
                if (draws < minDraws) {
                    minDraws = draws;
                    bestX = pathX;
                    bestY = pathY;
                }
            }
            return;
        }

        // 점수 조합 시도
        for (int i = 0; i <= min(10, a - sumX); i++) {
            for (int j = 0; j <= min(10, b - sumY); j++) {
                pathX.push_back(i);
                pathY.push_back(j);
                dfs(idx + 1, sumX + i, sumY + j, draws + (i == j ? 1 : 0));
                pathX.pop_back();
                pathY.pop_back();
            }
        }
    }

public:
    // 생성자
    MatchDrawSolver(int n, int a, int b) : n(n), a(a), b(b), minDraws(n) {}

    // 계산 시작
    bool solve() {
        // 예외 처리: n == 1일 경우 DFS 불필요
        if (n == 1) {
            if (a <= 10 && b <= 10) {
                minDraws = (a == b ? 1 : 0);
                bestX.push_back(a);
                bestY.push_back(b);
                return true;
            }
            return false; // 불가능한 점수 조합
        }

        dfs(0, 0, 0, 0);  // DFS 시작
        return !bestX.empty();
    }

    // 결과 출력
    void print() {
        printf("%d\n", minDraws);
        for (int i = 0; i < n; i++) {
            printf("%d:%d\n", bestX[i], bestY[i]);
        }
    }
};

// 메인 함수
int main()
{
    int n, a, b;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    MatchDrawSolver solver(n, a, b);

    // 불가능한 경우 예외 처리
    if (solver.solve()) {
        solver.print();
    } else {
        printf("-1\n"); // 불가능한 경우 출력 (문제 조건엔 없지만 안정성 위해)
    }

    return 0;
}
