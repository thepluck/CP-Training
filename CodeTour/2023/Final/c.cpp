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

double circle_intersection() {

}

const int N = 1e3 + 5;

double dis[N];
bool vis[N];
circle c[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> c[i].cen.x >> c[i].cen.y >> c[i].rad;
    if (c[i].cen.y - c[i].rad <= 0) {
      dis[i] = 1; 
    }

  }
  dis[0] = 1e9;
  for (int i = 1; i <= k; i++) {
    int best = 0;
    for (int j = 1; j <= k; j++)
      if (!vis[j] && leq(dis[j], dis[best]))
        best = j;
    if (c[best].cen.y + c[best].rad >= m) {
      cout << dis[best] + 1 << '\n';
      return 0;
    }
    vis[best] = 1;
    
  }
}