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

    bool operator == (const point &o) const {
        return abs(x - o.x) < EPS && abs(y - o.y) < EPS;
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

point perp(point p) {
    return point(-p.y, p.x);
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
    if (abs(cross(a, b)) < EPS) return 0;
    return cross(a, b) > 0;
}

struct line {
    point v; Tp c;

    line() {}

    line(Tp a, Tp b, Tp c): v(b, -a), c(c) {}

    line(point v, Tp c): v(v), c(c) {}

    line(point p, point q): v(q - p), c(cross(v, p)) {}

    Tp side(const point &p) {
        return cross(v, p) - c;
    }

    point proj(point p) {
        return p - perp(v) * side(p) / norm(v);
    }
};

void intersect(point o, Tp r, line l, pair<point, point> &out) {
    Tp h2 = r * r - l.side(o) * l.side(o) / norm(l.v);
    if (h2 >= 0) { // the line touches the circle
        point p = l.proj(o); // point P
        point h = l.v * sqrt(h2) / abs(l.v);
        out = {p - h, p + h};
    }
}

istream& operator >> (istream &is, point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const point &p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

const int N = 100005;
const int LOG = 18;

pair<point, point> pp[N];
pair<int, int> qq[N], gg[N];
int jump[N][LOG];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    point o; Tp r;
    cin >> o.x >> o.y >> r;
    int n; cin >> n;
    vector<point> all;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        line l(a, b, -c);
        intersect(o, r, l, pp[i]);
        pp[i].first.x *= -1;
        pp[i].second.x *= -1;
        pp[i].first.y *= -1;
        pp[i].second.y *= -1;
        all.push_back(pp[i].first);
        all.push_back(pp[i].second);
    }
    
    sort(all.begin(), all.end(), cmp);
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; i++) {
        if (orient(pp[i].first, pp[i].second, o) < 0)
            swap(pp[i].first, pp[i].second);
        qq[i].first = upper_bound(all.begin(),
        all.end(), pp[i].first, cmp) - all.begin();
        qq[i].second = upper_bound(all.begin(),
        all.end(), pp[i].second, cmp) - all.begin();
        if (qq[i].second < qq[i].first)
            qq[i].second += all.size();
    }
    sort(qq, qq + n, [](pair<int, int> x, pair<int, int> y) {
        return x.first != y.first ? x.first < y.first : x.second > y.second;
    });
    vector<int> stk;
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (stk.size() && qq[stk.back()].second >= qq[i].second) {
            gg[m++] = qq[stk.back()]; stk.pop_back();
        }
        stk.push_back(i);
    }
    for (int i = 0; i + 1 < stk.size(); i++)
        gg[m++] = {qq[stk[i]].first, qq[stk[i + 1]].second};
    n--; stk.clear();
    sort(gg, gg + n, [](pair<int, int> x, pair<int, int> y) {
        return x.first != y.first ? x.first < y.first : x.second > y.second;
    });
    memset(jump, -1, sizeof jump);
    for (int i = 0; i < n; i++) {
        while (stk.size() && gg[stk.back()].second >= gg[i].second)
            stk.pop_back();
        int lo = -1, hi = stk.size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (gg[mi].second > gg[i].first) lo = mi;
            else hi = mi - 1;
        }
        if (lo >= 0) jump[i][0] = stk[lo];
        stk.push_back(i);
    }
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i < n; i++)
            if (jump[i][k - 1] >= 0)
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cur = 1, j = i;
        for (int k = LOG - 1; k >= 0; k--)
            if (jump[j][k] >= 0 && gg[i].second - gg[jump[j][k]].first < n) {
                j = jump[j][k]; cur += 1 << k;
            }
        res = max(res, cur);
    }
    cout << res;
}