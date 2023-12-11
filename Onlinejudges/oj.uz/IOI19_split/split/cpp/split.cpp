#include "split.h"
#include <bits/stdc++.h>

using namespace std;

namespace {
    vector<vector<int>> adj, chd;
    vector<int> siz, low, num, ans, par;
    int cnt;

    void dfs1(int u) {
        siz[u] = 1;
        low[u] = num[u] = ++cnt;
        for (int v : adj[u])
            if (!num[v]) {
                par[v] = u; dfs1(v);
                siz[u] += siz[v];
                chd[u].push_back(v);
                low[u] = min(low[u], low[v]);
            } else if (v != par[u])
                low[u] = min(low[u], num[v]);
    }

    void dfs2(int u, int &s, int l) {
        if (!s) return;
        s--; ans[u] = l;
        for (int v : chd[u])
            dfs2(v, s, l);
    }

    void dfs3(int u, int &s, int l) {
        if (!s) return;
        s--; ans[u] = l;
        for (int v : adj[u])
            if (!ans[v]) dfs3(v, s, l);
    }
}

vector<int> find_split(int n, int a, int b,
int c, vector<int> p, vector<int> q) {
#define fi first
#define se second
    int m = p.size();
    vector<pair<int, int>> s(3);
    s[0] = {a, 1}; s[1] = {b, 2}; s[2] = {c, 3};
    sort(s.begin(), s.end());
    adj.resize(n); siz.resize(n);
    chd.resize(n); low.resize(n);
    num.resize(n); ans.resize(n);
    par.resize(n); par[0] = -1;
    for (int i = 0; i < m; i++) {
        adj[p[i]].push_back(q[i]);
        adj[q[i]].push_back(p[i]);
    }
    dfs1(0); int u = 0;
    while (true) {
        bool flag = false;
        for (int v : chd[u])
            if (siz[v] >= s[0].fi) {
                u = v; flag = true; break;
            }
        if (!flag) break;
    }
    if (siz[u] + s[1].fi <= n) {
        dfs2(u, s[0].fi, s[0].se);
        dfs3(par[u], s[1].fi, s[1].se);
    } else {
        s[1].fi--; ans[u] = s[1].se;
        for (int v : chd[u])
            if (low[v] >= num[u])
                dfs2(v, s[1].fi, s[1].se);
        for (int v : chd[u])
            if (low[v] < num[u])
                dfs2(v, s[1].fi, s[1].se);
        if (u) dfs3(par[u], s[0].fi, s[0].se);
        if (s[0].fi) return vector<int> (n, 0);
    }
    for (int i = 0; i < n; i++)
        if (!ans[i]) ans[i] = s[2].se;
    return ans;
#undef fi
#undef se
}
