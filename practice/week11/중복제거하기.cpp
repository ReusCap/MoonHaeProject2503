#include<iostream> // C++ 표준 입출력 위한 헤더
#include<set>	// set 사용 위한 헤더
using namespace std;

// main 함수수
int main() {
	int n;	// 입력할 숫자 개수 n
	scanf("%d", &n);

	// int형 세트 s선언
	// default는 오름차순
	set<int>s;
	
	// n번동안 loop반복
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);	// 숫자 x 입력받음
    
    	//C++ set의 find메소드는 찾는 수가 있다면 해당 iterator를, 없다면 end() iterator를 반환한다.
		if (s.count(x) > 0) { //찾는 수가 있다면 s.find(x) != s.end()
			printf("DUPLICATED\n");	// 이미 있으면 DUPLICATED반환
			// printf("%d\n", *s.find(x));
		}
		else { //찾는 수가 없다면
			s.insert(x); //set에 수를 등록한다.
			printf("OK\n");
		}
	}
	return 0;
} 