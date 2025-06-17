/* 소수의 판별 **** 출제 예정!!!
testcase쓰면 
int caseIndex = 1; caseIndex <= caseSize; caseIndex
이걸로 caseindesx출력하고 결과 출력
N이 소수인지 판단.
1. N==1이면 소수 아니니 false반환
2. N의 약수 i가 있나 검사할 때 어차피 최대 약수 i는
i <= 루트N이여야함. 그런데 sqrt는 실수니까 안돼 i제곱 활용
for(int i=2; i*i<=N; i++)로 if (N%i==0)이면 false반환
*/

/* 데스트니 : 거리 동일한 좌표들 거리랑 개수 반환
    #include <climits>사용시 INT_MAX같은거 사용 가능
    point2d라고 클래스 생성. x,y좌표가 변수
    public으로
    this->x = x;
    this->y = y;하고
    거리제곱계산함수
    int dx = this->x - target.x;
    int dy = this->y - target.y;
    return dx*dx + dy*dy
    실제 거리반환함수로 sqrt(위의 결과)
*/

/* 픽셀 세기 **다시봐야함함
    inside하무로
    x*x + y*y < r*r로 해서 있으면 true

*/