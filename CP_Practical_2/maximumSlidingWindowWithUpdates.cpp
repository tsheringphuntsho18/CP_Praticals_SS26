// Problem 4: Maximum in Sliding Window with Updates

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n; // size (power of two)
    vector<ll> st;
    SegTree() : n(0) {}
    void init(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        st.assign(2*n, LLONG_MIN);
    }
    void build(const vector<ll>& a) {
        int sz = (int)a.size();
        init(sz);
        for (int i = 0; i < sz; ++i) st[n + i] = a[i];
        for (int i = n - 1; i >= 1; --i) st[i] = max(st[2*i], st[2*i+1]);
    }
    void update(int pos, ll val) {
        int p = pos + n;
        st[p] = val;
        p /= 2;
        while (p >= 1) {
            st[p] = max(st[2*p], st[2*p+1]);
            p /= 2;
        }
    }
    ll query(int l, int r) {
        if (l > r) return LLONG_MIN;
        l += n; r += n;
        ll res = LLONG_MIN;
        while (l <= r) {
            if (l & 1) res = max(res, st[l++]);
            if (!(r & 1)) res = max(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q;
    if (!(cin >> N >> K >> Q)) return 0;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    SegTree st;
    st.build(a);

    for (int qi = 0; qi < Q; ++qi) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos; ll val;
            cin >> pos >> val; // assume 1-based position
            if (pos >= 1 && pos <= N) st.update(pos - 1, val);
        } else if (type == 2) {
            int i;
            cin >> i; // 1-based end index
            int l = i - K + 1;
            if (l < 1) l = 1; // if window extends before start, clamp to valid prefix
            int L = l - 1;
            int R = min(i, N) - 1;
            ll ans = st.query(L, R);
            if (ans == LLONG_MIN) ans = LLONG_MIN; // should not happen for valid queries
            cout << ans << '\n';
        }
    }

    return 0;
}