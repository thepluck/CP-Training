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

Tp norm(const point &p) {
    return dot(p, p);
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
    return cross(a, b) > 0;
}

istream& operator >> (istream &is, point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const point &p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

const int N = 1505;

point a[N]; int s[N];
pair <point, int> b[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> s[i];
    for (int i = 0; i < n; i++) {
        int m = 0; int cur = 0;
        for (int j = 0; j < n; j++)
            if (i != j)
                b[m++] = {a[j] - a[i], s[j]};
        sort(b, b + m,
        [](const pair <point, int> &p,
        const pair <point, int> &q) {
            return cmp(p.first, q.first);
        });
        for (int j = 0; j < m; j++) {
            if (j > 0 && cross(b[j].first,
            b[j - 1].first) != 0) cur = 0;
            cur += b[j].second * b[j].second + 5;
            res = max(res, cur + s[i] * s[i] + 5);
        }
    }
    cout << res << '\n';
}