#include <bits/stdc++.h>
using namespace std;

#define ub upper_bound
#define eb emplace_back

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int c[N], d[N], n, res, lim;
vector <int> adj[N];

void dfs(int u, int p){
    int k;
    if (c[u] >= lim){
        k = ub(d + 1, d + n + 1, c[u]) - d;
        swap(d[k], c[u]); res = max(res, k);
    }
    for (int v : adj[u])
        if (v != p) dfs(v, u);
    if (c[u] >= lim) swap(d[k], c[u]);
}

int solve(int u){
    for (int i = 1; i <= n; i++) d[i] = inf;
    lim = c[u]; res = 0; dfs(u, 0); return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> n >> tc;
    for (int i = 1; i <= n; cin >> c[i++]);
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    while (tc--){
        int u; cin >> u;
        cout << solve(u) << '\n';
    }
}