#include <bits/stdc++.h>
using namespace std;

struct segtree{
    vector <int> seg, lo, hi;
    static const int ninf = 0xc0c0c0c0;
    void build(int i, int l, int r){
        lo[i] = l; hi[i] = r;
        if (l == r) return; int m = (l + r) / 2;
        build(i * 2, l, m); build(i * 2 + 1, m + 1, r);
    }
    void init(int n){
        seg.resize(4 * (n + 1)); lo.resize(4 * (n + 1));
        hi.resize(4 * (n + 1)); build(1, 1, n);
    }
    void update(int i, int p, int v){
        if (lo[i] > p || hi[i] < p) return;
        if (lo[i] == hi[i]){
            seg[i] = v; return;
        }
        update(i * 2, p, v); update(i * 2 + 1, p, v);
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
    }
    int query(int i, int l, int r){
        if (lo[i] > r || hi[i] < l) return ninf;
        if (lo[i] >= l && hi[i] <= r) return seg[i];
        return max(query(i * 2, l, r), query(i * 2 + 1, l, r));
    }
};

using iii = tuple <int, int, int>;
const int N = 200005; iii edge[N];
int head[N], heavy[N], pos[N], id[N], cnt, dep[N], par[N];
vector <int> adj[N]; segtree st[N]; int sz[N], val[N];


int dfs_tour(int v, int p){
    int cur_sz = 1, maxc_sz = 0; par[v] = p;
    for (int c : adj[v]) if (c != p){
        dep[c] = dep[v] + 1;
        int c_sz = dfs_tour(c, v); cur_sz += c_sz;
        if (maxc_sz < c_sz){
            heavy[v] = c; maxc_sz = c_sz;
        }
    }
    return cur_sz;
}

void dfs_hld(int v, int p, int t){
    if (t == 0) head[++cnt] = v; pos[v] = ++t; id[v] = cnt;
    sz[cnt]++; if (heavy[v]) dfs_hld(heavy[v], v, t);
    for (int c : adj[v]) if (c != p && c != heavy[v])
        dfs_hld(c, v, 0);
}

int lca(int u, int v){
    while (id[u] != id[v]){
        if (dep[head[id[u]]] > dep[head[id[v]]])
            u = par[head[id[u]]];
        else v = par[head[id[v]]];
    }
    if (dep[u] > dep[v]) return v; return u;
}

void solve(){
    int n, u, v, q; cin >> n >> q;
    for (int i = 2; i <= n; i++){
    	cin >> u; 
    	adj[u].push_back(i); adj[i].push_back(u);
    }
    dfs_tour(1, 0); dfs_hld(1, 0, 0);
    while (q--){
    	cin >> u >> v; cout << lca(u, v) << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); solve();
}