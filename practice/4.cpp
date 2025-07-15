// 백준 10859
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

// 입력값이 소수인지 판별
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 뒤집기 가능한 숫자 매핑
unordered_map<char, char> flipMap = {
    {'0', '0'}, {'1', '1'}, {'2', '2'}, {'5', '5'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
};

// 숫자를 뒤집어 새로운 숫자로 변환
string flipAndReverse(const string& s) {
    string flipped;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (flipMap.find(s[i]) == flipMap.end()) {
            return ""; // 뒤집기 불가능한 숫자 포함됨
        }
        flipped += flipMap[s[i]];
    }
    return flipped;
}

int main() {
    string input;
    cin >> input;

    // 입력된 수가 소수인지 확인
    // stoll은 string문자열을 long long정수형으로 바꿔줌
    long long original = stoll(input);
    if (!isPrime(original)) {
        cout << "no\n";
        return 0;
    }

    // 뒤집은 수 생성
    string flippedStr = flipAndReverse(input);
    if (flippedStr == "") {
        cout << "no\n";
        return 0;
    }

    // 뒤집은 수가 소수인지 확인
    long long flipped = stoll(flippedStr);
    if (!isPrime(flipped)) {
        cout << "no\n";
        return 0;
    }

    cout << "yes\n";
    return 0;
}
