#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> adj[N], lst[N];
int down[N], up[N];

void dfs1(int u, int p) {
    for (int v : adj[u])
        if (v != p) {
            dfs1(v, u);
            down[u] = max(down[u], down[v] + 1);
        }
}

void dfs2(int u, int p) {
    int fi = up[u], se = 0, ver = 0;
    for (int v : adj[u])
        if (v != p) {
            if (down[v] + 1 > fi) {
                se = fi; fi = down[v] + 1;
                ver = v;
            } else se = max(se, down[v] + 1);
        }
    for (int v : adj[u])
        if (v != p) {
            if (v == ver) up[v] = se + 1;
            else up[v] = fi + 1;
            dfs2(v, u);
        }
    lst[u].push_back(up[u]);
    for (int v : adj[u])
        if (v != p)
            lst[u].push_back(down[v] + 1);
    sort(lst[u].begin(), lst[u].end());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    while (q--) {
        int u, l; cin >> u >> l;
        cout << lst[u].end() - upper_bound(lst[u].begin(), lst[u].end(), l) << '\n';
    }
}