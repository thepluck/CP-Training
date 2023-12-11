/// dynamic binary heap
/// rank[lson] >= rank[rson]
/// height of rson is at most logn
/// merge 2 heaps in O(logn)
/// easily to maintain lazy tags

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 5;
int rnk[N], ls[N], rs[N], p[N];
int ans[N], a[N], v[N], st[N];
int dep[N], sac[N], cap[N];
ll val[N], mul[N], add[N], d[N];
vector <int> adj[N];

void do_add(int x, ll ad){
    val[x] += ad; add[x] += ad;
}

void do_mul(int x, ll mu){
    val[x] *= mu; mul[x] *= mu;
    add[x] *= mu;
}

void push_down(int x){
    do_mul(ls[x], mul[x]);
    do_mul(rs[x], mul[x]);
    do_add(ls[x], add[x]);
    do_add(rs[x], add[x]);
    add[x] = 0; mul[x] = 1;
}

int merge(int x, int y){
    push_down(x); push_down(y);
    if (!x || !y) return x | y;
    if (val[x] > val[y]) swap(x, y);
    rs[x] = merge(rs[x], y);
    if (rnk[ls[x]] < rnk[rs[x]])
        swap(ls[x], rs[x]);
    rnk[x] = rnk[rs[x]] + 1;
    return x;
}

int pop(int x){
    push_down(x);
    return merge(ls[x], rs[x]);
}

void dfs(int u){
    for (int v : adj[u]){
        dep[v] = dep[u]+ 1; dfs(v);
        p[u] = merge(p[u], p[v]);
    }
    while (p[u] && val[p[u]] < d[u]){
        cap[p[u]] =
            dep[st[p[u]]] - dep[u];
        p[u] = pop(p[u]); sac[u]++;
    }
    if (a[u] == 0) do_add(p[u], v[u]);
    else do_mul(p[u], v[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 2, p; i <= n; i++){
        cin >> p >> a[i] >> v[i];
        adj[p].push_back(i);
    }
    for (int i = 1; i <= m; i++){
        cin >> val[i] >> st[i];
        p[st[i]] = merge(p[st[i]], i);
    }
    dfs(1);
    while (p[1]){
        cap[p[1]] = dep[st[p[1]]] + 1;
        p[1] = pop(p[1]);
    }
    for (int i = 1; i <= n; i++)
        cout << sac[i] << '\n';
    for (int i = 1; i <= m; i++)
        cout << cap[i] << '\n';
    
}