#include <iostream>
#include <queue>
using namespace std;
//최대노드, 인접헹렬, 방문자, 노드와 간선까지 전역변수 설정
const int max_nodes=10;
int adj[max_nodes][max_nodes];
int visited[max_nodes];
int nodeCount, edgeCount;

// bfs는 첫 노드 받아서 큐 선언 후, 해당 노드 visited true로 만들고 큐에 집어 넣어.
// 이제 while문으로 큐 비기 전까지 !q.empty()까지 돌림
// 제일 앞에거를 current 변수에 집어넣고
// q.pop한다음에 출력
// 이제 인접행렬 통해서 탐색 한다. for문으로 돌려서 인접행렬 노드 1부터 끝까지 탐색
// if문의 조건은 인접행렬 adk[current][next]부터 차근차근 증가하다 1 있어야 하고, visited[next]가 false여야만 가능하다.
// 그렇게 방문시 visited[next]를 true로 바꾸고 큐에 q.push(next);로 큐에 넣고 실행 
void bfs(int start){
    queue<int> q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << endl;

        for (int next = 1; next <=nodeCount; next++){
            if(adj[current][next] && !visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    // 여기서 중요한게 인접행렬이니까 엣지만큼 받아야함
    // for문 안에서 u와 v를 선언하고 입력받고 해당 인접행렬 1로 초기화
    cin >> nodeCount >> edgeCount;
    for (int i = 0; i< edgeCount; ++i){
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u]=1;
    }
    bfs(1);
    return 0;
}
