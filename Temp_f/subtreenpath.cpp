#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

struct segtree{
    static const int ninf = 0xc0c0c0c0;
    static const int N = 1e5 + 5;
    int tree[N * 4], lazy[N * 4], n;

    segtree(){
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }

    segtree(int n): n(n){
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }

    void init(int n){
        this->n = n;
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
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

    int query(int l, int r){
        return query(1, 1, n, l, r);
    }
};

const int ninf = 0xc0c0c0c0;
const int N = 1e5 + 5;
vector <int> adj[N];
int head[N], in[N], out[N];
int dep[N], par[N], tim;
segtree st;

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

void update(int u, int val){
    st.update(in[u], out[u], val);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; st.init(n);
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs_init(1); dfs_hld(1);
    int q; string cmd; cin >> q;
    for (int i = 1, x, y; i <= q; i++){
        cin >> cmd >> x >> y;
        if (cmd[0] == 'a') update(x, y);
        else cout << query(x, y) << '\n';
    }
}