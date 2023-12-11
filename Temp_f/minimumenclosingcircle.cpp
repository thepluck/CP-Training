#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

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

Tp norm(const point &p) {
    return p.x * p.x + p.y * p.y;
}

Tp dist(const point &a, const point &b) {
    return sqrt(norm(a - b));
}

bool eq(Tp x, Tp y) {
    return abs(x - y) < EPS;
}

bool leq(Tp x, Tp y) {
    return x < y || eq(x, y);
}

bool geq(Tp x, Tp y) {
    return x > y || eq(x, y);
}

struct circle {
    point cen; Tp rad;

    circle(point cen, Tp rad = 0): cen(cen), rad(rad) {}

    circle(point a, point b, point c) {
        Tp a1 = a.x - b.x, b1 = a.y - b.y;
        Tp c1 = (norm(a) - norm(b)) / 2;
        Tp a2 = a.x - c.x, b2 = a.y - c.y;
        Tp c2 = (norm(a) - norm(c)) / 2;
        Tp Dx = c1 * b2 - c2 * b1;
        Tp Dy = a1 * c2 - a2 * c1;
        Tp D = a1 * b2 - a2 * b1;
        cen = {Dx / D, Dy / D};
        rad = dist(cen, a);
    }

    circle(point a, point b) {
        cen = {(a.x + b.x) / 2, (a.y + b.y) / 2};
        rad = dist(a, b) / 2;
    }

    bool contain(point p) {
        return leq(dist(cen, p), rad);
    }
};

circle welzl(int n, vector <point> &pts, vector <point> bdr) {
    if (n == 0 || bdr.size() == 3) {
        if (bdr.empty()) return circle({0, 0}, 0);
        if (bdr.size() == 1) return circle(bdr[0], 0);
        if (bdr.size() == 2) return circle(bdr[0], bdr[1]);
        return circle(bdr[0], bdr[1], bdr[2]);
    }
    int i = randInt(0, n - 1); point p = pts[i];
    swap(pts[i], pts[n - 1]);
    circle mec = welzl(n - 1, pts, bdr);
    if (mec.contain(p)) return mec;
    bdr.push_back(p);
    return welzl(n - 1, pts, bdr);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; scanf("%d", &n);
    vector <point> pts(n);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        pts[i] = {x, y};
    }
    shuffle(pts.begin(), pts.end(), rng);
    circle mec = welzl(n, pts, {});
    printf("%.3Lf %.3Lf\n%.3Lf",
    mec.cen.x, mec.cen.y, mec.rad);
}