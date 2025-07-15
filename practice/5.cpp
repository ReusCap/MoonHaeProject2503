// 백준 13156
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, m;
    cin >> c >> m;

    vector<vector<int>> price(m, vector<int>(c + 1)); // price[i][k]: i번째 상인이 CPU k개에 주는 돈

    for (int i = 0; i < m; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> price[i][j];

    vector<int> dp(c + 1, 0); // dp[j]: j개의 CPU가 남았을 때 최대 이익

    for (int i = 0; i < m; ++i) {
        vector<int> next_dp(c + 1, 0);

        for (int cpu_left = 0; cpu_left <= c; ++cpu_left) {
            for (int sell = 0; sell <= cpu_left; ++sell) {
                next_dp[cpu_left - sell] = max(
                    next_dp[cpu_left - sell],
                    dp[cpu_left] + price[i][sell]
                );
            }
        }

        dp = next_dp; // 갱신
    }

    int answer = *max_element(dp.begin(), dp.end());
    cout << answer << endl;
    return 0;
}
