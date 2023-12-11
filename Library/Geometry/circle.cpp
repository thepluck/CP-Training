#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

using ll = long long;
using ld = long double;

const ld EPS = 1e-9;

template <class Tp>
struct point {
    Tp x, y;
    
    point(): x(0), y(0) {}

    point(Tp x, Tp y): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator *= (const Tp &k) {
        x *= k; y *= k; return *this;
    }

    point &operator /= (const Tp &k) {
        x /= k; y /= k; return *this;
    }

    bool operator < (const point &o) const {
        return x != o.x ? x < o.x : y < o.y;
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

template <class Tp>
Tp dot(const point <Tp> &a, const point <Tp> &b) {
    return a.x * b.x + a.y * b.y;
}

template <class Tp>
Tp norm(const point <Tp> &p) {
    return p.x * p.x + p.y * p.y;
}

template <class Tp>
ld abs(const point <Tp> &p) {
    return sqrt(norm(p));
}

template <class Tp>
ld dist(const point <Tp> &a, const point <Tp> &b) {
    return sqrt(norm(a - b));
}

template <class Tp>
point <Tp> perp(const point <Tp> &p) {
    return point <Tp> (p.y, -p.x);
}
bool eq(ld x, ld y) {
    return abs(x - y) < EPS;
}

bool leq(ld x, ld y) {
    return x < y || eq(x, y);
}

bool geq(ld x, ld y) {
    return x > y || eq(x, y);
}

struct circle {
    point <ld> cen; ld rad;

    circle(point <ld> cen, ld rad = 0): cen(cen), rad(rad) {}

    circle(point <ld> a, point <ld> b, point <ld> c) {
        ld a1 = a.x - b.x, b1 = a.y - b.y;
        ld c1 = (norm(a) - norm(b)) / 2;
        ld a2 = a.x - c.x, b2 = a.y - c.y;
        ld c2 = (norm(a) - norm(c)) / 2;
        ld Dx = c1 * b2 - c2 * b1;
        ld Dy = a1 * c2 - a2 * c1;
        ld D = a1 * b2 - a2 * b1;
        cen = {Dx / D, Dy / D};
        rad = dist(cen, a);
    }

    circle(point <ld> a, point <ld> b) {
        cen = {(a.x + b.x) / 2, (a.y + b.y) / 2};
        rad = dist(a, b) / 2;
    }
    
    bool contain(point <ld> p) {
        return leq(dist(cen, p), rad);
    }
};

/// minimum enclosing circle
circle welzl(int n,
vector <point <ld>> &pts, vector <point <ld>> bdr) {
    if (n == 0 || bdr.size() == 3) {
        if (bdr.empty()) return circle({0, 0}, 0);
        if (bdr.size() == 1) return circle(bdr[0], 0);
        if (bdr.size() == 2) return circle(bdr[0], bdr[1]);
        return circle(bdr[0], bdr[1], bdr[2]);
    }
    int i = randInt(0, n - 1); point <ld> p = pts[i];
    swap(pts[i], pts[n - 1]);
    circle mec = welzl(n - 1, pts, bdr);
    if (mec.contain(p)) return mec;
    bdr.push_back(p);
    return welzl(n - 1, pts, bdr);
}
