#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

struct line {
    ll k, m, p;

    line(ll k = 0, ll m = 0, ll p = -INF):
    k(k), m(m), p(p) {}

    ll operator () (ll x) {
        return k * x + m;
    }
};

struct CHT {
    vector <line> hull; int N = 0;
    vector <tuple <int, int, line>> buck;

    ll floor(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    
    ll ceil(ll a, ll b) {
        if (b > 0)
            return floor(a + b - 1, b);
        return floor(-a - b - 1, -b);
    }

    bool isect(line x, line &y) {
        y.p = ceil(y.m - x.m, x.k - y.k);
        return x.p >= y.p;
    }

    void push(line l) {
        int lo = 0, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (isect(hull[mi], l)) hi = mi;
            else lo = mi + 1;
        }
        if (hi == int(hull.size()))
            hull.emplace_back();
        buck.emplace_back(hi, N, hull[hi]);
        if (hi) isect(hull[hi - 1], l);
        hull[hi] = l; N = hi + 1;
    }

    void pop() {
        int i; line l;
        tie(i, N, l) = buck.back();
        buck.pop_back(); hull[i] = l;
    }

    ll get(ll x) {
        if (!N) return -INF;
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (hull[mi].p <= x) lo = mi;
            else hi = mi - 1;
        }
        return hull[lo](x);
    }
};
