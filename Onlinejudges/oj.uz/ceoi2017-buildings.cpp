#include <bits/stdc++.h>
using namespace std;

using ll = long long;
 
struct line {
    mutable ll k, m, p;
    
    line(ll k, ll m, ll p = 0): k(k), m(m), p(p) {}
    
    bool operator < (const line &o) const {
        return k < o.k;
    }
    
    bool operator < (const ll &x) const {
        return p < x;
    }
};

template <bool type>
struct cht : multiset <line, less <>> {
    const ll inf = 1e18;
    
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf; return 0;
        }
        if (x->k == y->k)
            x->p = x->m == y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    
    void add(ll k, ll m) {
        if (type) {
            k = -k; m = -m;
        }
        auto z = emplace(k, m), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    void add(line l) {
        if (type) {
            l.k = -l.k; l.m = -l.m;
        }
        auto z = insert(l), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    ll query(ll x) {
        if (empty()) return type ? inf : -inf;
        auto l = *lower_bound(x);
        if (type) return -l.k * x - l.m;
        return l.k * x + l.m;
    }
};

const int N = 100005;

ll dp[N], h[N], w[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll tot = 0; cin >> n;
    cht <0> cc;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; tot += w[i];
    }
    dp[1] = -w[1];
    for (int i = 2; i <= n; i++) {
        cc.add(h[i - 1] * 2, -dp[i - 1] - h[i - 1] * h[i - 1]);
        dp[i] = -cc.query(h[i]) - w[i] + h[i] * h[i];
    }
    cout << tot + dp[n] << '\n';
}