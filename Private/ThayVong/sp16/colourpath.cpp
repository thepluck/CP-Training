#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb pop_back
using ll = long long;

const int N = 1e5 + 5;
int n, sz[N], c[N], sub[N], cnt[N], last[N];
vector <int> adj[N];
ll res[N];

void dfs(int u, int p){
    sz[u] = 1; ll tmp = 0;
    int pre = last[c[u]], ssub = 0;
    for (int v : adj[u]){
        if (v == p) continue;
        last[c[u]] = v; dfs(v, u);
        res[c[u]] += tmp * (sz[v] - sub[v]);
        sz[u] += sz[v]; ssub += sub[v];
        tmp += sz[v] - sub[v];
    }
    cnt[c[u]] += sz[u] - ssub;
    res[c[u]] += 1ll * (sz[u] - ssub) *
                (n - cnt[c[u]] + 1);
    sub[pre] += sz[u]; last[c[u]] = pre;
}

int main(){
    freopen("colourpath.inp", "r", stdin);
    freopen("colourpath.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; cin >> c[i++]);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}