#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {ll x, y;};

struct line {
    ll a, b; int id;

    line(ll a, ll b, int id): a(a), b(b), id(id) {}

    ll operator () (const ll &x) const {
        return a * x + b;
    }

    bool operator < (const line &o) const {
        return id < o.id;
    }

    bool operator < (const point &p) const {
        return this->operator()(p.x) > p.y;
    }
};

const int N = 400005;

point pt[N]; ll k[N], d[N];
set <line> ss;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> d[i];
        pt[i] = {pt[i - 1].x + d[i],
        pt[i - 1].y + d[i] * k[i]};
    }
    
}