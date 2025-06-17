#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <iostream> // C++ 스타일 입출력을 위한 헤더파일 
using namespace std;    // std:: 생략 위해

bool isPrime(int N)
{   
    // N이 1이면 약수 1개니 false
    if (N == 1){
        return false;
    }
    // 약수 개수 카운트해서 2개면 소수로 판단 방법도 있으나 시간복잡도가 O(N)이라 안쓰겠다.
    int cnt = 0;
    // sqrt함수 쓰면 실수가 나오니까 i * i < N으로 조건 설정
    // for문을 줄임으로써 시간복잡도를 엄청나게 줄일 수 있다.
    for (int i=2; i*i <= N; i++){
        if(N % i==0){
            // 만약 1개라도 1과 본인 제외 약수 나오면 false반환
            return false;
        }
    }
    return true;
}

// 테스트 케이스 실행 함수
void testcase(int caseIndex){
    // 소수 판별받을 정수 n 입력받음
    int n;
    scanf("%d", &n);

    // 소수 판별 함수 isPrime 실행
    bool result = isPrime(n);

    // Case#숫자 출력
    printf("Case #%d\n", caseIndex);
    // 만약 함수 결과(소수)가 참이면 YES를, 아니면 NO를 출력한다.
    if (result)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main()
{   
    // 테스트 케이스 int형으로 선언
    int caseSize;
    // 테스트 케이스 개수 입력
    scanf("%d", &caseSize);
    
    // for문으로 testcase 1부터 함수 반복 처리
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex +=1)
    {
        testcase(caseIndex);
    }
    return 0;
}