#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
using ii = pair <int, int>;

const int N = 1e5 + 5;
vector <ii> adj[N];
ii dp[N]; int res = 0;

void dfs(int u, int p){
    for (auto cc : adj[u])
        if (cc.fi != p){
            dfs(cc.fi, u);
            if (dp[cc.fi].fi + cc.se >= dp[u].fi){
                dp[u].se = dp[u].fi;
                dp[u].fi = dp[cc.fi].fi + cc.se;
            }
            else dp[u].se = max(dp[u].se,
                dp[cc.fi].fi + cc.se);
        }
    res = max(res, dp[u].fi + dp[u].se);
}

int main(){
    freopen("radistree2.inp", "r", stdin);
    freopen("radistree2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; int u, v, w;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    dfs(1, 0); cout << res << '\n';
}