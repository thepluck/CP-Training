#include <bits/stdc++.h>
using namespace std;

using type = double;

template <class T>
using vec = vector <T>;

const type EPS = 1e-9;

struct point {
    type x, y;

    point(type x = 0, type y = 0): x(x), y(y) {}

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator *= (const type &k) {
        x *= k; y *= k; return *this;
    }

    point& operator /= (const type &k) {
        x /= k; y /= k; return *this;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator * (const type &k) const {
        return point(*this) *= k;
    }

    point operator / (const type &k) const {
        return point(*this) /= k;
    }
};

type cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

type dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

type norm(const point &a) {
    return dot(a, a);
}

type dis(const point &a, const point &b) {
    return sqrt(norm(a - b));
}

type orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

struct line {
    point v; type c;

    line(point v, type c): v(v), c(c) {}

    line(type a, type b, type c): v(b, -a), c(c) {}

    line(point p, point q): v(q - p), c(cross(v, p)) {}

    type side(point p) {
        return cross(v, p) - c;
    }
};

bool inter(line l1, line l2, point &p) {
    type d = cross(l1.v, l2.v);
    if (abs(d) < EPS) return 0;
    p = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

const int N = 2005;


point a[N], b[N];
type cut[N], res = DBL_MAX, tot;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(4) << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i].x >> b[i].y;
    a[n + 1] = a[1]; a[0] = a[n];
    b[m + 1] = b[1]; b[0] = b[m];
    for (int i = 1; i <= m; i++) {
        point p; cut[i] = DBL_MAX;
        for (int j = 1; j <= n; j++) {
            line l1(a[j - 1], a[j]);
            line l2(b[i - 1], b[i]);
            bool x = l2.side(a[j - 1]) <= 0;
            bool y = l2.side(a[j]) >= 0;
            if (x == y && inter(l1, l2, p) &&
            dis(p, b[i]) <= dis(p, b[i - 1]))
                cut[i] = min(cut[i], dis(p, b[i]));
            l2 = line(b[i], b[i + 1]);
            x = l2.side(a[j - 1]) <= 0;
            y = l2.side(a[j]) >= 0;
            if (x == y && inter(l1, l2, p) &&
            dis(p, b[i]) <= dis(p, b[i + 1]))
                cut[i] = min(cut[i], dis(p, b[i]));
        }
        tot += cut[i] + dis(b[i - 1], b[i]);
    }
    cut[0] = cut[m]; cut[m + 1] = cut[1];
    for (int i = 1; i <= m; i++) {
        line l2(b[i - 1], b[i]); point p;
        type cur = tot - cut[i - 1] - cut[i];
        for (int j = 1; j <= n; j++) {
            line l1(a[j - 1], a[j]);
            bool x = l2.side(a[j - 1]) <= 0;
            bool y = l2.side(a[j]) >= 0;
            if (x == y && inter(l1, l2, p)) {
                cur += min(dis(p, b[i]),
                dis(p, b[i - 1]));
            }
        }
        res = min(res, cur);
    }
    cout << res << '\n';
}