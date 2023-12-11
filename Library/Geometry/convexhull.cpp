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

    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
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

istream& operator >> (istream &is, point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const point &p) {
    return os << p.x << ' ' << p.y;
}

vector <point> convexHull(vector <point> pts) {
    vector <point> hull;
    sort(pts.begin(), pts.end(), [](point a, point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i = 0; i < pts.size(); i++) {
        while (hull.size() > 1 && orient(hull[hull.size() - 2],
        hull[hull.size() - 1], pts[i]) <= 0) hull.pop_back();
        hull.push_back(pts[i]);
    }
    int k = hull.size();
    for (int i = pts.size() - 1; i >= 0; i--) {
        while (hull.size() > k && orient(hull[hull.size() - 2],
        hull[hull.size() - 1], pts[i]) <= 0) hull.pop_back();
        hull.push_back(pts[i]);
    }
    hull.pop_back(); return hull;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    while (cin >> N) {
        if (N == 0) return 0;
        vector <point> pts(N);
        for (auto &p : pts) cin >> p;
        auto hull = convexHull(pts);
        cout << hull.size() << '\n';
        for (auto p : hull) cout << p << '\n';
    }
}
