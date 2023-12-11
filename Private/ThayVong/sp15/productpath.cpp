#include<bits/stdc++.h>
using namespace std;

const int maxn = 3005;
int n, x, y, res = 0;
vector <int> adj[maxn];
vector <int> child[maxn];

bool vis[maxn];

int h[maxn], dp[maxn], len[maxn], len2[maxn];

void init(int v){
    vis[v] = true;
    for(int i = 0; i < adj[v].size(); ++i){
        int u = adj[v][i];
        if (vis[u]) continue;
        child[v].push_back(u);
        h[u] = h[v] + 1; init(u);
    }
}

void cal(int v){
    dp[v] = 1;
    for(int i = 0; i < child[v].size(); ++i){
        int u = child[v][i]; cal(u);
        len[v] = max(len[v], dp[v] + dp[u]);
        dp[v] = max(dp[v], dp[u] + 1);
    }

}

void dfs(int v, int exc)
{
    dp[v] = 1;
    for(int i = 0; i < child[v].size(); ++i){
        int u = child[v][i];
        if (u == exc) continue;
        dfs(u, exc);
        len2[v] = max(len2[v], dp[v] + dp[u]);
        dp[v] = max(dp[v], dp[u] + 1);
    }
    res = max(res, (len[exc] - 1) * (len2[v] - 1));
}

int main(){
    freopen("productpath.inp", "r", stdin);
    freopen("productpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(1); cal(1);
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            dp[j] = 0; len2[j] = 1;
        }
        dfs(1, i);
    }
    cout << res << '\n';
}