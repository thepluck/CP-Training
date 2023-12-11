#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct line {
    ll k, m, p;

    bool operator < (const ll &x) const {
        return p < x;
    }
};

struct ConvexHull: vector <line> {
    static const ll INF = LLONG_MAX;

    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(line &x, line y) {
        if (x.k == y.k)
            x.p = x.m > y.m ? INF : -INF;
        else x.p = div(y.m - x.m, x.k - y.k);
        return x.p >= y.p;
    }

    void add(ll k, ll m) {
        iterator x = end(), y;
        line l = {k, m, INF};
        if (x != begin()) isect(*(--x), l);
        while ((y = x) != begin()
        && (--x)->p >= y->p) {
            pop_back(); isect(*x, l);
        }
        push_back(l);
    }

    ll get(ll x) {
        line l = *lower_bound(begin(), end(), x);
        return l.k * x + l.m;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; ll res = 0;
    vector <ll> s1(n + 1), s2(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s1[i + 1] = s1[i] + x;
        s2[i + 1] = s2[i] + s1[i + 1];
    }
    ConvexHull hull;
    for (int i = n; i >= 0; i--) {
        hull.add(-i, s2[i]);
        res = max(res, hull.get(s1[i])
        + s1[i] * i - s2[i]);
    }
    cout << res << '\n';
}