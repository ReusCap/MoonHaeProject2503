#include <iostream>      // C++ 입출력 기능 헤더파일 
#include <iomanip>       // 입출력 포맷 제어용 헤더 파일 (setprecision(2))
#include <vector>        // 동적 배열 자료구조 vector 사용 위한 헤더
#include <cmath>         // 수학 함수들 (sqrt 등)사용 위한 헤더
#include <set>           // 중복 없는 정렬된 집합 set 사용 위한 헤더
#include <algorithm>     // max 함수 사용 위한 헤더

using namespace std;     // std:: 생략 가능하게 함

// 2차원 평면의 한 점을 표현하는 클래스
class Point2D {
public:
	int x;      // x 좌표
	int y;      // y 좌표
	int index;  // 인덱스

	// 생성자: index, x, y를 초기화
	Point2D(int index, int x, int y) {
		this->index = index; // 멤버 변수 index에 매개변수 값 할당
		this->x = x;         // 멤버 변수 x에 매개변수 값 할당
		this->y = y;         // 멤버 변수 y에 매개변수 값 할당
	}

	// 생성자 오버로딩: index를 생략한 버전 (index는 기본값 1로)
	Point2D(int x, int y) {
		this->index = 1;     // 기본값 1
		this->x = x;
		this->y = y;
	}


	// 두 점 사이의 제곱거리 계산 (정수형으로 반환)
	// this와 target사이의 x와 y좌표 비교
	long long getSquaredDistanceTo(Point2D target) {
		long long dx = abs(this->x - target.x);  // x 좌표 차이 절댓값
		long long dy = abs(this->y - target.y);  // y 좌표 차이 절댓값
		return dx * dx + dy * dy;               // 피타고라스 정리 (제곱거리 반환)
	}


	// 두 점 사이의 실수 거리 계산 (실제 거리)
	double getDistanceTo(Point2D target) {
		long long sqd = this->getSquaredDistanceTo(target);  // 제곱거리 먼저 구함
		return sqrt(sqd); // 루트 씌워서 실제 거리 반환
	}

	// < 연산자 오버로딩: set에 들어가기 위해 비교 기준 정의
	bool operator < (const Point2D& other) const {

		// x좌표가 다르다면 x좌표를 기준으로 비교한다.
		if (this->x != other.x) {     // x가 다르면 x 기준 정렬
			return this->x < other.x;
		}
		// x좌표가 같다면 y좌표를 기준으로 비교한다.
		return this->y < other.y;     // x가 같으면 y 기준 정렬
	}
};

// 가장 넓은 정사각형의 넓이(제곱거리)를 반환하는 함수
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0;	// 최대 넓이를 저장할 변수 (초기값 0)

	// 모든 점을 Set에 저장한다
	set<Point2D> pSet;
	for (int i = 0; i < n; i += 1) {
		pSet.insert(points[i]);
	}
	// 모든 점 쌍 (pa, pb)에 대해 검사
	for (int i = 0; i < n; i += 1) {
		Point2D pa = points[i];	// 첫 번째 점 선택

		for (int j = 0; j < n; j += 1) {
			Point2D pb = points[j];	// 두 번째 점 선택

			if (i==j) continue;

			// 두 기준점 pa와 pb를 지정한다.
			// 선분 pa-pb가 정사각형의 한 변이라고 하자.

			// 두 점의 거리(선분의 길이)의 제곱 구하기, 이 값값은 정사각형의 넓이가 된다.
			long long area = pa.getSquaredDistanceTo(pb);

			// 이미 구한 사각형보다 넓이가 작을 수 밖에 없다면 건너뛴다.
			if (area < answer)
				continue;

			// pa->pb방향의 x, y 좌표에 대한 거리(dx, dy)를 구한다
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			// 벡터 <dx, dy>를 90도로 회전시키면 <-dy, dx>(왼쪽 아래 방향향)가 된다.
			// pa와 pb에 벡터 <-dy, dx>를 각각 더해 정사각형을 구성하는 두 점
			// pd, pc를 구한다.
			Point2D pd(pa.x - dy, pa.y + dx);  // pa 기준 90도 회전된 점
			Point2D pc(pb.x - dy, pb.y + dx);  // pb 기준 90도 회전된 점


			// pd, pc이 pSet에 존재하는 점인지 검사
			// pd, pc 두 점이 실제로 존재하면 정사각형 완성 가능
			// 여기서는 pSet.count()>0 로 계산
			if (pSet.count(pc)>0 && pSet.count(pd)>0) {
				// 현재 넓이로 최대값 갱신
				answer = max(answer, area);
			}
		}
	}

	// 최대 넓이를 반환
	return answer;
}

// 테스트 케이스 하나 처리하는 함수
void process(int caseIndex) {
	int n;
	cin >> n;  // 점의 개수 입력

	vector<Point2D> points;  // 점들을 저장할 벡터 선언

	// n개의 점 좌표 입력받기
	for (int i = 0; i < n; i += 1) {
		int x, y;
		cin >> x >> y;  // 좌표 입력
		points.push_back(Point2D(i, x, y));  // Point2D 객체 생성해서 벡터에 추가
	}

	double answer = getMaximumSquareArea(n, points);  // 최대 정사각형 넓이 계산

	cout << fixed << setprecision(2) << answer << endl;  // 소수점 둘째 자리까지 출력
}

// 메인함수
int main() {
	int caseSize;
	cin >> caseSize;  // 테스트 케이스 개수 입력

	// 각 테스트 케이스 처리
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);  // 해당 번호 케이스 실행
	}
}
