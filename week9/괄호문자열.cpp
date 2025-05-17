#include <iostream>   // 표준 입출력 사용을 위한 헤더
#include <string>     // 문자열을 다루기 위한 헤더
#include <vector>     // 벡터 자료구조 사용을 위한 헤더
#include <stack>      // 스택 자료구조 사용을 위한 헤더

using namespace std;

// 괄호 하나를 표현하는 클래스
class Parenthesis {
public:
	bool type;  // 열린 괄호면 true, 닫힌 괄호면 false
	int index;  // 해당 괄호의 인덱스

    // 생성자, index와 type 값을 직접 받아 초기화
	Parenthesis(int index, bool type) {
		this->index = index;
		this->type = type;
	}

    // 생성자, index와 괄호 문자인 '(' 또는 ')'를 받아서 type을 자동 설정
	Parenthesis(int index, char c) {
		this->index = index;
		if (c == '(') { // '('이면 true, ')'이면 false
			this->type = true;
		} else {
			this->type = false;
		}
	}
};

// 괄호 벡터가 VPS(올바른 괄호 문자열)인지 확인하는 함수
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
	// 현재 짝을 찾지 못한 열린 괄호들
    // 닫힌 괄호가 나오면 탑에 저장된 열린 괄호를 삭제해 나감.
    // 삭제만 이루어짐 --> 스택변수로 선언
    // Parenthesis타입 스택 stack선언
	stack<Parenthesis> stack;

	for (int i = 0; i < parentheses.size(); i++) {
		// 왼쪽부터 오른쪽의 괄호를 차례로 조회한다.
        // 벡터 변수이므로 모든 원소 접근 가능
		Parenthesis p = parentheses[i];

		if (p.type == true) {
			// 열린 괄호라면 짝을 찾을 때 까지 스택에 보관한다
			stack.push(p);

		} else if (p.type == false) {
			// 닫힌 괄호 p에 대하여

			if (stack.size() > 0 && stack.top().type == true) {
				// 가장 마지막에 추가된 열린 괄호와 짝을 맞출 수 있으므로 제거한다
				stack.pop();
            // 애초에 닫힌 괄호는 스택에 들어가지 않는다. 그러니 열린 괄호와 매칭 안되면 잘못된 괄호 문자열
			} else {
				// 짝을 맞출 수 있는 열린 괄호가 없다면 올바르지 않은 괄호 문자열이다.
				return false;
			}
		}
	}

	if (stack.size() > 0) {
		// 아직 스택에 짝을 찾지 못한 열린 괄호가 남아있다.
        // 열린 괄호가 남아있으므로 VPS가 아님
		return false;
	}  
    // 스택이 비어있으면 모든 괄호 짝이 맞음(VPS)
	return true;
}

// 한 테스트 케이스에 대해 문자열 입력받고 VPS 판단하여 결과 출력
void process(int caseIndex) {
    // 괄호 문자열 입력 
	string str;
	cin >> str;

    // Parenthesis타입 parentheses벡터 선언
	vector<Parenthesis> parentheses;
    // 벡터는 (front-back) 모든 위치의 원소 접근 가능(동적 배열로 사용)
    // 스택은 탑 위치의 원소만 접근 가능
	for (int i = 0; i < str.length(); ++i) {
        // 문자열을 하나씩 Parenthesis 객체로 변환해 벡터에 저장
		parentheses.push_back(Parenthesis(i,str[i]));
	}

    // 올바른 괄호 문자열인지 검사, isValidParentheses 함수 호출
	bool isValid = isValidParentheses(parentheses);

    // 결과 출력
	if (isValid) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
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