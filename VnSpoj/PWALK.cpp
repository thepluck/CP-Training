#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, w;
};

const int N = 1e3 + 5;
vector <edge> adj[N];
int dep[N], anc[N][11], len[N][11];
int n, q;

void dfs(int u, int par){
    for (auto e : adj[u])
        if (e.u != par){
            dep[e.u] = dep[u] + 1;
            anc[e.u][0] = u; dfs(e.u, u);
            len[e.u][0] = e.w;
        }
}

void pre_calc(){
    dfs(1, 0); dep[0] = -1;
    for (int k = 1; k <= 10; k++)
        for (int i = 1; i <= n; i++)
            if (dep[i] >= (1 << k)){
                anc[i][k] = anc[anc[i][k - 1]][k - 1];
                len[i][k] = len[i][k - 1] + len[anc[i][k - 1]][k - 1];
            }
}

int get_len(int u, int v){
    int res = 0;
    if (dep[u] < dep[v]) return get_len(v, u);
    for (int k = 10; k >= 0; k--)
        if (dep[anc[u][k]] >= dep[v]){
            res += len[u][k]; u = anc[u][k];
        }
    if (u == v) return res;
    for (int k = 10; k >= 0; k--)
        if (anc[u][k] != anc[v][k]){
            res += len[u][k] + len[v][k];
            u = anc[u][k]; v = anc[v][k];
        }
    res += len[u][0] + len[v][0];
    return res;
}

int main(){
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    pre_calc();
    while (q--){
        int u, v; cin >> u >> v;
        cout << get_len(u, v) << '\n';
    }
}
