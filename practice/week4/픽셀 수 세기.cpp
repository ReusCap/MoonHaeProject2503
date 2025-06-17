#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <iostream> // C++ 스타일 입출력을 위한 헤더파일 
using namespace std;    // std:: 생략 위해

// 주어진 좌표가 원 내부에 있는지 판단하는 함수
bool isInside(long long x, long long y, long long R)
{   
    // 원 내부에 있으려면 x^2 + y^2 < R^2
    long long sqd = x*x + y*y;
    // 안에 있으면 true
    if (sqd < R*R)
        return true;
    // 안에 없으면 false
    return false;
}
// 각 테스트 케이스 처리 함수
void testcase(int caseIndex){
    long long R;    // 반지름 R 변수
    scanf("%lld", &R);  // R 입력받음

    long long sum = 0;  // 1사분면의 총 픽셀 수 0으로 초기화 
    long long y = R;    // y는 R부터 시작해서 점차 감소
    
    // x는 0부터 R까지 점차적으로 증가
    for(long x=0; x<=R; x++){

        long long height = 0;   // 해당 x좌표에 y방향 몇개 픽셀 원 안에 들어가는지

        // y값을 점차 줄여가며 (x,y)가 원 안에 들어가는지 검사
        for (; y>=0; y--){
            if (isInside(x,y,R)){
                // (x, y)가 원 내부에 있다면, 그 높이는 y+1 (0부터 y까지 포함되므로)
                height = (y+1);
                break;
            }
        }
        // 너비가 1인 세로 막대 하나로 간주하여 높이만큼 픽셀 수 추가
        sum += height;
    }
    //결과 출력
    printf("#%d\n", caseIndex);
    // 1사분면 픽셀 수 구했으니 4사분면 전체 구하기
    printf("%lld\n", sum * 4);
}

int main()
{
    int caseSize;
    // 테스트 케이스 개수 입력
    scanf("%d", &caseSize);
    // 각 테스트 케이스에 대해 처리
    // 테스트 케이스 1부터 실행행
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex +=1)
    {
        testcase(caseIndex);
    }
    return 0;
}