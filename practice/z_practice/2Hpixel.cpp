#include <iostream>
using namespace std;

// 주어진 좌표가 반지름 R의 원 안에 있는지 여부
bool isInside(long long x, long long y, long long R) {
    return x * x + y * y < R * R;
}

// 각 테스트 케이스 실행 함수
// 1사분면 값의 합 sum과 y를 R로 받고, x를 for문 인자로 받아.
// 이제 for문으로 x증가시 for문으로 y감소시키며 if문으로 isInside로 가능 여부 판단
// 만약 안에 있다면 아까 정의한 height변수에 집어넣는다. 근데 여기서 y+1을 집어넣는걸로 판단
void testcase(int caseIndex){
    long long R;
    cin >> R;
    long long sum = 0;
    long long y = R;

    for (long x=0; x<=R; x++){
        long long height = 0;

        for (; y>=0; y--){
            if (isInside(x,y,R)){
                height = (y+1);
                break;
            }
        }
        sum += height;
    }
    cout << '#' << caseIndex << endl;
    cout << sum*4 << endl;
}


int main() {
    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        testcase(i);
    }

    return 0;
}
