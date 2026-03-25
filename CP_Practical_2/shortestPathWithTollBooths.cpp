// Problem 6: The Shortest Path with Toll Booths

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<int> toll(N + 1);
    for (int i = 1; i <= N; ++i) cin >> toll[i];

    // DP table: dp[i][j] = minimum time to reach booth i with j skips used
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, INT_MAX));
    dp[1][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            // Pay toll and move to next booth
            if (j == 0 && i < N) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            // Skip this booth
            if (j < K && i < N) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 2);
            }
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j <= K; ++j) {
        ans = min(ans, dp[N][j]);
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';

    return 0;
}