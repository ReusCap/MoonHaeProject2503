#include <stdio.h>     // C 스타일 입출력을 위한 헤더
#include <map>         // C++에서 map 사용을 위한 헤더

using namespace std;

int main() {
    int N;
    // 사용자로부터 정수 N 입력 받음 (총 입력될 숫자의 개수)
    scanf("%d", &N);

    // map 자료구조 선언
    // key: 입력된 정수 X
    // value: 그 정수 X가 지금까지 몇 번 등장했는지를 나타내는 빈도수
    map<int, int> frequencyMap;

    // N개의 정수를 입력받아 처리
    for (int i = 0; i < N; i++) {
        int X;
        // 정수 X 입력 받기
        scanf("%d", &X);

        // X의 빈도수를 1 증가시킴
        // map에 X가 없으면 자동으로 value가 0으로 초기화된 후 1이 됨
        frequencyMap[X]++;

        // map.size()는 현재까지 서로 다른 숫자의 개수를 의미
        // frequencyMap[X]는 현재 숫자 X가 몇 번 등장했는지를 의미
        printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);
    }

    return 0;

	// 마지막에 frequencyMap의 키, 벨류 모두 출력 경우
	/*
	map<int, int>::iterator it;
	for (it=frequencyMap.begin(); it!=fequencyMap.end(); it++)
	{
		printf("%d %d\n", it ->first, it ->second);
	}
		2 1
		3 2
		5 2
		최종 저장 형태

	for (const auto& p : frequencyMap) {
    	cout << p.first << p.second << '\n';
	}
	*/
}
