#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 100005;
const ll INF = 1e18;

int x[N], t[N]; ll ans[N];
pair <int, ll> BIT[N];
vector <int> val;

void update(int i, int v, int y) {
    for (; i < N; i += i & -i) {
        BIT[i].first += y;
        BIT[i].second += v * y;
    }
}

int getPos(int k) {
    int p = 0;
    for (int l = 1 << 16; l > 0; l >>= 1)
        if (p + l < N && BIT[p + l].first < k) {
            p += l; k -= BIT[p].first;
        }
    return p + 1;
}

pair <int, ll> query(int i) {
    pair <int, ll> res;
    for (; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

ll getSum(int k) {
    int pos = getPos(k);
    if (pos == N) return INF;
    auto res = query(pos - 1);
    return res.second + 1ll *
    (k - res.first) * val[pos - 1];
}

void rec(int l, int r, int optl, int optr) {
    int m = (l + r) / 2, optm;
    for (int i = optl; i <= optr; i++) {
        update(t[i], val[t[i] - 1], 1);
        ll cur = getSum(m);
        if (ans[m] > cur + x[i]) {
            ans[m] = cur + x[i]; optm = i;
        }
    }
    for (int i = optl; i <= optr; i++)
        update(t[i], val[t[i] - 1], -1);
    if (l < m) rec(l, m - 1, optl, optm);
    for (int i = optl; i < optm; i++)
        update(t[i], val[t[i] - 1], 1);
    if (m < r) rec(m + 1, r, optm, optr);
    for (int i = optl; i < optm; i++)
        update(t[i], val[t[i] - 1], -1);
}

void solve() {
    int n; cin >> n; val.clear();
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> t[i];
        val.push_back(t[i]);
        ans[i] = INF;
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(),
    val.end()), val.end());
    for (int i = 1; i <= n; i++)
        t[i] = upper_bound(val.begin(),
        val.end(), t[i]) - val.begin();
    rec(1, n, 1, n);
    int q; cin >> q;
    while (q--) {
        long long lim; cin >> lim;
        cout << upper_bound(ans + 1,
        ans + n + 1, lim) - ans - 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int test; cin >> test;
    while (test--) solve(); 
}