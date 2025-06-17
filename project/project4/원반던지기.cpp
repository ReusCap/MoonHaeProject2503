#include <iostream>     // 표준 입출력을 위한 헤더
#include <vector>       // vector 사용을 위한 헤더
#include <stack>        // stack 사용을 위한 헤더

using namespace std;

// 왼쪽부터 오른쪽까지 한 명씩 보면서
// 스택 안에 키가 감소하는 인덱스들만 유지해
// 새 친구가 나타났을 때 자기보다 작은 키들을 하나씩 꺼내며

// 메인함수
int main() {
    int N;              // 친구 수 N명
    cin >> N;           // 사용자로부터 N 입력 받음

    vector<int> height(N);   // 크기 N의 정수 벡터 height 선언 (친구들의 키 저장)
    for (int i = 0; i < N; ++i) {
        cin >> height[i];    // 각 인덱스에 해당하는 친구들 키 입력
    }

    long long answer = 0; // 조건을 만족하는 거리의 총합
    stack<int> stack;   // 인덱스를 저장하는 스택

    for (int i = 0; i < N; ++i) {           // N만큼 순회
        int current_height = height[i];     // 현재 인덱스의 친구들 키 저장

        // 스택이 비어있지 않은 동안 반복
        while (!stack.empty()) {
            int j = stack.top();    // 스택의 맨 위 인덱스
            int x = height[j];      // 그 인덱스에 해당하는 키 값

            answer += (i - j + 1);   // 현재 위치 i와 스택 top의 거리(i-j+1)를 더함

            if (current_height >= x) {
                // 현재 키가 스택 top의 키보다 크거나 같으면 top 제거
                // 이는 current_height가 x보다 크면 두 키 사이의 거리 조건을 만족함을 의미
                stack.pop();
            } else {
                // 현재 키가 더 작으면 더 이상 탐색하지 않고 종료
                // 즉, 조건이 안 맞기 때문에 멈춤
                break;
            }
        }

        stack.push(i); // 현재 인덱스를 스택에 추가
    }

    cout << answer << endl; // 결과 출력

    return 0; // 프로그램 종료
}