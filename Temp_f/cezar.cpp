#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz
#define eb emplace_back

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

struct fenwick_tree{
    struct node{
        int cnt = 0, sum = 0;

        node(){}
    };

    static const int N = 2e5 + 5;
    node tree[N]; int n;

    fenwick_tree(int n = 0) : n(n){
        memset(tree, 0, sizeof tree);
    }

    void update(int i, int val, int t){
        for (; i <= n; i += i & -i){
            tree[i].cnt += t;
            tree[i].sum += val * t;
        }
    }

    int get_cnt(int i){
        int cnt = 0;
        for (; i > 0; i -= i & -i)
            cnt += tree[i].cnt;
        return cnt;
    }

    int get_sum(int i){
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i].sum;
        return sum;
    }

    int get_kth(int k){
        if (!k) return 0;
        int pos = 0, p = 1 << (31 - clz(n));
        for (; p > 0; p >>= 1){
            pos += p;
            if (pos <= n && k > tree[pos].cnt)
                k -= tree[pos].cnt;
            else pos -= p;
        }
        return pos + 1;
    }
} bit;

const int N = 2e5 + 5;
vector <int> adj[N];
int sz[N], n, k, res = INT_MAX;

void dfs_sz(int u, int p){
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p){
            dfs_sz(v, u); sz[u] += sz[v];
        }
    if (p) bit.update(sz[u], sz[u], 1);
}

int get_cost(){
    int val = bit.get_kth(n - k - 1);
    return bit.get_sum(val) -
    (bit.get_cnt(val) - n + k + 1) * val;
}

void dfs_sol(int u, int p){
    int pre = sz[u];
    if (p){
        sz[u] = n; sz[p] = n - pre;
        bit.update(pre, pre, -1);
        bit.update(sz[p], sz[p], 1);
    }
    chkmin(res, get_cost());
    for (int v : adj[u])
        if (v != p) dfs_sol(v, u);
    if (p){
        bit.update(pre, pre, 1);
        bit.update(sz[p], sz[p], -1);
        sz[u] = pre; sz[p] = n;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k; bit.n = n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs_sz(1, 0); dfs_sol(1, 0);
    cout << res << '\n';
}