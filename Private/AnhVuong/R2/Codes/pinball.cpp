#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class segTree {
private:
    vector <ll> val; int lo, hi, n; ll res;

    void update(int i, int l, int r, ll v) {
        val[i] = min(val[i], v);
        if (l != r) {
            int m = (l + r) / 2;
            if (m >= lo) update(i * 2, l, m, v);
            else update(i * 2 + 1, m + 1, r, v);
        }
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res = min(res, val[i]));
        int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi) query(i * 2 + 1, m + 1, r);
    }

public:
    segTree(int n): n(n), val(4 * n, 1e18) {}

    void update(int p, ll v) {
        lo = p; update(1, 1, n, v);
    }

    ll query(int l, int r) {
        lo = l; hi = r; res = 1e18;
        query(1, 1, n); return res;
    }
};

const int N = 1e5 + 5;

int a[N], b[N], c[N], d[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        val.push_back(a[i]);
        val.push_back(b[i]);
        val.push_back(c[i]);
    }
    val.push_back(1); val.push_back(m);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(),
    val.end()), val.end());
    segTree ST1(val.size());
    segTree STm(val.size());
    ST1.update(upper_bound(val.begin(),
    val.end(), 1) - val.begin(), 0);
    STm.update(upper_bound(val.begin(),
    val.end(), m) - val.begin(), 0);
    long long res = 1e18;
    for (int i = 1; i <= n; i++) {
        a[i] = upper_bound(val.begin(),
        val.end(), a[i]) - val.begin();
        b[i] = upper_bound(val.begin(),
        val.end(), b[i]) - val.begin();
        c[i] = upper_bound(val.begin(),
        val.end(), c[i]) - val.begin();
        ll get1 = ST1.query(a[i], b[i]);
        ll getm = STm.query(a[i], b[i]);
        res = min(res, get1 + getm + d[i]);
        ST1.update(c[i], get1 + d[i]);
        STm.update(c[i], getm + d[i]);
    }
    if (res == ll(1e18)) cout << "-1";
    else cout << res;
}