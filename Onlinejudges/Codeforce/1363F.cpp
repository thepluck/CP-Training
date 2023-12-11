#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 2e5 + 5;
int rem[N][2], a[N], b[N], c[N];
long long cost;
vector <int> adj[N];

void dfs(int u, int p){
    if (b[u] != c[u]) rem[u][b[u]]++;
    for (int v : adj[u]) if (v != p){
        chkmin(a[v], a[u]); dfs(v, u);
        rem[u][0] += rem[v][0];
        rem[u][1] += rem[v][1];
    }
    int can = min(rem[u][0], rem[u][1]);
    rem[u][0] -= can; rem[u][1] -= can;
    cost += 2ll * can * a[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0);
    if (rem[1][0] || rem[1][1])
        cout << "-1\n";
    else cout << cost << '\n';
}