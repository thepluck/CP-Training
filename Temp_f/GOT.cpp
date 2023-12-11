#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
 
template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}
 
struct segtree{
    static const int ninf = 0xc0c0c0c0;
    static const int N = 2e5 + 5;
    int tree[N * 4], lazy[N * 4], n;
 
    segtree(){}
 
    segtree(int n): n(n){
        fill_n(tree + 1, 4 * n, ninf);
        fill_n(lazy + 1, 4 * n, 0);
    }
 
    void init(int n){
        this->n = n;
        fill_n(tree + 1, 4 * n, ninf);
        fill_n(lazy + 1, 4 * n, 0);
    }
 
    void lazy_down(int i, int lo, int hi){
        if (!lazy[i]) return;
        tree[i] += lazy[i];
        if (lo != hi){
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
 
    void update(int i, int lo, int hi,
                int l, int r, int val){
        lazy_down(i, lo, hi);
        if (l > hi || r < lo) return;
        if (l <= lo && r >= hi){
            tree[i] += val;
            if (lo != hi){
                lazy[i * 2] += val;
                lazy[i * 2 + 1] += val;
            }
            return;
        }
        int mi = (lo + hi) / 2;
        update(i * 2, lo, mi, l, r, val);
        update(i * 2 + 1, mi + 1, hi, l, r, val);
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
 
    void update(int i, int lo,
                int hi, int p, int val){
        lazy_down(i, lo, hi);
        if (lo > p || hi < p) return;
        if (lo == hi){
            tree[i] = val; return;
        }
        int mi = (lo + hi) / 2;
        update(i * 2, lo, mi, p, val);
        update(i * 2 + 1, mi + 1, hi, p, val);
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
 
    int query(int i, int lo, int hi, int l, int r){
        lazy_down(i, lo, hi);
        if (l > hi || r < lo) return ninf;
        if (l <= lo && r >= hi) return tree[i];
        int mi = (lo + hi) / 2;
        return max(query(i * 2, lo, mi, l, r),
            query(i * 2 + 1, mi + 1, hi, l, r));
    }
 
    void update(int l, int r, int val){
        update(1, 1, n, l, r, val);
    }
 
    void update(int p, int val){
        update(1, 1, n, p, val);
    }
 
    int query(int l, int r){
        return query(1, 1, n, l, r);
    }
};
 
struct quest{
    int u, v, w, id;
};
 
const int ninf = 0xc0c0c0c0;
const int N = 2e5 + 5;
vector <int> adj[N];
int head[N], in[N], out[N];
int dep[N], par[N], tim;
segtree st; quest que[2 * N];
bitset <N> ans;
 
int dfs_init(int u){
    int u_sz = 1, maxc_sz = 0, c_sz;
    for (int &v : adj[u])
        if (v != par[u]){
            par[v] = u;
            dep[v] = dep[u] + 1;
            u_sz += c_sz = dfs_init(v);
            if (c_sz > maxc_sz){
                maxc_sz = c_sz;
                swap(v, adj[u][0]);
            }
        }
    return u_sz;
}
 
void dfs_hld(int u){
    in[u] = ++tim;
    if (par[u] && u == adj[par[u]][0])
        head[u] = head[par[u]];
    else head[u] = u;
    for (int v : adj[u])
        if (v != par[u]) dfs_hld(v);
    out[u] = tim;
}
 
int query(int u, int v){
    int res = ninf;
    while (head[u] != head[v]){
        if (dep[head[u]] > dep[head[v]]){
            chkmax(res, st.query(in[head[u]], in[u]));
            u = par[head[u]];
        }
        else {
            chkmax(res, st.query(in[head[v]], in[v]));
            v = par[head[v]];
        }
    }
    if (dep[u] > dep[v])
        chkmax(res, st.query(in[v], in[u]));
    else chkmax(res, st.query(in[u], in[v]));
    return res;
}
 
void update(int u, int val){
    st.update(in[u], val);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    while (cin >> n >> q){
        st.init(n);
        for (int i = 1; i <= n; i++){
            cin >> que[i].w;
            que[i].id = -1; que[i].u = i;
        }
        for (int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            adj[u].eb(v); adj[v].eb(u);
        }
        for (int i = n + 1; i <= n + q; i++){
            cin >> que[i].u >> que[i].v >> que[i].w;
            que[i].id = i - n;
        }
        sort(que + 1, que + n + q + 1,
        [&](quest &x, quest & y){
            if (x.w != y.w) return x.w < y.w;
            return x.id < y.id;
        });
        dfs_init(1); dfs_hld(1);
        for (int i = 1; i <= n + q; i++){
            if (~que[i].id)
                ans[que[i].id] =
                query(que[i].u, que[i].v) == que[i].w;
            else update(que[i].u, que[i].w);
        }
        for (int i = 1; i <= q; i++)
            if (ans[i]) cout << "Find\n";
            else cout << "NotFind\n";
        cout << '\n';
    }
} 
