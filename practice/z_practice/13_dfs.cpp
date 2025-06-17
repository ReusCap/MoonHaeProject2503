#include <iostream>
using namespace std;

const int MAX_NODES = 10;       // 노드 개수
int adj[MAX_NODES][MAX_NODES];  // 인접 행렬
bool visited[MAX_NODES];        // 방문 여부
int edgeCount;                  // 간선 수

// 인접 행렬 초기화
// visited도 0으로 초기화
void init() {
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            adj[i][j] = 0;
        }
        visited[i] = false;
    }
}

// 깊이 우선 탐색
// 방문시 노드v를 visited에 넣고 출력한다.
// 그리고 for문으로 i에 대해 adj[v][i]가 1이고 visited를 하지 않았다면 그대로 들어가서 dfs탐색
void dfs(int v){
    visited[v] = true;
    cout << v << endl;
    for(int i =0; i<MAX_NODES; i++){
        if(adj[v][i] && !visited[i]){
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
    dfs(1);
    

    return 0;
}
