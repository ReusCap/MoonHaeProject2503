#include <iostream>
#include <vector>
using namespace std;

class Sieve {
public:
    int maximumValue;
    vector<bool> isPrime;

    Sieve(int maximumValue) : maximumValue(maximumValue) {
        isPrime.assign(maximumValue+1, true);
        isPrime[0] = isPrime[1]=false;
        // isPrime 0과 1 false하자마자 바로 for문 진입
        // 2부터 시작해서 i++하고 만약 false면 continue 하게
        for(int i=2; i<=maximumValue; i++){
            if(isPrime[i]==false){
                continue;
            }
            // j는 i*i이고 j+=1인거 잊지마!!
            for(int j=i*i; j<=maximumValue; j+=i){
                isPrime[j]=false;
            }
        }
    }
};

void process(int caseIndex, const Sieve& sieve) {
    // L과 R입력받고 숫자 셀 count입력
    int L,R;
    cin >>L>>R;
    int count=0;
    // L과 R을 범위로 forㅁ누 돌려서
    // 그냥 sieve.isPrime[i]가 true이면 count증가하게 설계
    for (int i=L; i<=R; i++ ){
        if(sieve.isPrime[i]==true){
            count++;
        }
    }
    cout << "Case #" << caseIndex << ":"<<endl;
    cout << count<< endl;
}

int main() {
    // 문제에서 주어진만큼 미리 seive전처리
    const int MAX_VALUE = 1000000;
    Sieve sieve(MAX_VALUE);

    int caseSize;
    cin >> caseSize;

    for (int i = 1; i <= caseSize; ++i) {
        process(i, sieve);
    }

    return 0;
}
