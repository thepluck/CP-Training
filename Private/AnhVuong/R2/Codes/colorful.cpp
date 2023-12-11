#include <bits/stdc++.h>

using namespace std;

#define lb lower_bound

const int N = 1e5 + 5;

int ans[N], ord[N], timer, ver[N];
set <int> lst[N]; int par[N][17];
vector <int> adj[N];
int dep[N], col[N];

void DFS(int u) {
    ver[ord[u] = ++timer] = u;
    dep[u] = dep[par[u][0]] + 1;
    for (int k = 1; k < 17; k++)
        par[u][k] = par[par[u][k - 1]][k - 1];
    for (int v : adj[u])
        if (v != par[u][0]) {
            par[v][0] = u; DFS(v);
        }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = 16; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v) return u;
    for (int k = 16; k >= 0; k--)
        if (par[u][k] != par[v][k]) {
            u = par[u][k]; v = par[v][k];
        }
    return par[u][0];
}

void add(int u, int x) {
    if (lst[x].size() == 0) {
        lst[x].insert(ord[u]);
        ans[x] = 0; return;
    }
    auto it = lst[x].lb(ord[u]);
    int r = -1;
    if (it != lst[x].end())
        r = LCA(u, ver[*it]);
    if (it != lst[x].begin()) {
        int v = LCA(u, ver[*prev(it)]);
        if (r < 0 || dep[r] < dep[v]) r = v;
    }
    ans[x] += dep[u] - dep[r];
    int p = LCA(ver[*lst[x].begin()],
    ver[*lst[x].rbegin()]);
    if (dep[p] >= dep[r])
        ans[x] += dep[p] - dep[r];
    lst[x].insert(ord[u]);
}

void remove(int u, int x) {
    lst[x].erase(ord[u]);
    if (lst[x].size() == 0) {
        ans[x] = -1; return;
    }
    auto it = lst[x].lb(ord[u]);
    int r = -1;
    if (it != lst[x].end())
        r = LCA(u, ver[*it]);
    if (it != lst[x].begin()) {
        int v = LCA(u, ver[*prev(it)]);
        if (r < 0 || dep[r] < dep[v]) r = v;
    }
    ans[x] -= dep[u] - dep[r];
    int p = LCA(ver[*lst[x].begin()],
    ver[*lst[x].rbegin()]);
    if (dep[p] >= dep[r])
        ans[x] -= dep[p] - dep[r];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(ans, -1, sizeof ans);
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cin >> col[i]; add(i, col[i]);
    }
    int q; cin >> q;
    while (q--) {
        char cmd; int u; cin >> cmd;
        if (cmd == 'U') {
            cin >> u; remove(u, col[u]);
            cin >> col[u]; add(u, col[u]);
        }
        else {
            cin >> u; cout << ans[u] << '\n';
        }
    }
}