#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int N = 100005;
const int MOD = 1000000007;

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int dep[N], par[N], siz[N], ord[N];
bool vis[N];
vector<ii> adj[N], to_add[N], to_sub[N];
vector<int> cp_add[N], cp_sub[N];

struct fenwick {
    int bit[N], n;
    
    void init(int n) {
        fenwick::n = n;
        fill(bit + 1, bit + n + 1, 0);
    }
    
    void add(int i) {
        for (; i <= n; i += i & -i)
            bit[i]++;
    }
    
    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
} fen;

void dfs1(int u) {
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != par[u]) {
            dep[v] = dep[u] + w;
            par[v] = u; dfs1(v);
        }
    }
}

int find_cen(int u) {
    int c = u, p = 0;
    while (true) {
        bool flag = 0;
        for (auto e : adj[c]) {
            int v; tie(v, ignore) = e;
            if (v != p && !vis[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = 1; break;
            }
        }
        if (!flag) break;
    }
    return c;
}

void dfs2(int u, int p) {
    siz[u] = 1;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            dep[v] = dep[u] + w;
            dfs2(v, u);
            siz[u] += siz[v];
        }
    }
}

void dfs3(int u, int p, int x, int y) {
    to_add[x].emplace_back(u, dep[u]);
    to_sub[y].emplace_back(u, dep[u]);
    
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            dep[v] = dep[u] + w;
            dfs3(v, u, x, y);
        }
    }
}

void dfs4(int u) {
    dfs2(u, 0); vis[u = find_cen(u)] = 1;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (!vis[v]) {
            dep[v] = w;
            dfs3(v, u, u, u == par[v] ? v : u);
        }
    }
    to_add[u].emplace_back(u, 0);    
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (!vis[v]) dfs4(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs1(1);
    iota(ord + 1, ord + n + 1, 1);
    sort(ord + 1, ord + n + 1, [&](int x, int y) {
        return dep[x] < dep[y];
    });
    dfs4(1);
    for (int u = 1; u <= n; u++) {
        sort(to_add[u].begin(), to_add[u].end(), 
        [&](ii x, ii y) {
            return ord[x.first] < ord[y.first];
        });
        sort(to_sub[u].begin(), to_sub[u].end(), 
        [&](ii x, ii y) {
            return ord[x.first] < ord[y.first];
        });
        for (auto pp : to_add[u])
            cp_add[u].push_back(pp.second);
        for (auto pp : to_sub[u])
            cp_sub[u].push_back(pp.second);
        sort(cp_add[u].begin(), cp_add[u].end());
        sort(cp_sub[u].begin(), cp_sub[u].end());
    }
    while (q--) {
        int d, k; cin >> d >> k;
        memset(dep, 0, sizeof dep);
        for (int u = 1; u <= n; u++) {
            fen.init(to_add[u].size());
            for (auto e : to_add[u]) {
                int v, w; tie(v, w) = e;
                dep[v] += fen.get(upper_bound(cp_add[u].begin(),
                cp_add[u].end(), d - w) - cp_add[u].begin());
                fen.add(upper_bound(cp_add[u].begin(),
                cp_add[u].end(), w) - cp_add[u].begin());
            }
            fen.init(to_sub[u].size());
            for (auto e : to_sub[u]) {
                int v, w; tie(v, w) = e;
                dep[v] -= fen.get(upper_bound(cp_sub[u].begin(),
                cp_sub[u].end(), d - w) - cp_sub[u].begin());
                fen.add(upper_bound(cp_sub[u].begin(),
                cp_sub[u].end(), w) - cp_sub[u].begin());
            }
        }
        int res = 1;
        for (int u = 1; u <= n; u++)
            res = mul(res, max(0, k - dep[u]));
        cout << res << '\n';
    }
}