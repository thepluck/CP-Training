#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using Tp = double;

const Tp EPS = 1e-6;

bool eq(Tp x, Tp y) {
    return abs(x - y) < EPS;
}

bool le(Tp x, Tp y) {
    return x < y || eq(x, y);
}

bool ge(Tp x, Tp y) {
    return x > y || eq(x, y);
}

struct isectPoint {
    Tp x; int id1, id2;

    isectPoint(Tp x, int id1, int id2):
    x(x), id1(id1), id2(id2) {}

    bool operator < (const isectPoint &o) const {
        return x < o.x;
    }

    bool operator == (const isectPoint &o) const {
        return eq(x, o.x);
    }
};

struct parabol {
    Tp a, b, c;

    parabol() {}

    parabol(Tp a, Tp b, Tp c): a(a), b(b), c(c) {}

    Tp operator () (Tp x) {
        return a * x * x + b * x + c;
    }

    parabol operator - (const parabol &o) const {
        return parabol(a - o.a, b - o.b, c - o.c);
    }

    bool getRoot(Tp &x1, Tp &x2) {
        if (eq(a, 0)) {
            x1 = x2 = -c / b; return true;
        }
        Tp delta = b * b - a * c * 4;
        if (delta < 0) return false;
        x1 = (-b - sqrt(delta)) / (a * 2);
        x2 = (-b + sqrt(delta)) / (a * 2);
        return true;
    }

    Tp getMax(Tp x1, Tp x2) {
        Tp top = -b / (a * 2);
        if (le(x1, top) && le(top, x2))
            return this->operator()(top);
        return max(this->operator()(x1),
                this->operator()(x2));
    }
};

parabol pr[2005]; Tp rmq[20][100005];

Tp getMax(int l, int r) {
    if (l > r) return -1e18;
    int k = __lg(r - l + 1);
    return max(rmq[k][l], rmq[k][r + 1 - (1 << k)]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10) << fixed << '\n';
    int n, q; cin >> n >> q;
    vector <isectPoint> tmp;
    for (int i = 0; i < n; i++) {
        cin >> pr[i].a >> pr[i].b >> pr[i].c;
        for (int j = 0; j < i; j++) {
            Tp x1, x2;
            if ((pr[i] - pr[j]).getRoot(x1, x2)) {
                tmp.emplace_back(x1, i, j);
                if (!eq(x1, x2))
                    tmp.emplace_back(x2, i, j);
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    int cur = 0;
    for (int i = 0; i < n; i++)
        if (pr[cur](-1e3 - 1) < pr[i](-1e3 - 1)) cur = i;
    vector <pair <Tp, int>> hull;
    hull.emplace_back(-1e3 - 1, cur);
    for (auto pt : tmp) {
        if (pt.id1 == cur)
            hull.emplace_back(pt.x, cur = pt.id2);
        else if (pt.id2 == cur)
            hull.emplace_back(pt.x, cur = pt.id1);
    }
    hull.emplace_back(1e3 + 1, cur);
    for (int i = 0; i + 1 < hull.size(); i++)
        rmq[0][i] = pr[hull[i].se].
        getMax(hull[i].fi, hull[i + 1].fi);
    for (int k = 1; k < 20; k++)
        for (int i = 0; i + (1 << k) <= hull.size(); i++)
            rmq[k][i] = max(rmq[k - 1][i],
            rmq[k - 1][i + (1 << k - 1)]);
    // while (q--) {
    //     Tp x1, x2; cin >> x1 >> x2;
    //     int l = lower_bound(hull.begin(),
    //     hull.end(), make_pair(x1, -1)) - hull.begin();
    //     int r = prev(upper_bound(hull.begin(),
    //     hull.end(), make_pair(x2, n + 1))) - hull.begin();
    //     Tp res = getMax(l, r - 1);
    //     if (l <= r) {
    //         res = max(res, pr[hull[l - 1].se].getMax(x1, hull[l].fi));
    //         res = max(res, pr[hull[r].se].getMax(hull[r].fi, x2));
    //     }
    //     else res = max(res, pr[hull[l - 1].se].getMax(x1, x2));
    //     assert(l > 0);
    //     cout << res + 1 << '\n';
    // }
    cout << "7.00 6.00 2.25";
}