#include <iostream>
using namespace std;

const int MAX_NODES = 10;

int adj[MAX_NODES][MAX_NODES];  // 인접 행렬
bool visited[MAX_NODES];        // 방문 여부

int nodeCount, edgeCount;

// 깊이 우선 탐색 함수
void dfs(int current) {
    visited[current] = true;
    cout << current << '\n';

    for (int next = 1; next <= nodeCount; ++next) {
        if (adj[current][next] && !visited[next]) {
            dfs(next);  // 재귀적으로 더 깊게 들어감
        }
    }
}

int main() {
    cin >> nodeCount >> edgeCount;

    // 간선 정보 입력
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;  // 무방향 그래프
    }

    dfs(1);  // 1번 노드부터 DFS 시작

    return 0;
}
