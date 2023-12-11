#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ub upper_bound

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
    }

    segtree(int n): n(n){
        memset(tree, 0, sizeof tree);
    }

    void init(int n){
        this->n = n;
        memset(tree, 0, sizeof tree);
    }

    void update(int i, int lo, int hi,
                int p, int val){
        if (lo == hi){
            tree[i] = val; return;
        }
        int mi = (lo + hi) / 2;
        if (mi >= p) update(i * 2, lo, mi, p, val);
        else update(i * 2 + 1, mi + 1, hi, p, val);
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }

    int query(int i, int lo, int hi, int l, int r){
        if (l > hi || r < lo) return ninf;
        if (l <= lo && r >= hi) return tree[i];
        int mi = (lo + hi) / 2;
        return max(query(i * 2, lo, mi, l, r),
            query(i * 2 + 1, mi + 1, hi, l, r));
    }

    int query(int l, int r){
        return query(1, 1, n, l, r);
    }
} st[2];

const int N = 1e5 + 5;
int w[N], hv[N], dp[N][2];
int in[N], out[N], ver[N], tim;
vector <int> adj[N];

void dfs_init(int v, int p){
    adj[v].erase(find(all(adj[v]), p));
    for (int c : adj[v]) dfs_init(c, v);
}

int dfs_hv(int v){
    in[v] = ++tim; ver[tim] = v;
    int c_sz, maxc_sz = 0, v_sz = 1;
    for (int c : adj[v]){
        v_sz += c_sz = dfs_hv(c);
        if (c_sz > maxc_sz){
            maxc_sz = c_sz; hv[v] = c;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v){
    
}

int main(){
    st[0].init(N); st[1].init(N);
}