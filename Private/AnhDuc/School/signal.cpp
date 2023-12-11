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

ll norm(const point &a) {
    return a.x * a.x + a.y * a.y;
}

ll C2(ll n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}

ll C3(ll n) {
    if (n < 0) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

ll C4(ll n) {
    if (n < 0) return 0;
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <point> a(n), b;
    for (point &p : a)
        cin >> p.x >> p.y;
    auto cmp = [](const point &p, const point &q) {
        if (p.y < 0 && q.y >= 0) return false;
        if (p.y >= 0 && q.y < 0) return true;
        return cross(p, q) > 0;
    };
    ll concave = 0, convex = C4(n);
    for (int i = 0; i < n; i++) {
        b.clear();
        for (int j = 0; j < n; j++)
            if (j != i)
                b.push_back(a[j] - a[i]);
        sort(b.begin(), b.end(), cmp);
        ll tri = C3(n - 1);
        for (int j = 0, k = 0; j < n - 1; j++) {
            while (k < int(b.size())
            && cross(b[j], b[k]) >= 0) k++;
            tri -= C2(k - j - 1);
            b.push_back(b[j]);
        }
        concave += tri; convex -= tri;
    }
    double res = convex * 2 + concave;
    res /= C3(n); res += 3;
    cout << setprecision(6) << fixed << res;
}