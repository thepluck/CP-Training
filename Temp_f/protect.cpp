#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

#define eb emplace_back
using ll = long long;

const int N = 1e3 + 5;
vector <int> adj[N];
int dp[N][3];

void dfs(int u, int p){
    dp[u][0] = 1; dp[u][1] = 1005; int tmp = 0;
    for (int v : adj[u]) if (v != p){
        dfs(v, u);
        dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]});
        dp[u][2] += dp[v][1];
        dp[u][1] = min(dp[u][1] + min(dp[v][0], dp[v][1]),
                        tmp + dp[v][0]);
        tmp += min(dp[v][0], dp[v][1]);
    }
}

int main(){
    freopen("protect.inp", "r", stdin);
    freopen("protect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][1]) << '\n';
}