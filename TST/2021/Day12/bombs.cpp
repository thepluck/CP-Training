#include <bits/stdc++.h>

using namespace std;

using Tp = double;

const Tp EPS = 1e-9;
const int N = 200005;
const Tp PI = 3.14159265359;
const int LG = 18;

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

bool eq(Tp x, Tp y) {
    return abs(x - y) < EPS;
}

bool le(Tp x, Tp y) {
    return x < y || eq(x, y);
}

bool ge(Tp x, Tp y) {
    return x > y || eq(x, y);
}

struct segment {
    Tp l, r; int id;

    bool operator < (const segment &o) const {
        return eq(l, o.l) ? r < o.r : l < o.l;
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

point pt[N]; int n, m;
bool ban[N]; int nxt[LG][N];

bool check(Tp rad) {
    memset(ban, 0, sizeof ban);
    vector <segment> tmp, cur;
    for (int i = 0; i < n; i++) {
        Tp a = atan2(pt[i].y, pt[i].x);
        Tp b = acos(rad / abs(pt[i]));
        tmp.push_back({a - b, a + b, i});
        a += PI * 2;
        tmp.push_back({a - b, a + b, i});
    }
    sort(tmp.begin(), tmp.end());
    Tp minR = 1e18;
    for (int i = tmp.size() - 1; i >= 0; i--) {
        if (ge(tmp[i].r, minR)) ban[tmp[i].id] = 1;
        minR = min(minR, tmp[i].r);
    }
    for (auto s : tmp)
        if (!ban[s.id]) cur.push_back(s);
    int k = cur.size();
    for (int i = 0, j = 0; i < k; i++) {
        while (j < k && le(cur[j].l, cur[i].r)) j++;
        nxt[0][i] = j;
    }
    nxt[0][k] = k;
    for (int b = 1; b < LG; b++)
        for (int i = 0; i <= k; i++)
            nxt[b][i] = nxt[b - 1][nxt[b - 1][i]];
    for (int i = 0; i < k / 2; i++) {
        int res = 1, j = i;
        for (int b = LG - 1; b >= 0; b--)
            if (nxt[b][j] < i + k / 2) {
                res += 1 << b; j = nxt[b][j];
            }
        if (res <= m) return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    Tp lo = 0, hi = 1e6;
    for (int i = 0; i < n; i++) {
        cin >> pt[i].x >> pt[i].y;
        hi = min(hi, abs(pt[i]));
    }
    for (int i = 0; i < 40; i++) {
        Tp mi = (lo + hi) / 2;
        if (check(mi)) lo = mi;
        else hi = mi;
    }
    cout << setprecision(10) <<
    fixed << (lo + hi) / 2 << '\n';
}