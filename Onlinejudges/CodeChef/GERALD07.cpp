#include <bits/stdc++.h>
using namespace std;

struct state {int u, par, rnk, cmp;};

struct query {int l, r, i;};

struct edge {int u, v;};

const int N = 200005, K = 500;

vector <state> chg;
int n, m, q, cmp, ans[N], par[N], rnk[N];
query que[N]; edge ed[N];

void make_set() {
    for (int i = 1; i <= n; i++) {
        par[i] = i; rnk[i] = 0;
    }
    cmp = n; chg.clear();
}

void roll_back() {
    while (chg.size()) {
        par[chg.back().u] = chg.back().par;
        rnk[chg.back().u] = chg.back().rnk;
        cmp = chg.back().cmp; chg.pop_back();
    }
}

int find_set(int u) {
    return u == par[u] ? u : find_set(par[u]);
}

void union_set(int u, int v) {
    u = find_set(u); v = find_set(v);
    if (u == v) return;
    if (rnk[u] == rnk[v]) {
        chg.push_back({u, par[u], rnk[u], cmp});
        rnk[u]++;
    }
    if (rnk[u] > rnk[v]) {
        chg.push_back({v, par[v], rnk[v], cmp});
        par[v] = u;
    }
    else {
        chg.push_back({u, par[u], rnk[u], cmp});
        par[u] = v;
    }
    cmp--;
}

void snap_shot() {chg.clear();}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> ed[i].u >> ed[i].v;
    for (int i = 1; i <= q; i++) {
        cin >> que[i].l >> que[i].r;
        que[i].i = i;
    }
    sort(que + 1, que + q + 1,
    [](const query &x, const query &y) {
        return x.l / K != y.l / K ?
        x.l / K < y.l / K : x.r < y.r; 
    });
    make_set(); int last = -1, l, r;
    for (int i = 1; i <= q; i++) {
        if (que[i].r - que[i].l > K) continue;
        snap_shot();
        for (int j = que[i].l; j <= que[i].r; j++)
            union_set(ed[j].u, ed[j].v);
        ans[que[i].i] = cmp;
        roll_back();
    }
    for (int i = 1; i <= q; i++) {
        if (que[i].r - que[i].l <= K) continue;
        int cur = que[i].l / K;
        if (cur != last) {
            make_set(); last = cur;
            l = (cur + 1) * K; r = l - 1;
        }
        while (r < que[i].r) {
            r++; union_set(ed[r].u, ed[r].v);
        }
        snap_shot();
        for (int j = que[i].l; j < l; j++)
            union_set(ed[j].u, ed[j].v);
        ans[que[i].i] = cmp;
        roll_back();
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}