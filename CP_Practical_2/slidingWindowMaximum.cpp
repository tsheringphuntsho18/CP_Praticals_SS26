// Problem 3: Sliding Window Maximum

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    deque<int> dq; // indices of useful elements, front = max
    vector<long long> ans;
    for (int i = 0; i < N; ++i) {
        // remove indices out of window
        while (!dq.empty() && dq.front() <= i - K) dq.pop_front();
        // remove smaller elements from back
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= K - 1) ans.push_back(a[dq.front()]);
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}

