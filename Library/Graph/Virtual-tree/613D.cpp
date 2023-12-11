#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;
const int LG = 18;

vector <int> adj[N];
int st[N], tp, sp[N], tim;
int p[LG][N], d[N], in[N], imp[N];

void add_edge(int u, int v) {
    adj[u].eb(v);
}

void dfs(int u) {
    in[u] = ++tim;
    for (int v : adj[u]) {
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

void clear(vector <int> &v) {
    v.clear();
    v.shrink_to_fit();
}

int cal(int u) {
    int res = 0;
    if (imp[u])
        for (int v : adj[u]) {
            res += cal(v);
            if (imp[v]) {
                res++; imp[v] = 0;
            }
        }
    else {
        for (int v : adj[u]) {
            res += cal(v);
            imp[u] += imp[v];
            imp[v] = 0;
        }
        if (imp[u] > 1) {
            imp[u] = 0; res++;
        }
    }
    clear(adj[u]); return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    d[0] = -1; dfs(1);
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++)
            p[k][i] = p[k - 1][p[k - 1][i]];
    auto cmp = [&](int x, int y) {
        return in[x] < in[y];
    };
    for (int i = 1; i <= n; i++)
        clear(adj[i]);
    int q; cin >> q;
    while (q--) {
        int k; bool ok = 0; cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> sp[i]; imp[sp[i]] = 1;
        }
        for (int i = 0; i < k; i++)
            ok |= imp[p[0][sp[i]]];
        if (ok) {
            for (int i = 0; i < k; i++)
                imp[sp[i]] = 0;
            cout << "-1\n"; continue;
        }
        sort(sp, sp + k, cmp);
        st[tp = 0] = 1;
        for (int i = 0; i < k; i++) {
            if (sp[i] == 1) continue;
            int r = lca(st[tp], sp[i]);
            while (tp && d[r] < d[st[tp - 1]]) {
                adj[st[tp - 1]].eb(st[tp]);
                tp--;
            }
            if (d[r] < d[st[tp]])
                adj[r].eb(st[tp--]);
            if (st[tp] != r) st[++tp] = r;
            st[++tp] = sp[i];
        }
        while (tp) {
            adj[st[tp - 1]].eb(st[tp]);
            tp--;
        }
        cout << cal(1) << '\n'; imp[1] = 0;
    }
}