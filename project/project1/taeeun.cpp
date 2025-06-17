#include <iostream> // C++ 입출력 스트림 사용
using namespace std;

// 빠진 페이지를 찾아 잉크 사용량을 계산하는 함수
int calculateInk(int* page, int n, int m) {
    // 최대 n개까지 빠질 수 있으므로 n 크기로 동적 배열 생성
    int* missingPages = new int[n];
    // missing 배열에 몇 개나 저장됐는지 기록
    int missingCount = 0;

    // 1부터 n번까지 빠진 페이지 찾기
    for (int i = 1; i <= n; i++) {
        // 현재 i 페이지가 바닥에 있는지 확인하는 변수
        bool found = false;
        // 바닥에 있는 페이지들 중 i가 있는지 찾기
        for (int j = 0; j < m; j++) {
            if (page[j] == i) {
                // 찾았으면 found를 ture로 바꾸고 break
                found = true;
                break;
            }
        }
        // 못찾았다면 missingPages배열에 추가
        if (!found) {
            missingPages[missingCount] = i;
            // 빠진 페이지 개수 증가
            missingCount++;
        }
    }

    // 총 잉크 사용량 저장 변수
    int result = 0;
    // 마지막으로 인쇄한 페이지 번호
    int last = 0;

    // missingpages배열 순회하며 잉크 사용량 계산
    for (int i = 0; i < missingCount; i++) {
        // 현재 인쇄할할 페이지
        int curr = missingPages[i];
        // 첫 인쇄인 경우
        if (last == 0) {
            // 7만큼의 잉크 사용용
            result += 7;
        // 첫 인쇄가 아닌경우
        } else {
            // 앞의 페이지와 현재 페이지 번호의 차이를 diff 변수에 저장
            int diff = curr - last;
            // 비용 변수에 페이지 번호차이 곱하기 2를 한다.
            int cost = diff * 2;
            // 만약 cost가 7보다 작으면 총 잉크사용량에 그대로 더하고
            if (cost < 7) {
                result += cost;
            // 7보다 크거나 같으면 7을 잉크 사용량에 더한다.
            } else {
                result += 7;
            }
        }
        // 마지막 인쇄 페이지를 현재 페이지로 업데이트
        last = curr;
    }

     // 동적 배열 해제
    delete[] missingPages;
    // 총 잉크 사용량 반환
    return result;
}

int main() {
    // int형으로 논문의 마지막 페이지 번호 n과 바닥에 있는 논문의 장 수 m 선언언
    int n, m;
    // cin으로 n과 m 입력 받는다.

    cin >> n >> m;

    // page 동적 배열 포인터 생성
    int* page = new int[m];

    // 바닥에 있는 페이지들 입력받기
    for (int i = 0; i < m; i++) {
        cin >> page[i];
    }
    int answer = calculateInk(page, n, m);

    // 잉크 양 출력
    cout << answer << endl;

    // 메모리 해제
    delete[] page;
   
    return 0;
}
