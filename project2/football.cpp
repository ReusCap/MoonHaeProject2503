#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 득점/실점을 번갈아가며 경기 결과를 초기 분배하는 함수
// (무승부 최소화를 위해 가능한 한 한쪽 팀에만 점수를 먼저 배분)
// 쉽게 말해 홀수번 째 경기는 1:0, 짝수번 째 경기는 0:1 이런식으로 우선 분배
// 매개변수 a, b, GwangjuFC, OpponentFC를 &로 참조 받아서 실제 값에 접근 가능하게 한다.
void assignGoalsAlternately(int n, int &a, int &b, vector<int> &GwangjuFC, vector<int> &OpponentFC) {
    // n경기 만큼 for문 순회
    for (int i = 0; i < n; i++) {
        // 짝수 번째 경기: 광주FC 우선
        if (i % 2 == 0) {
            // a가 0보다 크면 광주FC에 1점 줘서 1:0으로 만듦
            if (a > 0) {
                GwangjuFC[i] = 1;
                a--;
            }
            // a가 0이고, b가 0보다 크면 상대팀에 1점 줘서 0:1으로 만듦
            else if (b > 0) {
                OpponentFC[i] = 1;
                b--;
            }
        }
        // 홀수 번째 경기: 상대팀 우선
        else {
            // b가 0보다 크면 상대팀에 1점 줘서 0:1으로 만듦
            if (b > 0) {
                OpponentFC[i] = 1;
                b--;
            } 
            // b가 0이고, a가 0보다 크면 광주FC에 1점 줘서 1:0으로 만듦
            else if (a > 0) {
                GwangjuFC[i] = 1;
                a--;
            }
        }
    }
}

// 남은 득점/실점 수치를 이미 점수가 있는 경기에 몰아주는 함수
// (무승부 발생을 방지하기 위해, 점수가 이미 들어간 경기에만 분배)
// team에는 광주FC 또는 상대팀 벡터가 들어오고, remainingGoals에는 a 또는 b가 들어옴
// 모두 &로 참조받아서 실제값 접근
void distributeRemainingGoals(vector<int> &team, int &remainingGoals) {
    // remainingGoals가 0보다 클 동안, 팀의 경기 수만큼 순회
    // 1골 이상 득점한 경기를 발견하면 그 경기에 남은 골을 모두 몰아줌
    // 예: 광주FC가 1:0인 경기를 발견하면 남은 골 모두 더해 3:0처럼 만듦
    for (int i = 0; remainingGoals > 0 && i < team.size(); i++) {
        // 해당 경기가 1골 이상이면 남은 골 전부 더함
        if (team[i] > 0) {
            // 다 넣어주고, remainingGoals는 0으로 초기화시켜줌
            team[i] += remainingGoals;
            remainingGoals = 0;
        }
    }

    // 만약 모두 0골이라서 위에서 배분 못했다면, 어쩔 수 없이 첫 경기에 몰아준다.
    if (remainingGoals > 0) {
        // 모든 골 몰아주고 remainingGoasl 0으로 초기화
        team[0] += remainingGoals;
        remainingGoals = 0;
    }
}

// 각 경기에서 동점(무승부)이 발생한 경기 수를 세는 함수
// const &를 사용해 벡터를 복사하지 않고, 원본을 읽기 전용으로 참조함
int countDrawMatches(const vector<int> &GwangjuFC, const vector<int> &OpponentFC) {
    // 카운트를 0으로 초기화
    int count = 0;
    // 광주FC와 상대팀 인덱스별로 동점이 있으면 count 증가
    for (int i = 0; i < GwangjuFC.size(); i++) {
        if (GwangjuFC[i] == OpponentFC[i]) {
            count++;
        }
    }
    // count값 반환환
    return count;
}

// 최종 경기 결과 출력 함수
// const &를 사용해 벡터를 복사하지 않고, 원본을 읽기 전용으로 참조함
void printMatches(const vector<int> &GwangjuFC, const vector<int> &OpponentFC) {
    // 벡터 사이즈만큼 for문 순회
    for (int i = 0; i < GwangjuFC.size(); i++) {
        // %d:%d\n으로 줄바꿈하며 경기 결과 출력
        printf("%d:%d\n", GwangjuFC[i], OpponentFC[i]);
    }
}

// 메인 함수
int main() {
    int n, a, b; // n: 총 경기 수, a: 광주FC 총 득점, b: 총 실점

    // 사용자 입력 받기
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    // 각 경기의 득점/실점을 저장할 벡터 초기화
    vector<int> gwangjuFC(n, 0), opponentFC(n, 0);

    // 득점/실점을 번갈아가며 먼저 배분
    assignGoalsAlternately(n, a, b, gwangjuFC, opponentFC);

    // 남은 득점/실점을 기존에 점수가 있는 경기로 몰아줌
    // 광주FC, 상대팀 각각 함수 수행
    distributeRemainingGoals(gwangjuFC, a);
    distributeRemainingGoals(opponentFC, b);

    // 무승부 경기 수 계산
    int drawCount = countDrawMatches(gwangjuFC, opponentFC);
    // 무승부 경기 수 출력
    printf("%d\n", drawCount);

    // 각 경기의 득점 결과 출력
    printMatches(gwangjuFC, opponentFC);

    return 0;
}
