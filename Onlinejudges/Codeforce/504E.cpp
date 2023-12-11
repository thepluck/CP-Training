// Problem: E. Misha and LCP on Tree
// Contest: Codeforces - Codeforces Round #285 (Div. 1)
// URL: https://codeforces.com/contest/504/problem/E
// Memory Limit: 512 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000004539;
const int N = 300005;
const int Q = 1000005;
const int LG = 19;
const int B = 911;

struct quest {
    int i, k;
    
    quest(int i, int k): i(i), k(k) {}
};

int tour[N], rmq[LG][N], lg[N];
int n, m, tin[N], timer, par[N];
vector <int> adj[N]; int dep[N];
char str[N]; int Hash[N], pw[N];
tuple <int, int, int, int> que[Q];
int low[Q], high[Q], kth[Q * 2];
vector <quest> qq[N];
vector <int> path;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void dfsPre(int u) {
    tin[u] = timer++; dep[u] = dep[par[u]] + 1;
    Hash[u] = add(mul(Hash[par[u]], B), str[u]);
    for (int v : adj[u]) if (v != par[u]) {
        tour[m] = u; rmq[0][m++] = tin[u];
        par[v] = u; dfsPre(v);
    }
}

void initLCA() {
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = mul(pw[i - 1], B);
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
    for (int k = 1; k < LG; k++)
        for (int i = 0; i + (1 << k) <= m; i++)
            rmq[k][i] = min(rmq[k - 1][i],
            rmq[k - 1][i + (1 << (k - 1))]);
}

int LCA(int u, int v) {
    if (u == v) return u;
    tie(u, v) = minmax(tin[u], tin[v]);
    return tour[min(rmq[lg[v - u]][u],
    rmq[lg[v - u]][v - (1 << lg[v - u])])];
}

int getHash(int u, int v) {
    int r = LCA(u, v);
    return add(mul(sub(Hash[u], mul(Hash[par[r]],
    pw[dep[u] - dep[par[r]]])), pw[dep[v] - dep[r]]),
    sub(Hash[v], mul(Hash[r], pw[dep[v] - dep[r]])));
}

int getDis(int u, int v) {
    int r = LCA(u, v);
    return dep[u] + dep[v] - 2 * dep[r] + 1;
}

void dfsFind(int u) {
    path.emplace_back(u);
    for (auto q : qq[u])
        kth[q.i] = path[dep[u] - q.k];
    for (int v : adj[u])
        if (v != par[u]) dfsFind(v);
    path.pop_back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> (str + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfsPre(1); initLCA();
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        high[i] = min(getDis(a, b), getDis(c, d));
        que[i] = {a, b, c, d};
    }
    while (true) {
        bool flag = false;
        for (int i = 1; i <= n; i++)
            qq[i].clear();
        for (int i = 1; i <= q; i++) {
            if (low[i] == high[i]) continue;
            int mid = (low[i] + high[i] + 1) / 2;
            int a, b, c, d, x, y; flag = 1;
            tie(a, b, c, d) = que[i];
            x = LCA(a, b); y = LCA(c, d);
            if (mid <= dep[a] - dep[x] + 1)
                qq[a].emplace_back(2 * i, mid);
            else qq[b].emplace_back(2 * i,
                getDis(a, b) - mid + 1);
            if (mid <= dep[c] - dep[y] + 1)
                qq[c].emplace_back(2 * i + 1, mid);
                else qq[d].emplace_back(2 * i + 1,
                getDis(c, d) - mid + 1);
        }
        if (!flag) break; dfsFind(1);
        for (int i = 1; i <= q; i++) {
            if (low[i] == high[i]) continue;
            int mid = (low[i] + high[i] + 1) / 2;
            int a, b, c, d, x, y; flag = 1;
            tie(a, b, c, d) = que[i];
            if (getHash(a, kth[2 * i]) ==
            getHash(c, kth[2 * i + 1]))
                low[i] = mid;
            else high[i] = mid - 1;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << low[i] << '\n';
}