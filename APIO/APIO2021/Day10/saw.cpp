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

    bool operator < (const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

Tp dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

Tp orient(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b);
}

int main() {
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int K; cin >> K;
    vector <point> P, H;
    while (K--) {
        int N, x, y; cin >> N; N++;
        while (N--) {
            cin >> x >> y;
            if (x > 0) x = -x;
            P.emplace_back(x, y);
        }
    }
    sort(P.begin(), P.end());
    for (int i = 0, j = 0; i < P.size(); i++) {
        while (j > 1 && orient(H[j - 2], H[j - 1], P[i]) <= 0) {
            H.pop_back(); j--;
        }
        H.push_back(P[i]); j++;
    }
    double res = 0;
    for (int i = 0; i + 1 < H.size(); i++) {
        point v = H[i + 1] - H[i];
        if (!v.x || !v.y) continue;
        res = max(res, (-1.0 * H[i].x * v.y / v.x + H[i].y)
        * (1.0 * H[i].y * v.x / v.y - H[i].x));
    }
    cout << setprecision(6) << fixed << res << '\n';
}