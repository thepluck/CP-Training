#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 100;
int in[N], out[N], color, a[N];
int lo[4 * N], hi[4 * N]; ll sum[4 * N];
vector <int> adj[N];

void dfs(int u, int p){
    in[u] = ++color;
    for (int v : adj[u]) if (v != p) dfs(v, u);
    out[u] = color;
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r) return; int m = (l + r) >> 1;
    build(i * 2, l, m); build(i * 2 + 1, m + 1, r);
}

void update(int i, int p, int v){
    if (lo[i] > p || hi[i] < p) return;
    if (lo[i] == hi[i]){
        sum[i] = v; return;
    }
    update(i * 2, p, v); update(i * 2 + 1, p, v);
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

ll query(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return sum[i];
    return query(i * 2, l, r) + query(i * 2 + 1, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, u, v, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        cin >> u >> v; 
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0); build(1, 1, n); int cmd;
    for (int i = 1; i <= n; i++) update(1, in[i], a[i]);
    while (q--){
        cin >> cmd >> u;
        if (cmd == 1){
           cin >> v; update(1, in[u], v);
        }
        else cout << query(1, in[u], out[u]) << '\n';
    }
}