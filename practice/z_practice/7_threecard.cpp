#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
    vector<int> result;
    sort(cards, cards + n);

    for (int i = 0; i < m; ++i) {
        int k = targets[i];
        bool found = false;
        // j<n && !found; 이게 진짜 중요하다. 이래야지 이중 중첩문 나갈 수 있어. 
        for (int j = 0; j < n && !found; ++j) {
            for (int p = 0; p <= j; ++p) {
                int z = k - cards[j] - cards[p];
                if (binary_search(cards, cards + n, z)) {
                    found = true;
                    break;
                }
            }
        }

        if (found) result.push_back(k);
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* cards = new int[n];
    int* targets = new int[m];

    for (int i = 0; i < n; ++i) scanf("%d", &cards[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &targets[i]);

    vector<int> answers = getPossibleTargets(n, m, cards, targets);

    if (answers.empty()) {
        printf("NO");
    } else {
        for (int i = 0; i < answers.size(); ++i) {
            if (i > 0) printf(" ");
            printf("%d", answers[i]);
        }
    }

    delete[] cards;
    delete[] targets;
    return 0;
}
