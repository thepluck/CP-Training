#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 3e5 + 5;
int bit[N]; long long ans;
vector <int> adj[N];

void update(int i, int v){
    for (; i > 0; i -= i & -i)
        bit[i] += v;
}

int query(int i){
    int res = 0;
    for (; i < N; i += i & -i)
        res += bit[i];
    return res;
}

void dfs(int u, int p){
    ans += query(u);
    update(u, 1);
    for (int v : adj[u])
        if (v != p) dfs(v, u);
    update(u, -1);
}

int main(){
    freopen("treeinv.inp", "r", stdin);
    freopen("treeinv.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> n >> r;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(r, 0); cout << ans << '\n';
}