#include <cstdio>    // C 스타일 입출력을 위한 헤더파일
#include <vector>    // 벡터(vector) 사용을 위한 헤더파일
#include <algorithm> // swap 함수를 사용하기 위한 헤더파일
using namespace std;

// 현재 시각 t, 모래 총량 s, 뒤집은 시각 리스트(reverse_time)를 받아서
// t초 이후 모래가 모두 아래에 모일 때까지의 최종 시각을 반환하는 함수
int solve(int t, int s, vector<int> reverse_time) {
    int top = 0;      // 위쪽(top) 모래량 (초기에는 0)
    int bottom = s;   // 아래쪽(bottom) 모래량 (초기에는 전체 모래)
    int time = 0;     // 현재 시각 (초기에는 0)
    int idx = 0;      // reverse_time 벡터를 탐색할 인덱스 (현재 뒤집기 이벤트 번호)

    // 현재 시각 time이 목표 시각 t에 도달할 때까지 반복
    while (time < t) {
        int next; // 다음 이벤트가 발생할 시각

        // 아직 처리할 뒤집기 이벤트가 남아있는 경우
        if (idx < reverse_time.size()) {
            next = reverse_time[idx];
        } 
        // 더 이상 뒤집기 이벤트가 없는 경우
        else {
            next = t;
        }

        // 현재 시각 time부터 다음 이벤트 시각 next까지의 시간 차이
        int gap = next - time;

        // gap 동안 위쪽(top) 모래가 아래쪽(bottom)으로 떨어짐
        if (top >= gap) {
            // 위쪽 모래가 충분하면 gap만큼 떨어짐
            top -= gap;
            bottom += gap;
        } else {
            // 위쪽 모래가 부족하면 남은 모래(top)만큼만 떨어짐
            bottom += top;
            top = 0;
        }

        // 현재 시각을 이벤트 발생 시각(next)으로 갱신
        time = next;

        // 만약 현재 시각이 뒤집기 이벤트 시각과 일치하면
        if (idx < reverse_time.size() && time == reverse_time[idx]) {
            swap(top, bottom); // 위쪽과 아래쪽 모래를 뒤바꾼다
            idx++;             // 다음 뒤집기 이벤트로 넘어간다
        }
    }

    // 목표 시각 t초까지 처리 완료됨
    // 이후, 위(top)에 남아 있는 모래가 모두 아래로 떨어지는 데 추가로 걸리는 시간은 top초
    return time + top;
}

// 메인 함수
int main() {
    int t, s, n; // t: 목표 시각, s: 모래 총량, n: 뒤집기 횟수
    scanf("%d %d %d", &t, &s, &n);

    vector<int> reverse_time(n); // 뒤집은 시각들을 저장할 벡터

    // 각 뒤집기 시각 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &reverse_time[i]);
    }

    int final_time; // 최종 모래가 모두 아래에 쌓이는 시각
    final_time = solve(t, s, reverse_time);

    // 이미 t초에 모래가 모두 아래에 있으면 추가 대기시간은 0초
    if (final_time <= t) {
        printf("%d", 0);
    }
    // 모래가 아직 위에 남아있으면, 추가로 기다려야 하는 시간 출력
    else {
        printf("%d", final_time - t);
    }

    return 0;
}
