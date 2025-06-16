#include <iostream>     // 표준 입출력을 위한 헤더
#include <vector>       // vector 사용을 위한 헤더
#include <queue>        // priority_queue 사용을 위한 헤더
#include <algorithm>    // sort 함수 사용을 위한 헤더
using namespace std;

// 고객 정보를 담는 클래스
class Person {
public:
    int cash;   // 고객이 예치하려는 현금
    int time;   // 고객이 기다릴 수 있는 최대 시간 (은행이 닫히기 전까지 가능한 시간)

    // 생성자: 고객 정보를 초기화
    Person(int c, int t){
		this->cash = c;
		this->time = t;
	}

	bool operator<(const Person& other) const {
        return time < other.time;
	}
};

// 메인함수
int main() {
    int n, t;   // n: 고객 수, t: 은행이 닫히기까지 남은 시간(분)
    cin >> n >> t;

    vector<Person> people; // 고객 정보를 저장할 벡터

    // 고객 정보 입력 받기
    for (int i = 0; i < n; ++i) {
        int ci, ti;           // 현금과 시간 입력
        cin >> ci >> ti;
        people.push_back(Person(ci, ti));  // Person 객체를 벡터에 추가
    }

    // 고객들을 시간 기준으로 오름차순 정렬
    // 나중에 시간 t-1부터 0까지 거꾸로 탐색할 때 유리하게 정렬해 둠
    sort(people.begin(), people.end());

    // 현금을 기준으로 가장 큰 값을 우선 처리하기 위한 최대 힙
    // priority_queue는 기본적으로 최대 힙 (top이 가장 큰 값)
    priority_queue<int> pq;

    int idx = people.size() - 1;  // 마지막 인덱스부터 거꾸로 탐색
    int total = 0;                // 최종 확보한 현금의 합계

    // 현재 시간을 t-1부터 0까지 역순으로 순회
    // 즉, 가장 늦은 시간부터 가능한 고객을 최대한 배정해 나간다
    for (int curTime = t - 1; curTime >= 0; --curTime) {

        // 해당 시간에 가능한 고객들을 우선순위 큐에 삽입
        // 현재 시간 curTime 이상 기다릴 수 있는 고객만 추가
        while (idx >= 0 && people[idx].time >= curTime) {
            pq.push(people[idx].cash); // 현금을 우선순위 큐에 추가
            idx--;                     // 이전 고객으로 이동
        }

        // 해당 시간에 가장 많은 현금을 내는 고객을 선택
        if (!pq.empty()) {
            total += pq.top();  // 최대 금액 추가
            pq.pop();           // 해당 고객 처리 완료 → 큐에서 제거
        }
    }

    // 최종 현금 총합 출력
    cout << total << endl;

    return 0; // 프로그램 종료
}
