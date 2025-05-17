#include <iostream>     // C++ 표준 입출력
#include <queue>        // 우선순위 큐 사용
#include <vector>       // 벡터 사용
#include <algorithm>    // max() 함수 사용

using namespace std;

class City {
public:
	int index;     // 도시의 인덱스
	int income;    // 해당 도시의 소득

    // 생성자: index와 income을 받아서 초기화
	City(int index, int income) {
		this->index = index;
		this->income = income;
	}

    // 대소관계 추가. 이거 정의 해야지 greater사용 가능
    // 소득 기준 오름차순 비교 연산자 (<)
	bool operator < (const City& o) const {
		return this->income < o.income;
	}
    // 소득 기준 내림차순 비교 연산자 (>)
	bool operator > (const City& o) const {
		return this->income > o.income;
	}
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	int answer = 0; // 최대 소득 차이 초기값

	// 소득이 가장 작은 도시부터 pop되는 우선순위 큐 (top부터 오름차순)
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	// 소득이 가장 높은 도시부터 pop되는 우선순위 큐 (top부터 내림차순)
    // priority_queue<City, vector<City>, less<City>> rangeMaximum; 와 동일
	priority_queue<City> rangeMaximum;

    // k-1개 요소까지 큐에 미리 넣음
    // ex) 3-1=2개까지 넣는다.
	for (int i = 0; i < k - 1; i++) {
		rangeMaximum.push(cities[i]);   // 최대 힙에 넣음
		rangeMinimum.push(cities[i]);   // 최소 힙에 넣음
	}
    // k-1부터 n까지 반복
    // ex) 2부터 n까지 반복복
	for (int i = k - 1; i < n; i++) {
        // 그 다음 요소를 각 최대 힙, 최소 힙에 넣는다.
        // ex) 3번째 요소들 push
		rangeMaximum.push(cities[i]);
		rangeMinimum.push(cities[i]);
        // 이제 top의 인덱스가 i-k+1 이하일때까지 pop한다.
        // 우선순위 큐 내부에 오래된 데이터가 있어도 top이 항상 현재 k범위 안에 있도록 유지 역할
        // ex) i=2면 i-k+1=0, i=3이면 i-k+1은 1이다. 만약 top의 인덱스가 0이라면 pop으로 범위 유지
		while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();
		while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();
        // 반복한 값들 중에서 가장 큰 소득 차를 answer에 업데이트 하는 형식 
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
	}

	return answer;  // 최종 결과 반환
}

void process(int caseIndex) {
    // 도시 수 n, 연속된 도시 수 k 입력
	int n, k;
	cin >> n >> k;

    // City타입의 cities벡터 생성
	vector<City> cities;

    // 각 도시의 소득 입력
	for (int i = 0; i < n; i += 1) {
		int income;
        // income에 소득 입력 받고
		cin >> income;
		cities.push_back(City(i, income));  // 인덱스 i를 함께 저장
	}

    // 최대 소득 차이 계산
    // getMaximumRangeDifference함수 사용
	int answer = getMaximumRangeDifference(n, k, cities);

    // 결과 출력
	cout << answer << endl;
}

// 메인 함수
int main() {
    // 테스트 케이스 수 선언, 입력
	int caseSize;
	scanf("%d", &caseSize);

    // 각 테스트 케이스에 대해 실행
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);    // 해당 케이스 실행
	}
	
	return 0;
}