#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ctz __builtin_ctzll

const int N = 2e5 + 5;
int dep[N], anc[19][N], que[N], ans[N];
vector <int> adj[N]; bitset <N> era;

void dfs_init(int u, int p){
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1;
            dfs_init(v, u); anc[0][v] = u;
        }
}

int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = 18; ~k; k--)
        if (dep[anc[k][u]] >= dep[v])
            u = anc[k][u];
    if (u == v) return u;
    for (int k = 18; ~k; k--)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}

int kth_anc(int u, int k){
    if (k > dep[u]) return -1;
    while (k > 0){
        u = anc[ctz(k)][u]; k -= k & -k;
    }
    return u;
}

int dis(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main(){
    freopen("deltree.inp", "r", stdin);
    freopen("deltree.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs_init(1, 0); dep[0] = -1; int cnt = q;
    for (int k = 1; k <= 18; k++)
        for (int u = 1; u <= n; u++)
            if (dep[u] >= (1 << k))
                anc[k][u] = anc[k - 1][anc[k - 1][u]];
    for (int i = 1; i <= q; i++){
        cin >> que[i]; era[que[i]] = 1;
    }
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++)
        if (!era[i]) adj[dep[i]].eb(i);
    for (int i = n - 1; ~i; i--)
        for (int u : adj[i]) que[++cnt] = u;
    int u = que[n], v = que[n];
    for (int i = n - 1; i > 0; i--){
        ans[i] = max({ans[i + 1],
        dis(que[i], u), dis(que[i], v)});
        if (ans[i] == dis(que[i], u)) v = que[i];
        else if (ans[i] == dis(que[i], v)) u = que[i];
    }
    for (int i = 2; i <= q + 1; i++)
        cout << ans[i] << '\n';
}