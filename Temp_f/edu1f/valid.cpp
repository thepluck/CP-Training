#include "testlib.h"
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

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
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

Tp input() {
    static double x;

    x = inf.readStrictDouble(-100000, 100000, 0, 2);
    return round(x * 100);
}

void magic(Tp &x) {
    if (x) x /= abs(x);
}

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(3, 1000);
    inf.readSpace();
    int m = inf.readInt(1, 100);
    inf.readEoln();
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        a[i].x = input();
        inf.readSpace();
        a[i].y = input();
        inf.readEoln();
        for (int j = 0; j < i; j++)
            ensuref(a[i].x != a[j].x || a[i].y != a[j].y, "duplicated points");

    }
    a.push_back(a[0]);
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n - (i == 0); j++) {
            Tp o1 = orient(a[i], a[j], a[i + 1]);
            Tp o2 = orient(a[i], a[j + 1], a[i + 1]);
            Tp o3 = orient(a[j], a[i], a[j + 1]);
            Tp o4 = orient(a[j], a[i + 1], a[j + 1]);
            magic(o1); magic(o2); magic(o3); magic(o4);
            ensuref(o1 * o2 > 0 || o3 * o4 > 0, "segment intersect %d %d", i, j);
        }
    for (int i = 0; i < m; i++) {
        input();
        inf.readSpace();
        input();
        inf.readSpace();
        input();
        inf.readSpace();
        input();
        inf.readEoln();
    }
    inf.readEof();
}