#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> frequencyMap;
    int maxFrequency = 0;

    for (int i = 0; i < N; i++) {
        string st;
        cin >> st;
        frequencyMap[st]++;
        int k = frequencyMap[st];
        if (k > maxFrequency) {
            maxFrequency = k;
        }
    }

    cout << maxFrequency << endl;

    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        if (it->second == maxFrequency) {
            printf("%s ", it->first.c_str());
        }
    }
    cout << endl;
}
