#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 3e5 + 5;

using ii = pair <int, int>;

int n, par[N], wpar[N];
ll down[N], sub[N], res;
vector <ii> adj[N];

void dfs_dp(int u) {
    for (ii pp : adj[u]) {
        int v, w; tie(v, w) = pp; dfs_dp(v);
        cmax(sub[u], down[u] + down[v] + w);
        cmax(sub[u], sub[v]);
        cmax(down[u], down[v] + w);
    }
}

void dfs_reroot(int u) {
    vector <ll> dpre, dsuf, spre, ssuf;
    dpre.eb(0); dsuf.eb(0);
    spre.eb(0); ssuf.eb(0);
    int ch = adj[u].size();
    for (int i = 0; i < ch; i++) {
        int v, w; tie(v, w) = adj[u][i];
        dpre.eb(down[v] + w);
        dsuf.eb(down[v] + w);
        spre.eb(sub[v]); ssuf.eb(sub[v]);
    }
    dpre.eb(0); dsuf.eb(0);
    spre.eb(0); ssuf.eb(0);
    for (int i = 1; i <= ch; i++) {
        cmax(spre[i], spre[i - 1]);
        cmax(spre[i], dpre[i] + dpre[i - 1]);
        cmax(dpre[i], dpre[i - 1]);
    }
    for (int i = ch; i > 0; i--) {
        int v, w; tie(v, w) = adj[u][i - 1];
        cmax(ssuf[i], ssuf[i + 1]);
        cmax(ssuf[i], dsuf[i] + dsuf[i + 1]);
        cmax(dsuf[i], dsuf[i + 1]);
        int subu = sub[u], subv = sub[v];
        int downu = down[u], downv = down[v];
        sub[u] = max({spre[i - 1], ssuf[i + 1],
        dpre[i - 1] + dsuf[i + 1]});
        down[u] = max(dpre[i - 1], dsuf[i + 1]);
        if (par[u]) {
            int p = par[u];
            cmax(sub[u], sub[p]);
            cmax(sub[u], down[p] + wpar[u]
            + max(dpre[i - 1], dsuf[i + 1]));
            cmax(down[u], down[p] + wpar[u]);
        }
        cmin(res, abs(sub[u] - sub[v]));
        cmax(sub[v], sub[u]);
        cmax(sub[v], down[u] + down[v] + w);
        cmax(down[v], down[u] + w);
        dfs_reroot(v);
        sub[v] = subv; down[v] = downv;
        sub[u] = subu; down[u] = downu;
    }
}

void solve() {
    if (n == 0) return;
    for (int i = 1; i <= n; i++) {
        down[i] = sub[i] = 0;
        adj[i].clear();
    }
    res = LLONG_MAX;
    for (int i = 2; i <= n; i++) {
        int p, w; cin >> p >> w;
        adj[p].eb(i, w);
        par[i] = p; wpar[i] = w;
    }
    dfs_dp(1); dfs_reroot(1);
    cout << res << '\n';
}

int main() {
    while (cin >> n) solve();
}
