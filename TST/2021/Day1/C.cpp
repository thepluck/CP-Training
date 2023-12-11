#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

using Tp = long long;

struct point {
    Tp x, y;

    point(Tp x = 0, Tp y = 0): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator *= (const Tp &k) {
        x *= k; y *= k; return *this;
    }

    bool operator != (const point &o) const {
        return x != o.x || y != o.y;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator * (const Tp &k) const {
        return point(*this) *= k;
    }
};

Tp dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

Tp orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

bool ccw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) > 0;
}

bool cw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) < 0;
}

bool cmp(const point &a, const point &b) {
    if (a.y < 0 && b.y >= 0) return false;
    if (a.y >= 0 && b.y < 0) return true;
    if (!cross(a, b)) return a.x > b.x;
    return cross(a, b) > 0;
}

istream& operator >> (istream &is, point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const point &p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

int main() {
    freopen("ball.inp", "r", stdin);
    freopen("ball.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <point> a(n);
    for (auto &p : a) cin >> p.x >> p.y;
    sort(a.begin(), a.end(),
    [](const point &p, const point &q) {
        return p.x < q.x;
    });
    bool straight = true;
    for (int i = 0; i < n - 2; i++)
        if (orient(a[i], a[i + 1], a[i + 2])) {
            straight = false; break;
        }
    long long res = 0;
    if (straight) {
        for (int i = 1; i < n; i++)
            res += i * (n - i);
        cout << res * 2; return 0;
    }
    for (int i = 0; i < n; i++) {
        vector <point> b;
        for (int j = 0; j < n; j++)
            if (i != j) b.push_back(a[j] - a[i]);
        sort(b.begin(), b.end(), cmp);
        for (int j = 0; j < n - 1; j++) {
            if (j && !cross(b[j], b[j - 1])
            && b[j].x * b[j - 1].x >= 0
            && b[j].y * b[j - 1].y >= 0)
                res += 2;
            else res += 1;
        }
    }
    cout << res << '\n';
}