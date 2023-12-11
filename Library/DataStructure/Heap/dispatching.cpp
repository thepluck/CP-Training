/// another dynamic binary heap
/// :))))))))))))))))))))))))))

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
int sz[N], c[N], ls[N], rs[N], p[N];
ll su[N], lim, res, l[N];
vector <int> adj[N];

void maintain(int x){
    sz[x] = sz[ls[x]] + sz[rs[x]] + 1;
    su[x] = su[ls[x]] + su[rs[x]] + c[x];
}

int merge(int x, int y){
    if (!x || !y) return x | y;
    if (c[x] < c[y]) swap(x, y);
    rs[x] = merge(rs[x], y);
    if (sz[ls[x]] < sz[rs[x]])
        swap(ls[x], rs[x]);
    maintain(x);
    return x;
}

int pop(int x){
    return merge(ls[x], rs[x]);
}

void dfs(int u){
    for (int v : adj[u]){
        dfs(v);
        p[u] = merge(p[u], p[v]);
    }
    while (p[u] && su[p[u]] > lim)
        p[u] = pop(p[u]);
    res = max(res, l[u] * sz[p[u]]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, root = 0; cin >> n >> lim;
    for (int i = 1, p; i <= n; i++){
        cin >> p >> c[i] >> l[i];
        if (p == 0) root = i;
        else adj[p].push_back(i);
        sz[i] = 1; su[i] = c[i];
    }
    iota(p + 1, p + n + 1, 1);
    dfs(root); cout << res << '\n';
}