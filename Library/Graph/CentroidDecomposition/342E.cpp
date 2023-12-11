#define FOR(i, j, k) for (int i = (j); i <= (k); i++)
#define FORD(i, j, k) for (int i = (j); i >= (k); i--)
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 100005;
vector <int> adj[N];
int par[N], ans[N], sz[N];
int anc[18][N], dep[N], n, q;
bitset <N> used;

void add_edge(int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u);
}

void dfs(int v, int p){
    for (int c : adj[v]) 
        if (c != p){
            dep[c] = dep[v] + 1;
            anc[0][c] = v; dfs(c, v);
        }
}

void dfs_sz(int v, int p){
    sz[v] = 1;
    for (int c : adj[v])
        if (c != p && !used[c]){
            dfs_sz(c, v); sz[v] += sz[c];
        }
}

int dfs_cen(int v, int p, int r){
    for (int c : adj[v])
        if (!used[c] && c != p)
            if (sz[c] * 2 >= sz[r])
                return dfs_cen(c, v, r);
    return v;
}

void decompose(int v, int r){
    dfs_sz(v, 0); 
    int cen = dfs_cen(v, 0, v);
    used[cen] = 1; par[cen] = r;
    for (int c : adj[cen])
        if (!used[c]) decompose(c, cen);
}

int lca(int u, int v){
    if (dep[u] < dep[v]) return lca(v, u);
    FORD(k, 17, 0)
        if (dep[anc[k][u]] >= dep[v])
            u = anc[k][u];
    FORD(k, 17, 0)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return u == v ? u : anc[0][u];
}

int dist(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void update(int v){
    int u = v;
    while (u != 0){
        ans[u] = min(ans[u], dist(u, v));
        u = par[u];
    }
}

int query(int v){
    int u = v, res = inf;
    while (u != 0){
        res = min(res, dist(u, v) + ans[u]);
        u = par[u];
    }
    return res;
}

void prepare(){
    dfs(1, 0); decompose(1, 0);
    FOR(k, 1, 17) FOR(i, 1, n)
        if (dep[i] >= (1 << k))
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
    FOR(i, 1, n) ans[i] = inf; update(1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; add_edge(u, v);
    }
    prepare(); int cmd, v;
    while (q--){
        cin >> cmd >> v;
        if (cmd == 1) update(v);
        else cout << query(v) << '\n';
    }
}