#include <iostream>     // C++ 스타일 입출력을 위한 헤더
#include <string>       // 문자열(string) 사용을 위한 헤더
#include <map>          // map 컨테이너 사용을 위한 헤더

using namespace std;

int main() {
    int N;
    // 입력받을 투표 수 (후보 이름의 개수)
    cin >> N;

	// 각 후보 이름과 득표 수를 저장하는 key-value Map
	map<string, int> frequencyMap;

	int maxFrequency = 0; // 가장 많은 득표수 저장
  
  	//각 이름이 하나 추가될 때마다 현재까지의 최다 특표 값 갱신, 최다 득표 후보 리스트를 갱신해간다.
	for (int i = 0; i<N; i++) {
		string st;
		cin >> st;	// 후보 이름 입력
		frequencyMap[st]++;	// 해당 후보의 득표 수 +1

		int k = frequencyMap[st];	// 지금 후보의 누적 득표 수

		// 지금 후보가 현재까지 최다 득표자보다 많다면 갱신
		if (k>maxFrequency) {
			maxFrequency = k;
		}
	}

	// 최대 득표 후보 수를 출력한다.
	cout << maxFrequency << endl;

	// 최대 득표를한 동점 후보들 이름을 사전순으로 출력한다.
	map<string, int>::iterator it;
	// 최다 득표 수를 받은 후보들을 사전순으로 출력
    // map은 기본적으로 key(문자열)가 사전순으로 정렬되므로 begin()부터 순회하면 자동 정렬됨
	for(it = frequencyMap.begin(); it!=frequencyMap.end(); it++){
		// 득표 수가 최다 득표 수와 같다면 출력 대상
		if(it->second == maxFrequency){
			// printf를 사용했기 때문에 string을 C 문자열로 변환 필요
			printf("%s ", it->first.c_str());
		}
	}
	cout << endl;
}