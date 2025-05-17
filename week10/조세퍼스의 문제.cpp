#include <iostream> // C++ 입출력
#include <vector>   // 벡터 자료구조
#include <queue>    // 큐 자료구조
#include <cstdio>   // C 스타일 입출력

using namespace std;

// 플레이어를 나타내는 클래스
class Player {
public:
	int index;  // 플레이어의 번호

    // 생성자: 플레이어 번호를 초기화
	Player(int index = 0) {
		this->index = index;
	}
};

// 요세푸스 문제 해결 함수
vector<Player> getDeadPlayersList(int n, int m, const vector<Player> &players) {
	// 현재 게임에서 제외된 플레이어들의 리스트
	vector<Player> deadPlayers;

	// 아직 게임에서 제외되지 않는 플레이어들의 리스트
	queue<Player> que;

    // players벡터의 요소들을 que에 순서대로 push 한다.
	for (int i = 0; i < n; i += 1) {
		que.push(players[i]);   // 1 2 3 4 5 6 7
	}
    
    // n번동안 반복
	for (int i = 0; i < n; i++) {
		// (m-1)명의 사람을 건너뛴다.
        // 나머지 연산으로 해결
		int jump = 1 + (m - 1) % que.size();
        
        // jump-1만큼 반복
		for (int j = 0; j < jump - 1; j += 1) {
            // m번째 사람이 제일 front로 오게 반복해서 que 수정
			Player p = que.front();
			que.pop();
			que.push(p);
		}

		// m번째 사람은 게임에서 제외한다.
		Player dead = que.front();
		que.pop();

		// 제외 리스트에 추가한다.
		deadPlayers.push_back(dead);
	}

    // 제거된 순서대로 정렬된 deadPlayers벡터 반환
	return deadPlayers;
}
// 하나의 테스트 케이스 처리 함수
void testcase(int caseIndex) {
    // 사람 수 n과 제거할 간격 m을 입력한다.
	int n, m;
	scanf("%d %d", &n, &m);

    // Player타입의 player벡터 선언
	vector<Player> players;

    // player벡터에 1번부터 n번까지 번호 부여
	for (int i = 0; i < n; i++) {
		players.push_back(Player(i + 1));
	}

    // 제거된 순서 출력하는 리스트 생성
    // getDeadPlayersList함수 이용
	vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

    // deadPlayers리스트를 공백으로 구분하여 출력
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");    // 첫번째 출력 이후 공백 삽입
		}

		Player p = deadPlayers[i];
        // 제거된 player의 번호 p.index를 출력 
		printf("%d", p.index);
	}
	printf("\n");   // 줄바꿈
}

// 메인 함수
int main() {
    // 테스트 케이스 수 선언, 입력
	int caseSize;
	scanf("%d", &caseSize);

    // 각 테스트 케이스에 대해 실행
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		testcase(caseIndex);    // 해당 케이스 실행
	}
	
	return 0;
}
