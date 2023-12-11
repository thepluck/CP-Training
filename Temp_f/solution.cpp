/*#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ub upper_bound
#define lb lower_bound

const int N = 1e3 + 5;
int w[N], d[N], n, res;
vector <int> adj[N];

void dfs_sol(int u, int p){
    int k = lb(d + 1, d + n + 1, w[u]) - d;
    res = max(res, k); swap(d[k], w[u]);
    for (int v : adj[u])
        if (v != p) dfs_sol(v, u);
    swap(d[k], w[u]);
}

int main(){
    freopen("TREELIS.inp", "r", stdin);
    freopen("TREELIS.ans", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; cin >> w[i++]);
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; i++){
        memset(d, 0x3f, sizeof d);
        dfs_sol(i, 0);
    }
    cout << res << '\n';
}*/
#include <bits/stdc++.h>
using namespace std;

const int W = 10010;
bitset <W> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("KNAPSACK.inp", "r", stdin);
    freopen("KNAPSACK.ans", "w", stdout);
    int n, q; cin >> n >> q; dp[0] = 1;
    for (int i = 1, x; i <= n; i++){
        cin >> x; dp |= dp << x;
    }
    for (int i = 1, x; i <= q; i++){
        cin >> x;
        cout << (dp[x] ? "YES\n" : "NO\n");
    }
}