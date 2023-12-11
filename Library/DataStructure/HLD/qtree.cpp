#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
const int N = 1e4 + 5;
const int ninf = 0xc0c0c0c0;

struct edge{
    int u, v, w;
};

struct segtree{
    struct node{
        int l, r, ma;
    } s[N << 2];
    
    void build(int i, int l, int r){
        s[i] = {l, r, 0};
        if (l == r) return; int m = (l + r) >> 1;
        build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    }

    void init(int n){
        build(1, 1, n);
    }

    void update(int i, int p, int v){
        if (s[i].l > p || s[i].r < p) return;
        if (s[i].l == s[i].r){
            s[i].ma = v; return;
        }
        update(i << 1, p, v); update(i << 1 | 1, p, v);
        s[i].ma = max(s[i << 1].ma, s[i << 1 | 1].ma);
    }

    int query(int i, int l, int r){
        if (s[i].l > r || s[i].r < l) return ninf;
        if (s[i].l >= l && s[i].r <= r) return s[i].ma;
        return max(query(i << 1, l, r), query(i << 1 | 1, l, r));
    }
};

struct hld{
    int heavy[N], pos[N], head[N], par[N], dep[N], tim;
    segtree st; vector <int> adj[N]; edge edges[N];

    void add_edge(int u, int v){
        adj[u].push_back(v); adj[v].push_back(u);
    }

    int dfs_tour(int v){
        int v_sz = 1, maxc_sz = 0;
        for (int c : adj[v]) if (c != par[v]){
            par[c] = v; dep[c] = dep[v] + 1;
            int c_sz = dfs_tour(c); v_sz += c_sz;
            if (c_sz > maxc_sz){
                maxc_sz = c_sz; heavy[v] = c;
            }
        }
        return v_sz;
    }

    void dfs_hld(int v, int h){
        head[v] = h; pos[v] = ++tim;
        if (heavy[v]) dfs_hld(heavy[v], h);
        for (int c : adj[v]) 
            if (c != par[v] && c != heavy[v])
                dfs_hld(c, c);
    }

    void init(){
        int n; cin >> n; st.init(n); tim = 0;
        for (int i = 1; i <= n; i++){
            par[i] = head[i] = dep[i] = pos[i] = heavy[i] = 0;
            adj[i].clear();
        }
        for (int i = 1, u, v, w; i < n; i++){
            cin >> u >> v >> w; add_edge(u, v); edges[i] = {u, v, w};
        }
        dfs_tour(1); dfs_hld(1, 1);
        for (int i = 1; i < n; i++){
            if (par[edges[i].u] == edges[i].v) 
                swap(edges[i].u, edges[i].v);
            st.update(1, pos[edges[i].v], edges[i].w);
        }
    }

    void update(int i, int v){
        edges[i].w = v; st.update(1, pos[edges[i].v], edges[i].w);
    }

    int query(int u, int v){
        int res = ninf;
        while (head[u] != head[v]){
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            res = max(res, st.query(1, pos[head[v]], pos[v]));
            v = par[head[v]];
        }
        if (u == v) return res;
        if (dep[u] > dep[v]) swap(u, v);
        res = max(res, st.query(1, pos[u] + 1, pos[v]));
        return res;
    }
} g;

void solve(){
    g.init(); string cmd; int u, v;
    while (cin >> cmd){
        if (cmd[0] == 'D') return;
        if (cmd[0] == 'Q'){
            cin >> u >> v; cout << g.query(u, v) << '\n';
        }
        if (cmd[0] == 'C'){
            cin >> u >> v; g.update(u, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}