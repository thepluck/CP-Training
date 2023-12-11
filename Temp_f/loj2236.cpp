#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 3e5 + 5;
const int LG = 19;

int p[LG][N], d[N], a[N], s[N];
vector <int> adj[N];

void dfs(int u) {
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

void cal(int u) {
    for (int v : adj[u]) {
        if (v == p[0][u]) continue;
        cal(v); s[u] += s[v];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1); d[0] = -1;
    for (int k = 1; k < LG; k++)
        for (int u = 1; u <= n; u++)
            p[k][u] = p[k - 1][p[k - 1][u]];
    for (int i = 1; i < n; i++) {
        int u = a[i], v = a[i + 1];
        int r = lca(u, v);
        if (v == r) {
            int x = u;
            for (int k = LG - 1; ~k; k--)
                if (d[p[k][x]] > d[v])
                    x = p[k][x];
            v = x;
        }
        else v = p[0][v];
        r = lca(u, v);
        s[u]++; s[v]++;
        s[r]--; s[p[0][r]]--;
    }
    cal(1);
    for (int i = 1; i <= n; i++)
        cout << s[i] << '\n';
}