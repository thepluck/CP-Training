#include <bits/stdc++.h>

using namespace std;


const int N = 300005;
const int K = 20000005;

using ll = long long;
using plli = pair <ll, int>;
using ii = pair <int, int>;

int par[N], siz[N];
vector <int> ord;
ll dep[N], lim[N];
bool vis[K], hasIn[K];
vector <plli> tot[N];
int root[K], scc, cnt;
vector <ii> tree[N];
int head[K], nxt[K], to[K], edge = 0;

void addEdge(int u, int v) {
    to[edge] = v; nxt[edge] = head[u];
    head[u] = edge++;
}

void DFSsiz(int u, int p) {
    siz[u] = 1;
    for (auto e : tree[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            DFSsiz(v, u);
            siz[u] += siz[v];
        }
    }
}

int findCen(int u) {
    int p = 0, c = u;
    while (true) {
        bool flag = false;
        for (auto e : tree[c]) {
            int v; tie(v, ignore) = e;
            if (v != p && !vis[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        }
        if (flag) continue; break;
    }
    return c;
}

void DFSdep(int u, int p,
vector <pair <ll, int>> &res) {
    res.emplace_back(dep[u], u);
    for (auto e : tree[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            dep[v] = dep[u] + w;
            DFSdep(v, u, res);
        }
    }
}

void DFScen(int u) {
    DFSsiz(u, 0); u = findCen(u);
    vis[u] = true; dep[u] = 0;
    DFSdep(u, 0, tot[u]);
    sort(tot[u].begin(), tot[u].end());
    vector <int> seg;
    for (int i = 0; i < tot[u].size(); i++) {
        seg.emplace_back(++cnt);
        addEdge(cnt, tot[u][i].second);
        if (i > 0) addEdge(cnt, cnt - 1);
        if (tot[u][i].first <= lim[u])
            addEdge(u, tot[u][i].second);
    }
    for (auto pp : tot[u]) {
        int v; ll dis; tie(dis, v) = pp;
        auto it = upper_bound(tot[u].begin(),
        tot[u].end(), plli(lim[v] - dis, 1e9));
        if (it != tot[u].begin())
            addEdge(v, seg[distance(
            tot[u].begin(), it) - 1]);
    }
    for (auto e : tree[u]) {
        int v; tie(v, ignore) = e;
        if (!vis[v]) DFScen(v);
    }
}

void DFS(int u, bool need) {
    vis[u] = true; root[u] = scc;
    for (int i = head[u]; i >= 0; i = nxt[i])
        if (!vis[to[i]]) DFS(to[i], need);
    if (need) ord.emplace_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; cnt = n;
    for (int i = 1; i <= n; i++)
        cin >> lim[i];
    for (int i = 1; i < n; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    memset(head, -1, sizeof head);
    DFScen(1); int res = 0;
    memset(vis, 0, sizeof vis);
    for (int u = 1; u <= cnt; u++)
        if (!vis[u]) DFS(u, true);
    reverse(ord.begin(), ord.end());
    memset(vis, 0, sizeof vis);
    for (int u : ord)
        if (!vis[u] && u <= n) {
            res++; DFS(u, false);
        }
    cout << res << '\n';
}