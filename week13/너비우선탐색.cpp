#include <iostream>   // 표준 입출력 사용
#include <queue>      // 큐(queue) 사용을 위한 헤더
using namespace std;

// 최대 10개의 노드(정점)를 가정
// map[i][j]는 i번 노드와 j번 노드 사이의 연결 여부(간선)를 저장
int map[10][10] = {0};    // 인접 행렬: 1이면 연결됨, 0이면 연결 안 됨

// 노드 방문 여부를 저장하는 배열
// visit[i] == 1이면 i번 노드를 이미 방문함
int visit[10] = {0};      

// BFS에 사용할 큐
queue<int> q;

// 노드의 개수와 간선의 개수
int num, edge_num;

// 너비 우선 탐색(BFS) 함수
void bfs(int v) {
    visit[v] = 1;         // 시작 노드를 방문 처리
    cout << v << "\n";    // 시작 노드를 출력
    q.push(v);            // 시작 노드를 큐에 삽입

    // 큐가 빌 때까지 반복 (탐색할 노드가 없을 때까지)
    while (!q.empty()) {
        int node = q.front(); // 큐의 맨 앞 노드를 가져옴
        q.pop();              // 해당 노드를 큐에서 제거

        // 모든 노드에 대해 인접 여부 확인
        for (int i = 1; i <= num; i++) {
            // 조건:
            // 1. node와 i가 연결되어 있고 (map[node][i] == 1)
            // 2. i번 노드를 아직 방문하지 않은 경우
            if (map[node][i] == 1 && visit[i] == 0) {
                visit[i] = 1;       // i번 노드를 방문 처리
                cout << i << endl;  // i번 노드 출력
                q.push(i);          // i번 노드를 큐에 삽입 (나중에 탐색)
            }
        }
    }
}


// 메인함수
int main() {
    // 사용자로부터 노드 수(num)와 간선 수(edge_num)를 입력받음
    // 8 10 (정점 8개, 간선 10개)
    cin >> num >> edge_num;

    // edge_num만큼 간선 정보를 입력받아 인접 행렬 구성
    for (int i = 0; i < edge_num; i++) {
        int v1, v2;
        cin >> v1 >> v2;                // 두 노드 사이의 간선 입력
        map[v1][v2] = 1;                // v1 → v2 연결 표시
        map[v2][v1] = 1;                // v2 → v1 연결 표시 (무방향)
    }

    bfs(1);  // 1번 노드에서 탐색 시작

    return 0; // 프로그램 종료
}
