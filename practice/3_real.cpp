#include <iostream>
#include <string>
// 이 헤더를 추가하면 setw와 setfill사용 가능
#include <iomanip>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    int total_seconds = 0;

    for (int i = 0; i < n; ++i) {
        string time_str;
        cin >> time_str;

        // str[0]같은 경우는 char형이어서 stoi()가 못바꿔줌
        // stoi쓰고 싶으면 string s(count, char);로 string타입으로 바꿔주고 해야함
        // 근데 저 string함수는 반복해주는 함수다. 예를 들어 s(5,'7')하면 77777반환 그니까 쓰지마
        // int minutes = stoi(string(1,time_str[0]));
        int minutes = time_str[0] - '0';
        // substr(출발인덱스, 자를 길이) -> 문자열 잘라줌 
        // stoi(문자열) -> int형으로 바꿔줌
        int seconds = stoi(time_str.substr(2, 2));

        total_seconds += minutes * 60 + seconds;
    }

    // 크로스페이드 시간은 (n - 1) * c초만큼 전체 시간에서 겹침
    total_seconds -= (n - 1) * c;

    // hh:mm:ss로 변환
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    // setw(n): 출력 필드의 너비를 n으로 설정합니다.
    // setfill(c): 출력 자리수가 모자랄 때 채울 문자를 설정합니다.

    cout << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << ":"
         << setw(2) << setfill('0') << seconds << "\n";

    return 0;
}
