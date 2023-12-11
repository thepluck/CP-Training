#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int BUC = 1000;

struct edge {
    int u, v;
};

struct query {
    int l, r, id;
};

int sum[MAXN], N, M, Q;
vector <int> adj[MAXN], chg;
long long ans[MAXN], res;
int par[MAXN], siz[MAXN];

void makeSet() {
    for (int i = 1; i <= N; i++) {
        par[i] = 0; siz[i] = 1;
    }
    res = N; chg.clear();
}

int findSet(int u) {
    while (par[u]) u = par[u];
    return u;
}

#define sqr(x) 1ll * (x) * (x)

bool uniteSet(int u, int v) {
    u = findSet(u); v = findSet(v);
    if (u == v) return false;
    if (siz[u] < siz[v]) swap(u, v);
    chg.emplace_back(v);
    res -= sqr(siz[u]) + sqr(siz[v]);
    par[v] = u; siz[u] += siz[v];
    res += sqr(siz[u]); return true;
}

void rollBack() {
    while (chg.size()) {
        int v = chg.back(), u = par[v];
        chg.pop_back(); par[v] = 0;
        res -= sqr(siz[u]); siz[u] -= siz[v];
        res += sqr(siz[u]) + sqr(siz[v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        sum[u]++; sum[v]++;
    }
    for (int i = 1; i <= N; i++)
        sum[i] += sum[i - 1];
    vector <edge> grp;
    for (int u = 1; u <= N; u++)
        for (int v : adj[u])
            grp.push_back({u, v});
    vector <query> que;
    for (int i = 1; i <= Q; i++) {
        int l, r; cin >> l >> r;
        que.push_back({l, r, i});
    }
    sort(que.begin(), que.end(),
    [&](query x, query y) {
        return sum[x.l - 1] / BUC != sum[y.l - 1] / BUC ?
        sum[x.l - 1] < sum[y.l - 1] : sum[x.r] < sum[y.r];
    });
    makeSet();
    for (auto q : que) {
        if (sum[q.r] - sum[q.l - 1] > BUC) continue;
        chg.clear();
        for (int i = sum[q.l - 1]; i < sum[q.r]; i++)
            if (grp[i].v >= q.l && grp[i].v <= q.r)
                uniteSet(grp[i].u, grp[i].v);
        ans[q.id] = res - (N - (q.r - q.l + 1));
        rollBack();
    }
    int last = -1, l, r, lim = 0;
    for (auto q : que) {
        if (sum[q.r] - sum[q.l - 1] <= BUC) continue;
        int cur = sum[q.l - 1] / BUC;
        if (cur != last) {
            makeSet(); last = cur;
            l = r = (cur + 1) * BUC;
            while (lim < N && sum[lim] <= l) lim++;
        }
        while (r < sum[q.r]) {
            if (grp[r].v >= lim && grp[r].v <= q.r)
                uniteSet(grp[r].u, grp[r].v);
            r++;
        }
        chg.clear();
        for (int i = sum[q.l - 1]; i < l; i++)
            if (grp[i].v >= q.l && grp[i].v <= q.r)
                uniteSet(grp[i].u, grp[i].v);
        ans[q.id] = res - (N - (q.r - q.l + 1));
        rollBack();
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}