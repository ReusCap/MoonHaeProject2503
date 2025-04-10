#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 벡터 사용을 위한 헤더파일
using namespace std;    // std:: 생략 위해

// 자연수 N을 구성하는 모든 소인수를 반환하는 함수
vector<long long> factorize(long n){
    // factors벡터 선언언
    vector<long long> factors;

    // 정수형이니까 div * div <= n으로 식 작성
    // for문은 소수인 2부터 시작한다.
    for(int div = 2; div * div <= n; div += 1){ // sqrt(N)이하의 자연수 div에 대해서
        while(n%div ==0){
            // div이 N의 약수라면?
            // 이 때, div보다 작은 약수는 모두 처리되었으므로 div은 소인수임이 보장
            factors.push_back(div);
            // N에서 div을 소거해준다.
            // 그러므로 이후에는 div을 제외한 소인수를 찾게된다.
            n /= div;
        }
    }
    if (n>1){
        // 소인수를 찾지 못하고 남아있는 N이 존재한다면, 소수일 수 밖에 없다.
        // 이를 소인수에 추가한다.
        factors.push_back(n);
    }
    // 소인수 벡터 반환
    return factors;
}

// 한 테스트 케이스를 계산하고 결과 출력하는 함수
void process(int caseIndex){
    // 소인수 분해할 숫자 입력
    long long n;
    scanf("%lld", &n);

    // factors 벡터 생성 후, 소인수 분해 실행값 저장 factorize반환값(벡터)
    vector<long long> factors = factorize(n);

    // 케이스 번호 출력
    printf("#%d:\n", caseIndex);
    // 배열 사이즈 만큼 공백 두고 출력력
    for (int i=0; i< factors.size(); ++i){
        // 첫번째 인덱스 아니면 공백 앞에 둠
        if(i>0){
            printf(" ");
        }
        printf("%lld", factors[i]);
    }
    // 다음 케이스 위해 줄바꿈
    printf("\n");
} 

// 메인함수
int main()
{   
    // 테스트 케이스 선언하고 입력받기
    int caseSize;
    scanf("%d", &caseSize);

    // for문으로 테스트 케이스 실행
    for (int caseIndex = 1; caseIndex <= caseSize; caseSize++){
        // process함수로 테스트 케이스 돌린다.
        process(caseIndex);
    }
    return 0;
}