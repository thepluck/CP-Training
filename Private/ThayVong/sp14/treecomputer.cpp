#include <bits/stdc++.h>
using namespace std;

struct segtree{
    static const int ninf = 0xc0c0c0c0;
    static const int N = 2e5 + 5;
    int tree[N * 4]; int n;
 
    segtree(){}
 
    segtree(int n): n(n){
        fill_n(tree + 1, 4 * n, 0);
    }
 
    void init(int n){
        this->n = n;
        fill_n(tree + 1, 4 * n, 0);
    }

    void update(int i, int lo, int hi, int p, int val){
        if (lo > p || hi < p) return;
        if (lo == hi){
            tree[i] = val; return;
        }
        int mi = (lo + hi) / 2;
        update(i * 2, lo, mi, p, val);
        update(i * 2 + 1, mi + 1, hi, p, val);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    int query(int i, int lo, int hi, int l, int r){
        if (l > hi || r < lo) return 0;
        if (l <= lo && r >= hi) return tree[i];
        int mi = (lo + hi) / 2;
        return query(i * 2, lo, mi, l, r) +
            query(i * 2 + 1, mi + 1, hi, l, r);
    }

    void update(int p, int val){
        update(1, 1, n, p, val);
    }

    int query(int l, int r){
        return query(1, 1, n, l, r);
    }
};

const int N = 1e5 + 5;
segtree st; vector <int> adj[N];
int in[N], out[N], tim, a[N];

void dfs(int u, int p){
    in[u] = ++tim;
    for (int v : adj[u])
        if (v != p) dfs(v, u);
    out[u] = tim;
}

int main(){
    freopen("treecomputer.inp", "r", stdin);
    freopen("treecomputer.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); st.init(n);
    for (int i = 1; i <= n; i++)
        st.update(in[i], a[i]);
    for (int i = 1; i <= q; i++){
        int cmd, u, v; cin >> cmd >> u;
        if (cmd == 2) 
            cout << st.query(in[u], out[u]) << '\n';
        else {
            cin >> v; st.update(in[u], v);
        }
    }
}