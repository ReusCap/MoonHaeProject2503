#include <iostream>
#include <queue>
using namespace std;

// 밖에서 노드 개수와, 인접행렬과 방문여부, 노드와 간선 정의
const int MAX_NODES = 10;

int adj[MAX_NODES][MAX_NODES];  // 인접 행렬 (무방향 그래프)
bool visited[MAX_NODES];        // 방문 여부

int nodeCount, edgeCount;

// 너비 우선 탐색 함수
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    // while로 큐 비기 전까지 돌려. 
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << '\n';

        // 인접 노드 탐색
        // 방문 할때마다 true로 바꾸고 푸시를 한다. 
        for (int next = 1; next <= nodeCount; ++next) {
            if (adj[current][next] && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }
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

    bfs(1);  // 1번 노드부터 BFS 시작

    return 0;
}
