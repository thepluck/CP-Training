#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;
const int N = 1e5 + 5;
int heavy[N], tour[N], in[N], out[N], tim, n, q, ans[N];
int lo[N * 4], hi[N * 4], val[N * 4], col[N], cnt[N];
vector <ii> que[N]; vector <int> adj[N];

void add_edge(int u, int v){
    adj[u].push_back(v); adj[v].push_back(u);
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r) return; int m = (l + r) / 2;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
}

void update(int i, int p, int t){
    if (lo[i] > p || hi[i] < p) return;
    if (lo[i] == hi[i]){
        val[i] += t;
        if (val[i] < 0) val[i] = 0; return;
    }
    update(i << 1, p, t); update(i << 1 | 1, p, t);
    val[i] = val[i << 1] + val[i << 1 | 1];
}

int query(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return val[i];
    return query(i << 1, l, r) + query(i << 1 | 1, l, r);
}

void modify(int v, int t){
    update(1, cnt[col[v]], -1);
    cnt[col[v]] += t;
    update(1, cnt[col[v]], 1);
}

int dfs_tour(int v, int p){
    int cur_sz = 1, maxc_sz = 0;
    in[v] = ++tim; tour[tim] = v;
    for (int c : adj[v]) if (c != p){
        int c_sz = dfs_tour(c, v); cur_sz += c_sz;
        if (maxc_sz < c_sz){
            heavy[v] = c; maxc_sz = c_sz;
        }
    }
    out[v] = tim; return cur_sz;
}

void dfs_sol(int v, int p, bool keep){
    for (int c : adj[v])
        if (c != p && c != heavy[v])
            dfs_sol(c, v, false);
    if (heavy[v]) dfs_sol(heavy[v], v, true);
    for (int c : adj[v])
        if (c != p && c != heavy[v])
            for (int u = in[c]; u <= out[c]; u++)
                modify(tour[u], 1);
    modify(v, 1);
    for (auto qq : que[v])
        ans[qq.fi] = query(1, qq.se, n);
    if (!keep)
        for (int u = in[v]; u <= out[v]; u++)
            modify(tour[u], -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q; build(1, 1, n);
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; add_edge(u, v);
    }
    for (int i = 1, v, k; i <= q; i++){
        cin >> v >> k; que[v].push_back({i, k});
    }
    dfs_tour(1, 0); dfs_sol(1, 0, 1);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}
