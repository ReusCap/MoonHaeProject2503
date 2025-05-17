#include <iostream>   // 표준 입출력 사용을 위한 헤더
#include <vector>     // 벡터 자료구조 사용을 위한 헤더
#include <stack>      // 스택 자료구조 사용을 위한 헤더

using namespace std;

// 개별 타워의 정보를 담을 클래스
class Tower {
public:
	int index; // 타워의 인덱스(1부터 시작)
	int height; // 타워의 높이
	int targetTowerIndex;  // 이 타워의 레이저를 수신하는 대상 타워 인덱스

    // 생성자: 타워의 인덱스와 높이를 받아 초기화
	Tower(int index, int height) {
        // 인덱스, 높이 저장장
		this->index = index;
		this->height = height;
        // 수신하는 타워 인덱스는 0으로 초기화
		this->targetTowerIndex = 0;
	}

    // 수신 타워 인덱스를 설정하는 함수
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}

    // 수신 타워 인덱스를 반환하는 함수 
	int getTargetTowerIndex() {
		return this->targetTowerIndex;
	}
};

// 각 타워에 대해 레이저 수신 대상 타워를 계산하는 함수
void findTargetTowers(vector<Tower>& towers) {
	//Tower타입의 touchableTowers이름 스택 선언
    // 스택에는 항상 높이 내림차순이 되도록 유지 (낮은 타워는 제거됨)
	stack<Tower> touchableTowers;

    // 시간 복잡도 O(n)
	for(int i = 0; i < towers.size(); i ++) {
		Tower& t = towers[i];    // 각 타워 t에 대해 차례로 고려
		int targetTowerIndex = 0;   // 타워 t의 신호를 수신할 후보 인덱스 (초기값 0)

        // 스택에는 왼쪽 타워들이 들어있음
        // while문으로 현재 타워보다 낮은 타워들은 앞으로도 수신 불가하니 제거한다.
		while(touchableTowers.empty() == false && touchableTowers.top().height < t.height){
			// t보다 높이가 낮은 타워들은 이후에도 수신 가능성이 없으므로 제거
			touchableTowers.pop();
		}

		// t 이상의 높이를 가진 타워가 남아있다면?
		if(touchableTowers.size() > 0){
			// t는 해당 타워를 레이저 수신하는 인덱스로 지정한다.
			targetTowerIndex = touchableTowers.top().index;
		}
		// 계산한 수신 대상 타워 인덱스를 현재 타워 객체에 저장, setTargetTowerIndex함수 사용
		t.setTargetTowerIndex(targetTowerIndex);

		// t는 마지막에 등장했으므로 다른 타워의 신호를 수신할 수 있다. 스택에 추가
		touchableTowers.push(t);
	}
}

// 메인 함수
int main() {
    // 타워의 개수 선언, 입력
	int n;
	cin >> n;

    // Tower타입의 towers벡터 선언
	vector<Tower> towers;
    // 각 타워의 높이를 입력 받아 Tower 객체로 생성해 벡터에 저장
	for(int i = 0; i < n; ++i) {
		int hi;
		cin >> hi;  // 높이 입력
		towers.push_back(Tower(i + 1, hi)); // 인덱스 1부터 저장
	}

	// 각 타워가 송신하는 레이저에 대해 타겟을 모두 계산한다
	findTargetTowers(towers);

    // 결과 출력: 각 타워가 보낸 레이저를 수신한 타워의 인덱스를 순서대로 출력
	for(int i = 0 ; i < n; i ++) {
		if(i > 0) {
			cout << " ";    // 처음 이후 공백으로 구분
		}
        // 현재 타워가 수신한 타워의 인덱스 가져오기
		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
        // 출력
		cout << targetIndex;
	}
}