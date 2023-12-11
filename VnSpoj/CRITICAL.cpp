#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) (v).begin(), (v).end()

const int N = 2e4 + 5;
int num[N], low[N];
int siz[N], par[N];
int siz_anc[N];
vector <int> adj[N];
bitset <N> used;
int color; ll ans = 0;

int cnt_c(int u){
    used[u] = true; siz[u] = 1;
    for (int v : adj[u])
        if (!used[v]) siz[u] += cnt_c(v);
    return siz[u];
}

void dfs(int u){
    num[u] = low[u] = ++color;
    vector <int> c;
    for (int v : adj[u])
        if (num[v] == 0){
            par[v] = u; siz_anc[v] = siz_anc[u];
            dfs(v); low[u] = min(low[u], low[v]);
            if (low[v] >= num[u])
                c.push_back(siz[v]);
        }
        else if (v != par[u]) 
            low[u] = min(low[u], num[v]);
    if (!c.empty()){
        c.push_back(siz_anc[u] - 1 - accumulate(all(c), 0));
        ans += 1ll * (siz_anc[u] - 1) * (siz_anc[u] - 1);
        for (auto x : c) ans -= 1ll * x * x;
    }
}

int main(){
    int n, m; cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == 0){
            cnt_c(i); siz_anc[i] = siz[i]; dfs(i);
        }
    cout << setprecision(2) << fixed << 1.0 * ans / 2 / n << '\n';
}