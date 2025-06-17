#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 도시 정보 클래스
class City {
public:
    int index;     // 도시 번호
    int income;    // 도시 소득

    City(int idx, int income) : index(idx), income(income) {}

    // 최대 힙용: 소득 내림차순
    bool operator < (const City& other) const {
        return income < other.income;
    }

    // 최소 힙용: 소득 오름차순
    bool operator > (const City& other) const {
        return income > other.income;
    }
};

// 주어진 연속 k개 도시 범위에서 최대 소득 차 구하기
int getMaxIncomeDifference(int n, int k, const vector<City>& cities) {
    int maxDifference = 0;

    // 최대 소득 힙 (내림차순), 최소 소득 힙 (오름차순)
    priority_queue<City> maxHeap;  // top: 가장 소득 높은 도시
    priority_queue<City, vector<City>, greater<City>> minHeap;  // top: 가장 소득 낮은 도시

    // 처음 k-1개 도시 미리 넣어두기
    for (int i = 0; i < k - 1; ++i) {
        maxHeap.push(cities[i]);
        minHeap.push(cities[i]);
    }

    // 슬라이딩 윈도우: k개씩 확인
    for (int i = k - 1; i < n; ++i) {
        // 새 도시 추가
        maxHeap.push(cities[i]);
        minHeap.push(cities[i]);

        // 오래된 도시 제거 (범위 벗어난 것)
        int left = i - k + 1;
        while (maxHeap.top().index < left) maxHeap.pop();
        while (minHeap.top().index < left) minHeap.pop();

        // 현재 구간의 최대 소득 차이
        int diff = maxHeap.top().income - minHeap.top().income;
        maxDifference = max(maxDifference, diff);
    }

    return maxDifference;
}

// 입력 하나 처리
void process() {
    int n, k;
    cin >> n >> k;

    vector<City> cities;
    for (int i = 0; i < n; ++i) {
        int income;
        cin >> income;
        cities.emplace_back(i, income);  // 인덱스 포함해서 저장
    }

    int result = getMaxIncomeDifference(n, k, cities);
    cout << result << '\n';
}

// 메인
int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        process();
    }

    return 0;
}
