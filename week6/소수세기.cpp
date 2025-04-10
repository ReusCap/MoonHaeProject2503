#include <cstdio>   // C 스타일 입출력을 위한 헤더파일
#include <vector>   // 동적 배열 벡터 사용 위한 헤더
using namespace std;    // std:: 생략 위해

// 에라토스테네스의 체 클래스
// 1부터 n까지 모든 수에 대해 소수 여부를 미리 계산하는 역할
class Sieve{
// public (접근지정자) 클래스 외부 접근 가능
public:
    int maximumValue;       // 에라토스테네스의 체에서 다룰 가장 큰 범위의 값
    vector<bool> isPrime;   // 각 숫자별 소수 여부

    // 생성자 : 소수 범위 정하고, 체 초기화 설정
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue;
        // false값으로 초기화
        this->isPrime.assign(maximumValue + 1, false);  // 먼저 false로 초기화
        this->fillSieve();  // 체 알고리즘 실행하여 isPrime 채우기
    }

    // 특정 숫자가 소수인지 판단   
    bool isPrimeNumber(int num) const {
        // true인지 false인지 반환환
        return this-> isPrime[num];
    }
    // isPrime 배열의 값을 채우는 함수
    void fillSieve(){
        isPrime.assign(this->maximumValue, true);   // 처음에는 모두 소수라고 저장
        isPrime[0] = isPrime[1]=false;  // 0과 1은 소수가 아니므로 미리 처리한다.
        
        for(int num = 2; num<= maximumValue; num +=1){
            // [2,N]사이의 모든 자연수 num에 대해
            if(isPrime[num]== false){
                // 이미 소수가 아니라고 체크되었다면 건너 뛴다.
                continue;
            }
            // 이때 num은 소수다.
            // 그러므로 num의 모든 배수를 소수가 아니라고 체크해야한다.
            // num보다 작은 k에 대해 mul=num*num으로 표현되는 모든 자연수는 이미 처리되었다.
            // 그러므로 (mul = num*num)부터 끝까지 처리. 최대 100만의 제곱까지 --> long long타입
            for (long long mul = (long long)num* num; mul <= maximumValue; mul += num){
                // 이때 mul에 대해서, mul을 나누는 최초의 소인수 num이 등장한다.
                // 이 정보를 저장해두면 소인수 분해를 할 때 유용하다.
                // long long타입을 int타입으로 변환시켜준다.
                int index = (int) mul;
                isPrime[index] = false; // 이제 이 범위 안을 모두 false로 바꿔준다.
            }

        }   
    }
};

// sieve를 이용해 [from, to] 범위 내의 모든 소수를 찾아 반환하는 함수
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve){
    // 소수 벡터 선언언
    vector<int> primes;

    // from부터 to까지 반복하며 소수 여부 확인
    for(int num = from; num <= to; num+=1){
        // true이면 -> 곧 소수이면 push_back한다.
        if(sieve.isPrimeNumber(num)){
            primes.push_back(num);  // 소수인 경우 벡터에 저장
        }

    }
    // 소수 벡터 반환
    return primes;
}


// 테스트 케이스별로 소수 개수 계산하고 출력
void process(int caseIndex, const Sieve& sieve) {
    // 구간 L과 R
    int L,R;
    scanf("%d%d", &L, &R);  // 구간 [L, R] 입력

    // 해당 범위의 소수 구하기
    // getAllPrimeNumbers함수 실행
    vector<int> allPrimeNumbers = getAllPrimeNumbers(L,R,sieve);

    // 결과 출력
    printf("Case #%d:\n", caseIndex);
    // true인 소수만 push_back되었으니 size를 출력하는게 곧 소수의 개수.
    printf("%d\n", (int)allPrimeNumbers.size());
}

// 메인함수
int main()
{   
    const int MAX_VALUE = 1000000;  // 전처리
    Sieve sieve = Sieve(MAX_VALUE); // 전처리, Sieve는 체라는 뜻, MAX_VALUE크기로 sieve객체 전처리 생성성

    // 테스트 케이스 선언
    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 수 입력

    // 케이스 별로 process 함수 실행
    for(int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex, sieve);  // 각 테스트 케이스 처리
    }
}