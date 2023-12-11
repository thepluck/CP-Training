#include "circuit.h"
#include <bits/stdc++.h>

namespace {
    #define il i * 2
    #define ir i * 2 + 1

    using namespace std;

    const int N = 200'000;
    const int MOD = 1'000'002'022;

    vector<int> adj[N];
    int prd[N], ctb[N], sum[N * 4][2], n, m;
    bool flip[N * 4];

    int add(int x, int y) {
        return (x += y) >= MOD ? x - MOD : x;
    }

    int mul(int x, int y) {
        return (long long)x * y % MOD;
    }

    void dfs_prd(int u) {
        prd[u] = max(int(adj[u].size()), 1);
        for (int v : adj[u]) {
            dfs_prd(v);
            prd[u] = mul(prd[u], prd[v]);
        }
    }

    void dfs_ctb(int u) {
        vector<int> pre(adj[u].size() + 1);
        pre[0] = ctb[u]; int suf = 1;
        for (int i = 0; i < adj[u].size(); i++)
            pre[i + 1] = mul(pre[i], prd[adj[u][i]]);
        for (int i = adj[u].size() - 1; i >= 0; i--) {
            ctb[adj[u][i]] = mul(pre[i], suf);
            suf = mul(suf, prd[adj[u][i]]);
            dfs_ctb(adj[u][i]);
        }
    }

    void build(int i, int l, int r, vector<int> &a) {
        if (l == r) {
            if (a[l]) sum[i][0] = ctb[l + n];
            else sum[i][1] = ctb[l + n];
        } else {
        int m = (l + r) / 2;
            build(il, l, m, a);
            build(ir, m + 1, r, a);
            sum[i][0] = add(sum[il][0], sum[ir][0]);
            sum[i][1] = add(sum[il][1], sum[ir][1]);
        }
    }

    void apply(int i) {
        swap(sum[i][0], sum[i][1]); flip[i] ^= 1;
    }

    void push(int i) {
        if (flip[i]) {
            apply(il); apply(ir); flip[i] = 0;
        }
    }

    void update(int i, int l, int r, int x, int y) {
        if (l >= x && r <= y) return apply(i);
        int m = (l + r) / 2; push(i);
        if (m >= x) update(il, l, m, x, y);
        if (m < y) update(ir, m + 1, r, x, y);
        sum[i][0] = add(sum[il][0], sum[ir][0]);
        sum[i][1] = add(sum[il][1], sum[ir][1]);
    }
}

void init(int n, int m, vector<int> p, vector<int> a) {
    for (int i = 1; i < n + m; i++)
        adj[p[i]].push_back(i);
    dfs_prd(0); ctb[0] = 1; dfs_ctb(0);
    ::n = n; ::m = m; build(1, 0, m - 1, a);
}

int count_ways(int l, int r) {
    update(1, 0, m - 1, l - n, r - n);
    return sum[1][0];
}
