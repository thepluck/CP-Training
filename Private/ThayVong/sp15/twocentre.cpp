#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ctz __builtin_ctz
using ll = long long;

struct edge{
    int v, w;

    edge(){}

    edge(int v, int w): v(v), w(w){}
};

const int N = 2e5 + 5;
int anc[19][N], dep[N], n, q;
ll dis[N];
vector <edge> adj[N];

void dfs(int u, int p){
    for (auto e : adj[u])
        if (e.v != p){
            dep[e.v] = dep[u] + 1;
            dis[e.v] = dis[u] + e.w;
            anc[0][e.v] = u; dfs(e.v, u);
        }
}

void prepare(){
    dfs(1, 0); dep[0] = -1;
    for (int k = 1; k <= 18; k++)
        for (int u = 1; u <= n; u++)
            if (dep[u] >= (1 << k))
                anc[k][u] = anc[k - 1][anc[k - 1][u]];
}

int lca(int u, int v){
    if (dep[u] < dep[v]) return lca(v, u);
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
    while (k > 0){
        u = anc[ctz(k)][u]; k -= k & -k;
    }
    return u;
}

int main(){
    freopen("twocentre.inp", "r", stdin);
    freopen("twocentre.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    prepare(); cin >> q;
    for (int i = 1, u, v; i <= q; i++){
        cin >> u >> v;
        cout << dis[u] + dis[v] -
                2 * dis[lca(u, v)] << '\n';
    }
}