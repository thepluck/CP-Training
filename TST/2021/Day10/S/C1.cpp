#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

using Tp = double;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector <pair <point, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.x >> a[i].first.y;
        a[i].second = i;
    }
    shuffle(a.begin(), a.end(), rng);
    int i = 0, ans = 0; Tp res = DBL_MAX;
    while (clock() < CLOCKS_PER_SEC * 1.9) {
        if (i == n) break;
        vector <Tp> far(n);
        for (int j = 0; j < n; j++)
            far[j] = dist(a[i].first, a[j].first);
        nth_element(far.begin(),
        far.begin() + k - 1, far.end());
        if (res > far[k - 1]) {
            res = far[k - 1]; ans = a[i].second;
        }
        i++;
    }
    cout << ans + 1;
}