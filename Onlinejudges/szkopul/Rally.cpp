#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
} 

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
} 

vector<int> dag[N], tree[N], wait[N];
int dis1[N], dis2[N], dis3[N];
int par[N], jump[N], ans[N];
multiset<int> val[N];

int lca(int u, int v) {
    if (dis1[u] < dis1[v]) swap(u, v);
    while (dis1[u] > dis1[v]) {
        if (dis1[jump[u]] >= dis1[v])
            u = jump[u];
        else u = par[u];
    }
    while (u != v) {
        if (jump[u] != jump[v]) {
            u = jump[u]; v = jump[v];
        } else {
            u = par[u]; v = par[v];
        }
    }
    return u;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        dag[v].push_back(u); dis2[u]++;
    }
    for (int u = 1; u <= n; u++) {
        dag[u].push_back(0); dis2[0]++;
    }
    vector<int> topo;
    for (int u = 1; u <= n; u++)
        if (!dis2[u]) topo.push_back(u);
    for (int i = 0; i <= n; i++) {
        int u = topo[i];
        for (int v : dag[u]) {
            if (--dis2[v] == 0)
                topo.push_back(v);
            }
    }
    for (int i = n - 1; i >= 0; i--) {
        int u = topo[i];
        for (int v : dag[u])
            if (cmax(dis1[u], dis1[v] + 1))
                par[u] = v;
        tree[par[u]].push_back(u);
        if (dis1[jump[par[u]]] * 2 ==
        dis1[par[u]] + dis1[jump[jump[par[u]]]])
            jump[u] = jump[jump[par[u]]];
        else jump[u] = par[u];
    }
    for (int i = 0; i <= n; i++) {
        int u = topo[i];
        for (int v : dag[u])
            cmax(dis2[v], dis2[u] + 1);
        dis3[u] = dis1[u];
        for (int v : tree[u])
            cmax(dis3[u], dis3[v]);
    }
    for (int i = n; i >= 0; i--) {
        int u = topo[i];
        int mx1 = -1, mx2 = -1, ver = -1;
        for (int v : tree[u]) {
            cmax(mx2, dis3[v]);
            if (mx2 > mx1) {
                swap(mx1, mx2); ver = v;
            }
        }
        for (int v : tree[u])
            if (v != ver)
                ans[v] = max({ans[u], dis1[u], mx1});
            else ans[v] = max({ans[u], dis1[u], mx2});
    }
    for (int i = 0; i < n; i++) {
        int u = topo[i];
        for (int v : tree[u]) {
            if (val[u].size() < val[v].size())
                val[u].swap(val[v]);
            for (int x : val[v]) val[u].insert(x);
            val[v].clear();
        }
        for (int x : wait[u])
            val[u].erase(val[u].find(x));
        if (val[u].size())
            cmax(ans[u], *val[u].rbegin());
        for (int v : dag[u]) {
            val[u].insert(dis1[v] + dis2[u] + 1);
            wait[lca(u, v)].push_back(dis1[v] + dis2[u] + 1);
        }
    }
    auto it = min_element(ans + 1, ans + n + 1);
    cout << it - ans << ' ' << *it - 1 << '\n';
}