//https://www.hackerrank.com/contests/epiccode/challenges/epic-tree
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int MOD = 10009;
const int N = 1e5 + 5;

void madd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

vector <int> adj[N];
int hd[N], in[N], out[N];
int dep[N], par[N], tim, ver[N];
int sz[N], ssz[N];
int tr1[4 * N], tr2[4 * N];
int tg1[4 * N], tg2[4 * N];

int ls(int i) {
    return i * 2;
}

int rs(int i) {
    return i * 2 + 1;
}
 
int dfs_init(int u) {
    int u_sz = 1, maxv_sz = 0, v_sz;
    for (int &v : adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        u_sz += v_sz = dfs_init(v);
        if (u_sz >= MOD) u_sz -= MOD;
        if (v_sz > maxv_sz) {
            maxv_sz = v_sz;
            swap(v, adj[u][0]);
        }
    }
    return sz[u] = u_sz;
}

void dfs_hld(int u) {
    in[u] = ++tim;
    ssz[tim] = ssz[tim - 1] + sz[u];
    if (ssz[tim] >= MOD) ssz[tim] -= MOD;
    if (par[u] && u == adj[par[u]][0])
        hd[u] = hd[par[u]];
    else hd[u] = u;
    for (int v : adj[u])
        if (v != par[u]) dfs_hld(v);
    out[u] = tim;
}

void push_tag1(int i, int l, int r, int v) {
    tr1[i] += (ssz[r] - ssz[l - 1]) * v;
    if ((tr1[i] %= MOD) < 0) tr1[i] += MOD;
    if ((tg1[i] += v) >= MOD) tg1[i] -= MOD;
}

void update1(int i, int l, int r,
            int lo, int hi, int v) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi)
        return void(push_tag1(i, l, r, v));
    int m = (l + r) / 2;
    push_tag1(ls(i), l, m, tg1[i]);
    push_tag1(rs(i), m + 1, r, tg1[i]);
    tg1[i] = 0;
    update1(ls(i), l, m, lo, hi, v);
    update1(rs(i), m + 1, r, lo, hi, v);
    tr1[i] = tr1[ls(i)] + tr1[rs(i)];
    if (tr1[i] >= MOD) tr1[i] -= MOD;
}

int query1(int i, int l, int r,
            int lo, int hi) {
    if (l > hi || r < lo) return 0;
    if (l >= lo && r <= hi) return tr1[i];
    int m = (l + r) / 2;
    push_tag1(ls(i), l, m, tg1[i]);
    push_tag1(rs(i), m + 1, r, tg1[i]);
    tg1[i] = 0;
    return (query1(ls(i), l, m, lo, hi) +
    query1(rs(i), m + 1, r, lo, hi)) % MOD;
}

void push_tag2(int i, int l, int r, int v) {
    (tr2[i] += (r - l + 1) * v) %= MOD;
    if ((tg2[i] += v) >= MOD) tg2[i] -= MOD;
}

void update2(int i, int l, int r,
            int lo, int hi, int v) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi)
        return void(push_tag2(i, l, r, v));
    int m = (l + r) / 2;
    push_tag2(ls(i), l, m, tg2[i]);
    push_tag2(rs(i), m + 1, r, tg2[i]);
    tg2[i] = 0;
    update2(ls(i), l, m, lo, hi, v);
    update2(rs(i), m + 1, r, lo, hi, v);
    tr2[i] = tr2[ls(i)] + tr2[rs(i)];
    if (tr2[i] >= MOD) tr2[i] -= MOD;
}

int query2(int i, int l, int r,
            int lo, int hi) {
    if (l > hi || r < lo) return 0;
    if (l >= lo && r <= hi) return tr2[i];
    int m = (l + r) / 2;
    push_tag2(ls(i), l, m, tg2[i]);
    push_tag2(rs(i), m + 1, r, tg2[i]);
    tg2[i] = 0;
    return (query2(ls(i), l, m, lo, hi) +
    query2(rs(i), m + 1, r, lo, hi)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs_init(1); dfs_hld(1);
    int q; cin >> q;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int u, v, t; cin >> u >> v >> t;
            while (hd[u] != hd[v]) {
                if (dep[hd[u]] < dep[hd[v]])
                    swap(u, v);
                update1(1, 1, n, in[hd[u]], in[u], t);
                update2(1, 1, n, in[hd[u]], in[u], t);
                u = par[hd[u]];
            }
            if (dep[u] < dep[v]) swap(u, v);
            update1(1, 1, n, in[v], in[u], t);
            update2(1, 1, n, in[v], in[u], t);
        }
        else {
            int u, p, s = 0; cin >> u; p = par[u];
            while (p) {
                s += query2(1, 1, n, in[hd[p]], in[p]);
                if (s >= MOD) s -= MOD; p = par[hd[p]];
            }
            int res = s * sz[u] % MOD;
            res += query1(1, 1, n, in[u], out[u]);
            if (res >= MOD) res -= MOD;
            cout << res << '\n';
        }
    }
}