#include <iostream>     // 입출력 스트림 사용을 위한 헤더
#include <cstdio>       // C 스타일 입출력을 위한 헤더

using namespace std;

// 두 직사각형의 좌표를 받아서 겹치는 영역의 넓이를 계산하는 함수
// (la, ra, ta, ba): 첫 번째 직사각형의 왼쪽, 오른쪽, 위, 아래 좌표
// (lb, rb, tb, bb): 두 번째 직사각형의 왼쪽, 오른쪽, 위, 아래 좌표
int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)
{   
    // 
    int l,r,t,b;

    // 겹치는 구간의 왼쪽, 오른쪽, 위, 아래 좌표 계산
    l = max(la, lb);    // 겹치는 왼쪽 좌표: 더 큰 왼쪽값
    r = min(ra, rb);    // 겹치는 오른쪽 좌표: 더 작은 오른쪽값
    t = min(ta, tb);    // 겹치는 위쪽 좌표: 더 낮은 위쪽값
    b = max(ba, bb);    // 겹치는 아래쪽 좌표: 더 높은 아래쪽값
    
    // 겹치는 영역이 유효한 경우에만 넓이 계산
    if( l<=r && b <= t){
        return ((r-l)*(t-b));   // 넓이 = (가로 길이) * (세로 길이)
    }

    // 겹치는 부분이 없으면 넓이는 0
    return 0;
}

// 한 테스트 케이스에 대한 입력 처리 및 결과 출력 함수
void test_case()
{
    int ax, ay, bx, by;     // 첫 번째 직사각형의 두 꼭짓점
    int px, py, qx, qy;     // 두 번째 직사각형의 두 꼭짓점

    // 첫 번째 직사각형 입력 (두 꼭짓점: (ax, ay), (bx, by))
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);

    // 두 번째 직사각형 입력 (두 꼭짓점: (px, py), (qx, qy))
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    // 직사각형 a
    int la, ra, ba, ta;
    la = min(ax, bx);   // 왼쪽
    ra = max(ax, bx);   // 오른쪽
    ta = max(ay, by);   // 위
    ba = min(ay, by);   // 아래 

    // 직사각형 b
    int lb, rb, bb, tb;
    lb = min(px, qx);   // 왼쪽
    rb = max(px, qx);   // 오른쪽
    tb = max(py, qy);   // 위
    bb = min(py, qy);   // 아래 

    // 두 사각형의 겹치는 영역의 넓이 계산
    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

    // 결과 출력
    printf("%d\n", answer); 
}

// 메인함수
int main(){

    // 테스트 케이스 수
    int t;
    // 입력받기
    scanf("%d", &t);

    // 테스트 케이스 수 만큼 test_case()실행
    for(int i=0; i<t; i++)
        test_case();

    return 0;
}