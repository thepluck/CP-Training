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

void solve1(int n, vector <point <ll>> pts) {
    ll res = 1e18; point <ll> p1, p2;
    sort(pts.begin(), pts.end(),
    [](const point <ll> &a, const point <ll> &b) {
        return a.y != b.y ? a.y < b.y : a.x < b.x;
    });
    set <point <ll>> bdr;
    for (int i = 0, j = 0; i < n; i++) {
        point <ll> d = {ceil(sqrt(res)), 0};
        while (pts[i].y - pts[j].y >= d.x)
            bdr.erase(pts[j++]);
        auto lo = bdr.lower_bound(pts[i] - d);
        auto hi = bdr.upper_bound(pts[i] + d);
        for (; lo != hi; lo++)
            if (res > norm(*lo - pts[i])) {
                res = norm(*lo - pts[i]);
                p1 = *lo; p2 = pts[i];
            }
        bdr.insert(pts[i]);
    }
    ll x = p1.x + p2.x;
    ll y = p1.y + p2.y;
    cout << x / 2;
    if (x & 1) cout << ".5";
    cout << ' ' << y / 2;
    if (y & 1) cout << ".5";
    exit(0);
}

void solve2(int n, vector <point <ld>> pts) {
    point <ld> ans = welzl(n, pts, {}).cen;
    cout << ans.x << ' ' << ans.y << '\n';
    exit(0);
}

bool check(int n, int k, ld r,
const vector <point <ld>> &pts) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector <pair <ld, int>> events;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto p = pts[j] - pts[i];
            if (abs(p) > r * 2) continue;
            ld a = atan2(p.y, p.x);
            ld b = acos(abs(p) / (r * 2));
            events.emplace_back(a - b, 1);
            events.emplace_back(a + b, -1);
        }
        sort(events.begin(), events.end());
        int m = events.size(), cur = 1;
        for (int j = 0; j < m; j++)
            events.push_back(events[j]);
        for (int j = 0; j < 2 * m; j++) {
            cur += events[j].second;
            res = max(res, cur);
        }
    }
    return res >= k;
}

void solve3(int n, int k,
const vector <point <ld>> &pts) {
    ld lo = 0, hi = 1e7;
    for (int i = 0; i < 45; i++) {
        ld mi = (lo + hi) / 2;
        if (check(n, k, mi, pts)) hi = mi;
        else lo = mi;
    }
    ld r = hi; point <ld> p1, p2;
    for (int i = 0; i < n; i++) {
        vector <tuple <ld, int, int>> events;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto p = pts[j] - pts[i];
            if (abs(p) > r * 2) continue;
            ld a = atan2(p.y, p.x);
            ld b = acos(abs(p) / (r * 2));
            events.emplace_back(a - b, 1, j);
            events.emplace_back(a + b, -1, j);
        }
        sort(events.begin(), events.end());
        int m = events.size(), cur = 1;
        for (int j = 0; j < m; j++)
            events.push_back(events[j]);
        for (int j = 0; j < 2 * m; j++) {
            cur += get <1> (events[j]);
            if (cur >= k) {
                int l = get <2> (events[j]);
                point <ld> d = pts[l] - pts[i];
                ld d2 = norm(d);
                point <ld> p = {(pts[i].x + pts[l].x)
                / 2, (pts[i].y + pts[l].y) / 2};
                ld h2 = r * r - d2 / 4;
                point <ld> h = perp(d) * sqrt(h2 / d2);
                p1 = p - h; p2 = p + h; goto here;
            }
        }
    }
    here: int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += leq(dist(p1, pts[i]), r);
    if (cnt >= k) cout << p1.x << ' ' << p1.y << '\n';
    else cout << p2.x << ' ' << p2.y << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector <point <ll>> a(n);
    vector <point <ld>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        b[i].x = a[i].x; b[i].y = a[i].y;
    }
    if (k == 2) solve1(n, a);
    if (k == n) solve2(n, b);
    solve3(n, k, b);
}
