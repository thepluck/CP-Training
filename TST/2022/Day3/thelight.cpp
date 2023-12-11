#include <bits/stdc++.h>
using namespace std;

using Tp = long double;

const Tp EPS = 1e-9;

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

    point& operator /= (const Tp &k) {
        x /= k; y /= k; return *this;
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

    point operator / (const Tp &k) const {
        return point(*this) /= k;
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

Tp abs(const point &p) {
    return sqrt(norm(p));
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

struct line {
    point v; Tp c;

    line() {}

    line(point v, Tp c): v(v), c(c) {}

    line(point p, point q): v(q - p), c(cross(v, p)) {}

    Tp side(const point &p) {
        return cross(v, p) - c;
    }
};

// v1 x p = c1, v2 x p = c2
// => p x (v2 * c1 - v1 * c2) = 0
// => p = k(v2 * c1 - v1 * c2)
// v1 x k(v2 * c1 - v1 * c2) = c1 with v1 x v1 = 0
// => k = 1 / (v1 x v2) 
// => p = (v2 * c1 - v1 * c2) / (v1 x v2)

bool intersect(line l1, line l2, point &pt) {
    Tp d = cross(l1.v, l2.v);
    if (abs(d) < EPS) return false;
    pt = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

line bisector(line l1, line l2, bool sign) {
    return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
            l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}

int main() {
    
    Tp x0, y0; cin >> x0 >> y0;
    int n; cin >> n;
    vector<point> a(n);
    for (auto &p : a) cin >> p;
    a.push_back(a.back());
    Tp res = 0;
    for (int i = 0; i < n; i++)
        res += cross(a[i], a[i + 1]);
    cout << setprecision(2) << fixed <<  abs(res) / 2;
}