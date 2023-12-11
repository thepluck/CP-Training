#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 50005, B = 641;
const int MOD = 1000000009;

char s[N]; bool vis[N];
vector <int> adj[N];
int siz[N], ver[N], n, rev[N];
int sum[N], dep[N], pw[N], mx;
set <int> s1[N], s2[N]; int root;
bool found; int len, res = 1;

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

int getHash(int u, int p) {
    return sub(sum[u], mul(sum[p],
    pw[dep[u] - dep[p]]));
}

void DFSsiz(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u])
        if (v != p && !vis[v]) {
            DFSsiz(v, u); siz[u] += siz[v];
        }
}

void DFSsum(int u, int p) {
    sum[u] = add(mul(sum[p], B), s[u]);
    rev[u] = add(rev[p], mul(s[u], pw[dep[p]]));
    dep[u] = dep[p] + 1; mx = max(mx, dep[u]);
    for (int v : adj[u])
        if (v != p && !vis[v]) DFSsum(v, u);
}

void DFScal(int u, int p) {
    if (found) return; ver[dep[u]] = u;
    if (dep[u] <= len && dep[u] * 2 >= len) {
        int v = ver[dep[u] * 2 - len];
        if (sum[v] == rev[v] &&
        s2[dep[u] - dep[v]].count(getHash(u, v))) {
            found = true; return;
        }
    }
    if ((dep[u] - 1) * 2 <= len &&
    s1[dep[u] - 1].count(getHash(u, root))) {
            found = true; return;
        }
    for (int v : adj[u])
        if (v != p && !vis[v]) DFScal(v, u);
}

void DFSpush(int u, int p) {
    ver[dep[u]] = u;
    if (dep[u] <= len && dep[u] * 2 >= len) {
        int v = ver[dep[u] * 2 - len];
        if (sum[v] == rev[v])
            s1[dep[u] - dep[v]].insert(getHash(u, v));
    }
    if ((dep[u] - 1) * 2 <= len)
        s2[dep[u] - 1].insert(getHash(u, root));
    for (int v : adj[u])
        if (v != p && !vis[v]) DFSpush(v, u);

}

int findCen(int u) {
    int c = u; int p = 0;
    while (true) {
        bool flag = false;
        for (int v : adj[c])
            if (v != p && !vis[v] &&
            siz[v] * 2 > siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        if (flag) continue; break;
    }
    return c;
}

bool check(int u) {
    if (len <= 1) return true;
    found = false;
    for (int i = 0; i <= mx; i++) {
        s1[i].clear(); s2[i].clear();
    }
    s2[0].insert(0);
    for (int v : adj[u])
        if (!vis[v]) {
            DFScal(v, u); DFSpush(v, u);
        }
    return found;
}

void DFSsol(int u) {
    DFSsiz(u, 0); root = u = findCen(u);
    vis[u] = true; mx = 0; DFSsum(u, 0);
    int lo = 0, hi = mx; ver[1] = u;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        len = mi * 2;
        if (check(u)) {
            res = max(res, len);
            lo = mi + 1;
        }
        else hi = mi - 1;
    }
    lo = 0; hi = mx;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        len = mi * 2 + 1;
        if (check(u)) {
            res = max(res, len);
            lo = mi + 1;
        }
        else hi = mi - 1;
    }
    for (int v : adj[u])
        if (!vis[v]) DFSsol(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> (s + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = mul(pw[i - 1], B);
    DFSsol(1); cout << res << '\n';
}