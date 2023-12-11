#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct frac {
    long long a, b;

    frac(long long a, long long b) {
        if (b < 0) a = -a, b = -b;
        this->a = a; this->b = b;
    }

    bool operator < (const frac &o) const {
        return a * o.b < b * o.a;
    }
};

const int N = 1e5 + 5;

vector <pair <int, int>> tmp[2]; int BIT[N];

void update(int i) {
    for (; i > 0; i -= i & -i) BIT[i]++;
}

int query(int i) {
    int res = 0;
    for (; i < N; i += i & -i) res += BIT[i];
    return res;
}

long long calc1(int w) {
    vector <frac> val[2];
    for (auto pl : tmp[0])
        val[0].emplace_back(pl.se + w, pl.fi);
    for (auto pl : tmp[1])
        val[1].emplace_back(pl.se + w, pl.fi);
    sort(val[0].begin(), val[0].end());
    sort(val[1].begin(), val[1].end());
    memset(BIT, 0, sizeof BIT);
    long long res = 0;
    for (int i = 0; i < val[0].size(); i++) {
        int cur = upper_bound(val[0].begin(),
        val[0].end(), frac(tmp[0][i].se + w,
        tmp[0][i].fi)) - val[0].begin();
        res += query(cur); update(cur);
    }
    memset(BIT, 0, sizeof BIT);
    for (int i = 0; i < val[1].size(); i++) {
        int cur = upper_bound(val[1].begin(),
        val[1].end(), frac(tmp[1][i].se + w,
        tmp[1][i].fi)) - val[1].begin();
        res += query(cur); update(cur);
    }
    for (auto fr : val[1])
        res += upper_bound(val[0].begin(),
        val[0].end(), fr) - val[0].begin();
    return res;
}

long long calc2(int w) {
    vector <frac> val[2];
    for (auto pl : tmp[0])
        val[0].emplace_back(pl.se + w, pl.fi);
    for (auto pl : tmp[1])
        val[1].emplace_back(pl.se + w, pl.fi);
    sort(val[0].begin(), val[0].end());
    sort(val[1].begin(), val[1].end());
    memset(BIT, 0, sizeof BIT);
    long long res = 0;
    for (int i = 0; i < val[0].size(); i++) {
        int cur = upper_bound(val[0].begin(),
        val[0].end(), frac(tmp[0][i].se + w,
        tmp[0][i].fi)) - val[0].begin();
        res += query(cur + 1); update(cur);
    }
    memset(BIT, 0, sizeof BIT);
    for (int i = 0; i < val[1].size(); i++) {
        int cur = upper_bound(val[1].begin(),
        val[1].end(), frac(tmp[1][i].se + w,
        tmp[1][i].fi)) - val[1].begin();
        res += query(cur + 1); update(cur);
    }
    for (auto fr : val[1])
        res += lower_bound(val[0].begin(),
        val[0].end(), fr) - val[0].begin();
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, w; cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int x, v; cin >> x >> v;
        tmp[x > 0].emplace_back(x, v);
    }
    sort(tmp[0].begin(), tmp[0].end());
    sort(tmp[1].begin(), tmp[1].end());
    cout << calc1(w) - calc2(-w) << '\n';
}