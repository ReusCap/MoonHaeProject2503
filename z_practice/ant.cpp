#include <iostream>
using namespace std;
// 개미 문제
int main() {
    // 격자공간 가로, 세로 w와 h
    int w, h;
    cin >> w >> h;
    // 개미의 출발지 p,q좌표표
    int p, q;
    cin >> p >> q;
    // 개미가 움직일 시간 t
    int t;
    cin >> t;

    // 시간에 따른 x좌표 구하기
    // 개미의 2배 거리인 2w로 나눠서 판단
    // 만약 나눴을때 w보다 크면 2w에서 x만큼 빼면 실제 x다.

    int x = (p+t)%(2*w);
    if (x>w){
        x = 2*w-x;
    }
    // 시간에 따른 y좌표 구하기
    // y도 동일
    int y = (q+t)%(2*h);
    if (y>h){
        y = 2*h-y;
    }

    cout << x << " " << y << endl;

    return 0;
}
