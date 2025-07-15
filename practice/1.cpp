#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sieve{
public:
    long long maximumValue;
    vector<bool> isPrime;

    Sieve(long long maximumValue): maximumValue(maximumValue){
        isPrime.assign(maximumValue+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (long long num=2; num<=maximumValue; num++){
            if(isPrime[num]==false){
                continue;
            }
            for(long long j = num*num; j<=maximumValue; j+=num){
                isPrime[j]=false;
            }
        }
    }
};

void process(int caseSize, Sieve sieve){
    int L, R;
    cin >> L >> R;
    int count=0;

    for(int i = L; i <= R; i++){
        if(sieve.isPrime[i]==true){
            count++;
        }
    }

    cout << "Case #" << caseSize << ":" << endl;
    cout << count << endl;

}
int main(){
    long long max_num = 1000000;
    int caseSize;
    cin >> caseSize;
    Sieve sieve(max_num);
    for (int i=1; i<=caseSize; i++){
        process(i, sieve);
    }
    return 0;
}