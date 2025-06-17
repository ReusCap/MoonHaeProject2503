#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B;  // 현재 시, 분
    cin >> C;       // 요리 시간 (분)
    // 일단 모든 시간을 분으로 변경한다.
    // 그 다음에 24로 /한 몫을 구하고, 24로 나누고
    // 나머지를 %60으로 구함. 
    int total_minutes = A * 60 + B + C;  // 총 분으로 변환
    int end_hour = (total_minutes / 60) % 24;  // 시는 0~23
    int end_min = total_minutes % 60;          // 분은 0~59

    cout << end_hour << " " << end_min << endl;

    return 0;
}
