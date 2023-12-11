//https://www.hackerrank.com/contests/hourrank-15/challenges/kittys-calculations-on-a-tree/problem
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

const int N = 2e5 + 5;
const int LG = 18;
const int MOD = 1e9 + 7;

ll sv[N], sdv[N], res;
int st[N], tp, p[LG][N], d[N];
int tin[N], tim, sp[N];
vector <int> g[N]; bool imp[N];

void madd(ll &x, ll y) {
    (x += y) %= MOD;
}

void msub(ll &x, ll y) {
    if (((x -= y) %= MOD) < 0)
        x += MOD;
}

void clear(vector <int> &v) {
    v.clear();
    v.shrink_to_fit();
}

void dfs(int u) {
    tin[u] = ++tim; 
    for (int v : g[u]) {
        if (v == p[0][u]) continue;
        d[v] = d[u] + 1;
        p[0][v] = u; dfs(v);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int k = LG - 1; ~k; k--)
        if (d[p[k][u]] >= d[v])
            u = p[k][u];
    if (u == v) return u;
    for (int k = LG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            u = p[k][u]; v = p[k][v];
        }
    return p[0][u];
}

void cal(int u) {
    sv[u] = imp[u] ? u : 0;
    sdv[u] = sv[u] * d[u] % MOD;
    for (int v : g[u]) {
        cal(v);
        madd(res, sdv[u] * sv[v]);
        madd(res, sdv[v] * sv[u]);
        msub(res, sv[u] * sv[v]
        * 2 % MOD * d[u] % MOD);
        madd(sv[u], sv[v]);
        madd(sdv[u], sdv[v]);
    }
    imp[u] = 0; clear(g[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    auto cmp = [&](int x, int y) {
        return tin[x] < tin[y];
    };
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    d[0] = -1; dfs(1);
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++)
            p[k][i] = p[k - 1][p[k - 1][i]];
    for (int i = 1; i <= n; i++)
        clear(g[i]);
    while (q--) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> sp[i]; imp[sp[i]] = 1;
        }
        sort(sp, sp + k, cmp);
        st[tp = 0] = 1;
        for (int i = 0; i < k; i++) {
            if (sp[i] == 1) continue;
            int r = lca(sp[i], st[tp]);
            while (tp && d[r] < d[st[tp - 1]]) {
                g[st[tp - 1]].eb(st[tp]); tp--;
            }
            if (d[r] < d[st[tp]])
                g[r].eb(st[tp--]);
            if (st[tp] != r) st[++tp] = r;
            if (st[tp] != sp[i]) st[++tp] = sp[i];
        }
        while (tp) {
            g[st[tp - 1]].eb(st[tp]); tp--;
        }
        res = 0; cal(1); cout << res << '\n';
    }
}