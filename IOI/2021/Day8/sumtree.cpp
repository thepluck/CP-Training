#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;

struct fenwick_tree {
    vector <pair <int, ll>> sum; int N;
 
    fenwick_tree(int N): N(N), sum(N + 1) {}
 
    void add(int i, int v1, ll v2) {
        for (; i <= N; i += i & -i) {
            sum[i].first += v1;
            sum[i].second += v2;
        }
    }
 
    void get(int i, int &v1, ll &v2) {
        for (; i > 0; i -= i & -i) {
            v1 += sum[i].first;
            v2 += sum[i].second;
        }
    }
};
 
const int MOD = 1000000007;
const int MAXN = 500005;
 
int fac[MAXN], inv[MAXN], num[MAXN], zero = 0;
int tin[MAXN], tout[MAXN], bel[MAXN], timer;
vector <int> adj[MAXN]; ll tag[MAXN];
 
struct segment_tree {
#define il i * 2
#define ir i * 2 + 1
    vector <int> val; int N;
 
    void build(int i, int l, int r) {
        if (l == r) val[i] = -tout[bel[l]];
        else {
            int m = (l + r) / 2;
            build(il, l, m);
            build(ir, m + 1, r);
            val[i] = max(val[il], val[ir]);
        }
    }
 
    segment_tree(int N): N(N), val(N * 4) {
        build(1, 1, N);
    }
 
    void toggle(int i, int l, int r, int p) {
        if (l == r) val[i] = -val[i];
        else {
            int m = (l + r) / 2;
            if (m >= p) toggle(il, l, m, p);
            else toggle(ir, m + 1, r, p);
            val[i] = max(val[il], val[ir]);
        }
    }
 
    int search(int i, int l, int r, int p) {
        if (l >= p || val[i] < p) return -1;
         
        if (l == r) return l;
        int m = (l + r) / 2;
        int res = search(ir, m + 1, r, p);
        if (res >= 0) return res;
        return search(il, l, m, p);
    }
 
    void toggle(int p) {
        toggle(1, 1, N, p);
    }
     
    int search(int p) {
        return search(1, 1, N, p);
    }
};
 
int Add(int x, int y) {
    return x - ((x += y) >= MOD ? MOD : 0);
}
 
int Sub(int x, int y) {
    return x + ((x -= y) < 0 ? MOD : 0);
}
 
int Mul(int x, int y) {
    return (ll)x * y % MOD;
}
 
int Pow(int x, int k) {
    int res = 1;
    for (; k; k >>= 1, x = Mul(x, x))
        if (k & 1) res = Mul(res, x);
    return res;
}
 
int Div(int x, int y) {
    return Mul(x, Pow(y, MOD - 2));
}
 
int getC(ll n, ll k, int v) {
    if (n < k) {
        zero += v; return 1;
    }
    return Mul(fac[n], Mul(inv[k], inv[n - k]));
}
 
void DFS(int u, int p) {
    bel[tin[u] = ++timer] = u;
    num[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            DFS(v, u); num[u] += num[v];
        }
    tout[u] = timer;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N >> tag[1];
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
        inv[i] = MOD - Mul(inv[MOD % i], MOD / i);
    for (int i = 1; i < MAXN; i++) {
        fac[i] = Mul(fac[i - 1], i);
        inv[i] = Mul(inv[i], inv[i - 1]);
    }
    fenwick_tree fen(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    segment_tree seg(N);
    seg.toggle(1);
    int res = getC(N + tag[1] - 1, N - 1, 1);
    int Q; cin >> Q;
    fen.add(1, N, tag[1]);
    int siz_u, siz_p;
    ll sum_u, sum_p;
    cout << res << '\n';
    while (Q--) {
        int cmd; cin >> cmd;
        siz_u = sum_u = siz_p = sum_p = 0;
        if (cmd == 1) {
            int u, p; cin >> u >> tag[u];
            p = bel[seg.search(tin[u])];
            fen.get(tout[p], siz_p, sum_p);
            siz_p = num[p] - siz_p;
            sum_p = tag[p] - sum_p;
            fen.get(tin[p], siz_p, sum_p);
            res = Div(res, getC(sum_p + siz_p - 1, siz_p - 1, -1));
            fen.get(tout[u], siz_u, sum_u);
            siz_u = num[u] - siz_u;
            sum_u = tag[u] - sum_u;
            fen.get(tin[u], siz_u, sum_u);
            res = Mul(res, getC(sum_u + siz_u - 1, siz_u - 1, 1));
            siz_p -= siz_u; sum_p -= sum_u;
            res = Mul(res, getC(sum_p + siz_p - 1, siz_p - 1, 1));
            fen.add(tin[p], -siz_u, -sum_u);
            fen.add(tin[u], siz_u, sum_u);
            seg.toggle(tin[u]);
        } else {
            int u, p; cin >> u;
            p = bel[seg.search(tin[u])];
            fen.get(tout[p], siz_p, sum_p);
            siz_p = num[p] - siz_p;
            sum_p = tag[p] - sum_p;
            fen.get(tin[p], siz_p, sum_p);
            res = Div(res, getC(sum_p + siz_p - 1, siz_p - 1, -1));
            fen.get(tout[u], siz_u, sum_u);
            siz_u = num[u] - siz_u;
            sum_u = tag[u] - sum_u;
            fen.get(tin[u], siz_u, sum_u);
            res = Div(res, getC(sum_u + siz_u - 1, siz_u - 1, -1));
            siz_p += siz_u; sum_p += sum_u;
            res = Mul(res, getC(sum_p + siz_p - 1, siz_p - 1, 1));
            fen.add(tin[p], siz_u, sum_u);
            fen.add(tin[u], -siz_u, -sum_u);
            seg.toggle(tin[u]);
        }
        cout << (zero ? 0 : res) << '\n';
    }
}