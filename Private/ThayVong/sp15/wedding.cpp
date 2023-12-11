#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

const int N = 3e5 + 5;
bitset <N> used;
vector <int> path, adj[N];
int par[N], dp[N], dep[N], a, b;

void dfs_init(int u){
    adj[u].erase(find(all(adj[u]), par[u]));
    for (int v : adj[u]){
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs_init(v);
    }
}

void dfs_dp(int u){
    for (int v : adj[u]){
        dfs_dp(v);
        if (!used[v]) dp[u] = max(dp[u], dp[v] + 1);
    }
}

int main(){
    freopen("wedding.inp", "r", stdin);
    freopen("wedding.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> a >> b; adj[a].push_back(0); dfs_init(a);
    while (b != a){
        path.push_back(b);
        used[b] = 1; b = par[b];
    }
    path.push_back(a);
    int maxl = 0, res = 0, cnt = 0;
    reverse(all(path));
    dfs_dp(a); b = path.back();
    for (int i = 1; i <= n; i++) dp[i]++;
    for (int x : path){
        res = max(res, min(maxl, dep[b] - dep[x] + dp[x]));
        maxl = max(maxl, cnt + dp[x]); cnt++;
    }
    cout << res << '\n';
}