#include <bits/stdc++.h>
using namespace std;

const short N = 3005;
short dp[N][N], deg[N], sz[N], ans[N];
vector <short> adj[N];
void dfs(short u, short p){
    dp[u][1] = deg[u]; dp[u][0] = 0; sz[u] = 1;
    for (short v : adj[u]) if (v != p){
        dfs(v, u);
        for (short j = sz[u] + sz[v]; j > 0; j--)
            for (short k = min(short(j - 1), sz[u]); k > 0 && j - k <= sz[v]; k--)
                dp[u][j] = min(dp[u][j], short(dp[u][k] + dp[v][j - k] - 2));
        sz[u] += sz[v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    short n; cin >> n;
    for (short i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    memset(dp, 0x3f, sizeof dp);
    memset(ans, 0x3f, sizeof ans);
    dfs(1, 0); short q; cin >> q;
    for (short i = 1; i <= n; i++)
        for (short j = 1; j <= n; j++)
            ans[j] = min(ans[j], dp[i][j]);
    while (q--){
        short k; cin >> k;
        if (k > n) cout << "-1\n";
        else cout << ans[k] << '\n';   
    }
}