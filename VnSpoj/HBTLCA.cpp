#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;
const int LOG = 20;
int anc[LOG][N], dep[N];
int in[N], out[N], tim;
vector <int> adj[N];

bool is_anc(int u, int p){
    return in[u] >= in[p] &&
            out[u] <= out[p];
}

void dfs(int u, int p){
    in[u] = ++tim;
    for (int v : adj[u]){
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        anc[0][v] = u; dfs(v, u);
    }
    out[u] = tim;
}

int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LOG - 1; ~k; k--)
        if (dep[anc[k][u]] >= dep[v])
            u = anc[k][u];
    if (u == v) return u;
    for (int k = LOG - 1; ~k; k--)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}

int lca(int r, int u, int v){
    int p = lca(u, v);
    if (!is_anc(r, p)) return p;
    if (is_anc(u, r) || is_anc(v, r))
        return r;
    for (int k = LOG - 1; ~k; k--)
        if (anc[k][r] &&
        !is_anc(u, anc[k][r]) &&
        !is_anc(v, anc[k][r]))
        r = anc[k][r];
    return anc[0][r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, r = 1;
    while (cin >> n){
        if (n == 0) break;
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].eb(v); adj[v].eb(u);
        }
        dfs(1, 0); dep[0] = -1;
        for (int k = 1; k < LOG; k++)
            for (int u = 1; u <= n; u++)
                if (dep[u] >= (1 << k))
                    anc[k][u] =
                    anc[k - 1][anc[k - 1][u]];
        int q; cin >> q;
        char cmd; int u, v;
        while (q--){
            cin >> cmd;
            if (cmd == '!') cin >> r;
            else {
                cin >> u >> v;
                cout << lca(r, u, v) << '\n';
            }
        }  
        for (int i = 1; i <= n; i++){
            adj[i].clear(); dep[i] = 0;
            for (int k = 0; k < LOG; k++){
                anc[k][i] = 0;
            }
        }
        r = 1; tim = 0;
    }
}