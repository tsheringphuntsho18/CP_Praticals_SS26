// Problem 2: Maximum AND Subarray

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        int ans = 0;
        for (int bit = 31; bit >= 0; --bit) {
            int test = ans | (1 << bit);
            // check if there exists a subarray of length K where every element has all bits in 'test'
            int cnt = 0;
            bool ok = false;
            for (int i = 0; i < N; ++i) {
                if ((A[i] & test) == test) ++cnt;
                else cnt = 0;
                if (cnt >= K) { ok = true; break; }
            }
            if (ok) ans = test;
        }

        cout << ans << '\n';
    }

    return 0;
}

