#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
    ll x, y;

    point(ll x = 0, ll y = 0): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    bool operator < (const point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    
    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }
};

using poly = vector <point>;

ll dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

ll orient(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b);
}

poly minkowski(const poly &a, const poly &b) {
    if (a.empty() || b.empty()) return a.size() ? a : b;
    poly sum(1, a[0] + b[0]);
    int i = 0, j = 0, m = a.size(), n = b.size();
    while (i < m && j < n) {
        point p = (i == m - 1 ? a[0] : a[i + 1]) - a[i];
        point q = (j == n - 1 ? b[0] : b[j + 1]) - b[j];
        if (!cross(p, q)) {
            sum.push_back(sum.back() + p + q); i++; j++;
        }
        else if (cross(p, q) > 0) {
            sum.push_back(sum.back() + p); i++;
        }
        else {
            sum.push_back(sum.back() + q); j++;
        }
    }
    while (i + 1 < m) {
        sum.push_back(sum.back() + a[i + 1] - a[i]); i++;
    }
    while (j + 1 < n) {
        sum.push_back(sum.back() + b[j + 1] - b[j]); j++;
    }
    if (sum.back() == sum.front()) sum.pop_back();
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    poly sum;
    for (int id = 0; id < 3; id++) {
        int n; cin >> n; poly a(n);
        for (auto &p : a) cin >> p.x >> p.y;
        rotate(a.begin(), min_element
        (a.begin(), a.end()), a.end());
        sum = minkowski(sum, a);
    }
    int q; cin >> q;
    while (q--) {
        point p; cin >> p.x >> p.y;
        p.x *= 3; p.y *= 3;
        if (orient(sum[0], p, sum[1]) > 0 ||
        orient(sum[0], p, sum.back()) < 0) {
            cout << "NO\n"; continue;
        }
        int lo = 1, hi = sum.size() - 1;
        while (lo + 1 < hi) {
            int mi = (lo + hi) / 2;
            if (orient(sum[0], p, sum[mi]) < 0)
                lo = mi;
            else hi = mi;
        }
        if (orient(sum[lo], p, sum[hi]) <= 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
}