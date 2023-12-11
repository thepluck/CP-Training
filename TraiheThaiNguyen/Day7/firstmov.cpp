#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ctz __builtin_ctzll

const int N = 2e5 + 5;
int dep[N], anc[19][N], sz[N], n, q;
vector <int> adj[N];

void dfs_init(int u, int p){
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1;
            dfs_init(v, u); anc[0][v] = u;
            sz[u] += sz[v];
        }
}

int kth_anc(int u, int k){
    if (k > dep[u]) return -1;
    while (k > 0){
        u = anc[ctz(k)][u]; k -= k & -k;
    }
    return u;
}

int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    u = kth_anc(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int k = 18; ~k; k--)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}

int main(){
    freopen("firstmov.inp", "r", stdin);
    freopen("firstmov.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_init(1, 0); dep[0] = -1;
    for (int k = 1; k <= 18; k++)
        for (int u = 1; u <= n; u++)
            if (dep[u] >= (1 << k))
                anc[k][u] =
                anc[k - 1][anc[k - 1][u]];
    cin >> q;
    while (q--){
        int u, v; cin >> u >> v;
        int r = lca(u, v);
        if (r != u && r != v){
            cout << anc[0][u] << '\n';
            continue;
        }
        if (u == r){
            int k = dep[v] - dep[u];
            cout << kth_anc(v, k - 1) << '\n';
        }
        else cout << kth_anc(u, 1) << '\n';
    }
}