#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct point {
    ll x, y;

    point(ll x = 0, ll y = 0): x(x), y(y) {}

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }
};

ll cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

ll dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

ll norm(const point &a) {
    return dot(a, a);
}

ll orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

point st[5005]; bool tt[5005];
int tp, id[5005];

bool convex_hull(vector <point> &a) {
    if (a.size() < 3) return 0;
    tp = 0; int n = a.size();
    for (int i = 0; i < n; i++) {
        while (tp > 1 && orient(st[tp - 2],
        st[tp - 1], a[i]) > 0) tp--;
        id[tp] = i; st[tp++] = a[i];
    }
    int up = tp;
    for (int i = n - 2; i >= 0; i--) {
        while (tp > up && orient(st[tp - 2],
        st[tp - 1], a[i]) > 0) tp--;
        id[tp] = i; st[tp++] = a[i];
    }
    for (int i = 0; i < tp; i++)
        tt[id[i]] = 1;
    vector <point> b;
    for (int i = 0; i < n; i++)
        if (!tt[i]) b.push_back(a[i]);
    for (int i = 0; i < tp; i++)
        tt[id[i]] = 0;
    a = move(b); return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <point> a(n);
    for (point &p : a) cin >> p.x >> p.y;
    sort(a.begin(), a.end(),
    [](const point &p, const point &q) {
        if (p.x == q.x) return p.y < q.y;
        return p.x < q.x;
    });
    int cnt = 0;
    while (convex_hull(a)) cnt++;
    cout << cnt << '\n';
}