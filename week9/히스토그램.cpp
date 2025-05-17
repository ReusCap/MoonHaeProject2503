#include <iostream>   // 표준 입출력 사용 위한 헤더
#include <vector>     // 벡터 자료구조 사용 위한 헤더
#include <stack>      // 스택 자료구조 사용 위한 헤더
#include <cmath>      // abs 함수 사용 위한 헤더
#include <algorithm>  // max 함수 사용 위한 헤더더

using namespace std;

// 각 히스토그램 막대 하나를 표현하는 클래스
class Histogram {
public:
	int height;    // 히스토그램의 높이
	int leftX;     // 인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
	int rightX;    // 히스토그램의 오른쪽 변의 x좌표

	Histogram() { }

    // 생성자: 막대의 인덱스와 높이를 받아 초기화
	Histogram(int index, int height) {
		this->leftX = index;    // 막대의 시작 위치
		this->rightX = this->leftX + 1;   // 각 히스토그램은 너비가 1이므로 끝위치는 +1
		this->height = height;  // 높이도 저장
	}

};

// 히스토그램에서 가장 넓은 직사각형의 넓이를 구하는 함수
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
	long long answer = 0;    // 최대 직사각형의 넓이 (반환할 값)

    // Histogram 타입의 sdk이름의 stack을 선언
	// 현재까지 오른쪽으로 확장 가능한 히스토그램을 저장하는 스택을 선언한다
	// 이 스택은 히스토그램의 높이를 기준으로 오름차순을 유지하도록 구성된다
	stack<Histogram> sdk;

	// 스택이 비는 상황을 방지하고 첫 번째 막대의 계산을 단순하게 처리하기 위해
	// 왼쪽 끝에 높이 0인 가상의 히스토그램을 하나 추가한다
	sdk.push(Histogram(-1, 0));

    // 히스토그램의 모든 막대를 순서대로 처리한다
	// 마지막에 오른쪽 끝에 높이 0인 막대를 하나 더 추가하여 스택을 완전히 비울 수 있도록 한다
	for(int i = 0 ; i < histograms.size() + 1 ; i++) {
        // Histogram 타입 변수 h 선언
		Histogram h;

        // 현재 인덱스의 실제 히스토그램을 가져온다
		if(i < histograms.size()) {
			h = histograms[i];
        // 마지막 인덱스인 경우, 오른쪽 끝에 높이 0인 가상의 히스토그램을 추가한다
		} else { 
			h = Histogram(histograms.size(), 0);
		}

		// 현재 막대가 스택에 있는 마지막 막대보다 작거나 같은 경우
		// 스택에 쌓여 있던 막대는 더 이상 오른쪽으로 확장할 수 없다고 판단하고 넓이를 계산하고 POP
		while (sdk.size() > 1 && sdk.top().height >= h.height){
			// 확장이 종료된 막대를 꺼낸다
			Histogram lh = sdk.top();
			sdk.pop();

			// 이 막대의 왼쪽 끝을 나타내는 이전 막대를 가져온다
			Histogram bh = sdk.top();

			// 너비는 현재 막대의 leftX와 왼쪽 막대의 rightX 사이의 거리로 계산한다
			long long width = abs(h.leftX - bh.rightX);
            // 높이는 방금 꺼낸 막대의 높이를 사용한다
			long long height = lh.height;
            // 넓이는 너비와 높이의 곱으로 계산된다
			long long area =  width * height;

			// 기존에 저장된 최대 넓이와 비교하여 더 큰 값을 갱신 후 저장.
			answer = max(answer, area);
		}

		// 현재 막대 h는 이후의 막대들과 비교하여 확장 가능성이 있으므로 스택에 추가한다
		sdk.push(h);
	}

    // 최대 넓이 반환
	return answer;
}

// 테스트케이스 하나 처리하는 함수
void process(int caseIndex) {
    // 막대 수 선언, 입력
	int n;
	cin >> n;
    
    // Histogram 타입 histograms 벡터 선언
	vector<Histogram> histograms;
	for(int i = 0 ; i < n ; i ++) {
        // height을 입력한다.
		int height;
		cin >> height;
        // 각 막대를 Histogram 객체로 만들어 (생성자(인덱스,높이))형태로 벡터에 저장
		histograms.push_back(Histogram(i, height));
	}

    // 최대 직사각형 넓이 계산
	long long answer = getLargestRectangleArea(histograms);
    // 결과 출력
	cout << answer << endl;
}

// 메인 함수
int main() {
    // 테스트 케이스 수 선언, 입력
	int caseSize;
	cin >> caseSize;

    // 각 테스트 케이스마다 처리
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}