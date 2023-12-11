#include <bits/stdc++.h>

using namespace std;

#define sqr(x) 1ll * (x) * (x)

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct line {
    ll k, m, p;

    bool operator < (const ll &x) const {
        return p < x;
    }
};

struct ConvexHull: vector <line> {
    iterator iter;

    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(line &x, line y) {
        if (x.k == y.k)
            x.p = x.m > y.m ? INF : -INF;
        else x.p = div(y.m - x.m, x.k - y.k);
        return x.p >= y.p;
    }

    void add(ll k, ll m) {
        iterator x = end(), y;
        line l = {k, m, INF};
        if (x != begin()) isect(*(--x), l);
        while ((y = x) != begin()
        && (--x)->p >= y->p) {
            pop_back(); isect(*x, l);
        }
        push_back(l);
    }

    ll get(ll x, bool t = 0) {
        if (!t) {
            line l = *lower_bound(begin(), end(), x);
            return l.k * x + l.m;
        }
        while (*iter < x) iter++;
        return iter->k * x + iter->m;
    }
};

const int MAXN = 500005;
const int BLOCK = 350;

int col[MAXN], N, M;
ll sum[MAXN]; int last[MAXN];
int lazy[BLOCK], cnt[MAXN];
ConvexHull hull[BLOCK];

#define lef(id) id * BLOCK + 1
#define rig(id) min((id + 1) * BLOCK, N)

void inc(int id, int l, int r) {
    l = max(l, lef(id));
    r = min(r, rig(id));
    if (l > r) return;
    if (l == lef(id) && r == rig(id)) {
        lazy[id]++; return;
    }
    for (int i = l; i <= r; i++)
        cnt[i]++;
    l = lef(id); r = rig(id);
    for (int i = l; i <= r; i++)
        cnt[i] += lazy[id];
    lazy[id] = 0; hull[id].clear();
    for (int i = r; i >= l; i--)
        hull[id].add(2ll * M * cnt[i],
        sqr(cnt[i]) * M - sum[i - 1]);
    hull[id].iter = hull[id].begin();
}

ll get(int id, int l, int r) {
    l = max(l, lef(id));
    r = min(r, rig(id));
    if (l > r) return -INF;
    if (l == lef(id) && r == rig(id))
        return hull[id].get(lazy[id], true)
                + sqr(lazy[id]) * M;
    ll res = -INF;
    for (int i = l; i <= r; i++)
        res = max(res, sqr(cnt[i] +
        lazy[id]) * M - sum[i - 1]);
    return res;
}

#undef lef
#undef rig

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> col[i] >> sum[i];
        sum[i] += sum[i - 1];
    }
    long long res = -INF;
    if (count(col + 1, col + N + 1, 1) == N) {
        ll min_sum = 0;
        for (int i = 1; i <= N; i++) {
            res = max(res, sum[i] - min_sum);
            min_sum = min(min_sum, sum[i]);
        }
        return cout << res + M, 0;
    }
    bool flag = true;
    for (int i = 1; i <= N; i++)
        if (col[i] != i) flag = false;
    if (flag) {
        ConvexHull cht;
        for (int i = 1; i <= N; i++) {
            cht.add(2ll * M * (i - 1),
            sqr(i - 1) * M - sum[i - 1]);
            res = max(res, sum[i] +
            sqr(i) * M + cht.get(-i));
        }
        return cout << res, 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int id = 0; id < BLOCK; id++)
            inc(id, last[col[i]] + 1, i);
        last[col[i]] = i;
        for (int id = 0; id < BLOCK; id++)
            res = max(res, get(id, 1, i) + sum[i]);
    }
    cout << res << '\n';
    
}