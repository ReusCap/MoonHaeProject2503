#include <iostream>
#include <vector>

using namespace std;

class Sieve{
public:
    // 변수는 maximumValue와 isPrime벡터로 2개 
    int maximumValue;
    vector<bool> isPrime;

    // 생성자에서는 바로 assign갈기고 0,1만 대입한 다음 바로 for문 진입
    // for문에서는 2부터~랑 j로 i*i부터 랑 +=i
    Sieve(int maximumValue) : maximumValue(maximumValue){
        isPrime.assign(maximumValue+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i=2; i<=maximumValue; i++){
            if(isPrime[i]==false){
                continue;
            }
            for(int j=i*i; j<=maximumValue; j+=i){
                isPrime[j]=false;
            }
        }
    }
};

void process(int caseIndex, Sieve& sieve){
    int L, R;
    cin >> L >>R;
    int count = 0;
    for(int i = L; i<=R; i++){
        if(sieve.isPrime[i]==true){
            count++;
        }
    }
    cout << "Case # "<< caseIndex << ":"<< endl;
    cout << count << endl;
}

int main(){
    int max_num=1000000;
    int caseSize;
    cin >> caseSize;
    Sieve sieve(max_num);
    for (int i=1; i<=caseSize; i++){
        process(i,sieve);
    }
    return 0;
}