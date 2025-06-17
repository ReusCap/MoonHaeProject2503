#include <iostream>
using namespace std;

const int MAX_NODES = 10;

int adj[MAX_NODES][MAX_NODES];  // 인접 행렬
bool visited[MAX_NODES];        // 방문 여부
int edgeCount;                  // 간선 수

// 인접 행렬 초기화
void init() {
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            adj[i][j] = 0;
        }
        visited[i] = false;
    }
}

// 깊이 우선 탐색
// 방문시 true로 바꾸고 현재 접근 v에서 인접된놈 있는지 i로 탐색하고 더 들어감.
void dfs(int v) {
    visited[v] = true;
    cout << v << '\n';

    for (int i = 0; i < MAX_NODES; ++i) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    init();
    // 입력형식
    // 3개
    // 1 2
    // 1 3
    // 2 3 이런 느낌
    cin >> edgeCount;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;  // 무방향 그래프
    }

    // 1번 노드가 실제 연결된 경우에만 시작
    if (!visited[1]) {
        dfs(1);
    }

    return 0;
}
