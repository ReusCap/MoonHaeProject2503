#include <iostream> // 표준 입출력 사용을 위한 헤더
using namespace std;

// 그래프를 저장할 2차원 배열 (인접 행렬 방식)
// maps[i][j] = 1 이면 i번 노드와 j번 노드가 연결되어 있다는 의미
int maps[10][10];
// 방문 여부를 저장하는 배열
// visited[i] = 1 이면 i번 노드를 방문할 예정, 0이면 이미 방문했거나 없음
int visited[10] = {0};
// 사용자로부터 입력받는 간선의 개수 (edge 수)
int num;

// 인접 행렬 초기화 함수: 모든 값 0으로 설정
void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0; // 연결 없음으로 초기화
        }
    }
}

// 깊이 우선 탐색(DFS) 함수
void dfs(int v) {
    cout << v << endl;  // 현재 방문한 노드 출력
    visited[v] = 0;     // 현재 노드를 방문 완료 처리 (0으로 변경)
    // 연결된 노드를 순회하면서 재귀적으로 탐색
    for (int i = 0; i < num; i++) {
        // maps[v][i] == 1: v와 i가 연결되어 있음
        // visited[i] == 1: 아직 방문하지 않은 노드
        if (maps[v][i] && visited[i]) {
            dfs(i); // 연결된 노드로 DFS 재귀 호출
        }
    }
}

int main(void) {
    int v1, v2;      // 간선 정보에서 사용할 두 노드
    init();          // 인접행렬 초기화
    cin >> num;      // 간선 개수 입력

    // num개의 간선 정보를 입력받아서 인접 행렬 구성
    for (int i = 0; i < num; i++) {
        cin >> v1 >> v2;
        maps[v1][v2] = maps[v2][v1] = 1; // 무방향 그래프
        visited[v1] = visited[v2] = 1;   // 존재하는 노드 표시
    }

    dfs(1);     // DFS 시작: 1번 노드부터 탐색 시작
    return 0;   // 프로그램 종료
}
