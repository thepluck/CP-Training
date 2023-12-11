//http://lqdoj.edu.vn/problem/tichdayso
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

ll mmul(ll a, ll b, ll m) {
    a %= m; b %= m;
    ll q = (double) a * b / m;
    return (a * b - q * m) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    ll x, m; cin >> x >> m;
    ll ma = -inf, mi = inf;
    vector <ll> a(n);
    bool neg = 0;
    for (ll &y : a) {
        cin >> y;
        if (y < 0) {
            ma = max(ma, y);
            neg = !neg;
        }
        else mi = min(mi, y);
    }
    bool flag = 0;
    if (neg) {
        if (mi == inf) {
            int p = (abs(ma) + x - 1) / x;
            if (p > k) {
                flag = 1; goto gg;
            }
            k -= p;
            for (ll &y : a)
                if (y == ma) {
                    y += x * p; break;
                }
        }
        else {
            int p = (abs(ma) + x - 1) / x;
            int q = (mi + x - 1) / x;
            if (min(p, q) > k) {
                flag = 1; goto gg;
            }
            ll np = ma + x * p;
            ll nq = x * q - mi;
            if (p < q || (p == q && np > nq)) {
                k -= p;
                for (ll &y : a)
                    if (y == ma) {
                        y += x * p; break;
                    }
            }
            else {
                k -= q;
                for (ll &y : a)
                    if (y == mi) {
                        y -= x * q; break;
                    }
            }
        }
    }
    gg: ll res = 1;
    if (flag) {
        priority_queue <ll,
        vector <ll>, greater <ll>> pq;
        for (ll y : a) pq.push(abs(y));
        for (int i = 0; i < k; i++) {
            ll y = pq.top(); pq.pop();
            if (y >= x) pq.push(y - x);
            else {
                i--; res = mmul(res, y, m);
            }
        }
        while (!pq.empty()) {
            res = mmul(res, pq.top(), m);
            pq.pop();
        }
        if (res < 0) res += m;
        res = m - res;
    }
    else {
        priority_queue <ll,
        vector <ll>, greater <ll>> pq;
        for (ll y : a) pq.push(abs(y));
        for (int i = 0; i < k; i++) {
            ll y = pq.top(); pq.pop();
            pq.push(y + x);
        }
        while (!pq.empty()) {
            res = mmul(res, pq.top(), m);
            pq.pop();
        }
        if (res < 0) res += m;
    }
    cout << res << '\n';
}