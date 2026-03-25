// Problem 1: Dinner Table Arrangements

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> mask(N, 0);
        for (int i = 0; i < N; ++i) {
            int M; cin >> M;
            for (int j = 0; j < M; ++j) {
                int a; cin >> a;
                if (a >= 1 && a <= 30) mask[i] |= (1 << (a - 1));
            }
        }

        if (N == 1) {
            cout << "YES\n";
            continue;
        }

        // adjacency: can sit next to each other iff masks are disjoint
        vector<vector<char>> adj(N, vector<char>(N, 0));
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (i != j)
            adj[i][j] = ((mask[i] & mask[j]) == 0);

        // Use bitmask DP to search for Hamiltonian cycle.
        // Fix start = 0 to avoid rotational duplicates.
        const int START = 0;
        int FULL = (1 << N) - 1;

        vector<vector<char>> dp(1 << N, vector<char>(N, 0));
        dp[1 << START][START] = 1;

        for (int s = 0; s <= FULL; ++s) {
            for (int last = 0; last < N; ++last) {
                if (!dp[s][last]) continue;
                for (int nxt = 0; nxt < N; ++nxt) {
                    if (s & (1 << nxt)) continue;
                    if (!adj[last][nxt]) continue;
                    dp[s | (1 << nxt)][nxt] = 1;
                }
            }
        }

        bool ok = false;
        for (int last = 0; last < N; ++last) {
            if (last == START) continue;
            if (dp[FULL][last] && adj[last][START]) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
