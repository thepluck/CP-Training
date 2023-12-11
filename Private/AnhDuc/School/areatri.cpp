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

    void show() {
        cerr << x << ' ' << y;
    }
};

ll cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

ll norm(const point &a) {
    return a.x * a.x + a.y * a.y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll res = 0; cin >> n;
    vector <point> a(n), b;
    for (point &p : a)
        cin >> p.x >> p.y;
    auto cmp = [](const point &p, const point &q) {
        if (p.y < 0 && q.y > 0) return false;
        if (p.y > 0 && q.y < 0) return true;
        if (cross(p, q) == 0)
            return norm(p) < norm(q);
        return cross(p, q) > 0;
    };
    cerr << '\n';
    for (int i = 0; i < n; i++) {
        point cur; b.clear();
        for (int j = 0; j < n; j++)
            if (i != j)
                b.push_back(a[j] - a[i]);
        ll tmp = 0;
        sort(b.begin(), b.end(), cmp);
        for (int j = 0, k = 0; j < n - 1; j++) {
            while ((k == j) || (k < int(b.size())
            && cross(b[j], b[k]) > 0))
                cur += b[k++];
            res += cross(b[j], cur);
            tmp += cross(b[j], cur);
            cur -= b[j]; b.push_back(b[j]);
        }
        cerr << tmp << '\n';
    }
    cerr << res << '\n';
}