#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <cmath>    // 수학 함수 이용 위한 헤더파일
#include <climits>  // INT_MAX 처럼 최대/최솟값 사용 위한 헤더파일
#include <iostream> // C++ 스타일 입출력을 위한 헤더파일 
using namespace std;    // std:: 생략 위해

// 2차원 평면 좌표 클래스
class Point2D{
// private (접근지정자) 클래스 외부 접근 불가
private:
    // x좌표와 y좌표 선언
    int x;
    int y;

// public (접근지정자) 클래스 외부 접근 가능
public:
    // 생성자, 디폴트는 (0, 0)
    Point2D(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }

    // target과의 거리 제곱 계산 함수
    int getSquaredDistanceTo(const Point2D &target) const {
        // 절댓값으로 target과의 좌표차를 dx랑 dy저장
        int dx = abs(this->x - target.x);
        int dy = abs(this->y - target.y); 
        // 각 제곱 합을 리턴
        return dx*dx + dy*dy;
    }

    // target과의 거리 계산 함수
    double getDistanceTo(const Point2D &target) const {
        double sqd = (double) this -> getSquaredDistanceTo(target);
        // sqrt로 실제 거리 반환
        return sqrt(sqd);
    }
};

// 메인함수
int main()
{   
    // 천체의 수 n
    int n;
    // Point2D 타입의 객체들을 저장할 포인터
    Point2D *points;

    // 점의 개수 입력
    scanf("%d", &n);
    // new를 사용해 n개의 Point2D객체 배열을 동적 할당
    points = new Point2D[n];

    // for문으로 x와 y를 points 배열에 저장
    for (int i=0; i<n; i++){
        int x,y ;
        scanf("%d %d", &x, &y);

        points[i] = Point2D(x,y);
    }

    // 가장 짧은 거리에 INT_MAX(32비트 약 21억)저장
    int min_sqd = INT_MAX;
    // 가장 짧은 거리 쌍 카운터 0으로 저장장
    int min_cnt = 0;

    // 모든 점 쌍에 대해 거리 제곱 계산
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            // getSquaredDistanceTo함수를 사용해서 거리 제곱을 구한다.
            int sqd = points[i].getSquaredDistanceTo(points[j]);
            // 만약 min_sqd보다 sqd가 작으면 업데이트
            if (sqd <min_sqd){
                min_sqd =sqd;
                // min_cnt를 1로 초기화
                min_cnt = 1;
            // 만약 min_sqd와 같은 쌍 발견하면 min_cnt카운터 ++한다.
            } else if(sqd == min_sqd){
                min_cnt++;
            }
        }
    }

    // distance에 sqrt로 제곱근 저장
    double distance = sqrt(min_sqd);
    // 소수점 1의 자리수까지 반올림하여 출력
    printf("%.1f\n", distance);
    // 최소거리만큼 떨어진 천체 쌍 수 출력
    printf("%d\n", min_cnt);

    // 동적 메모리 해제
    delete[] points;
    return 0;
}