#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back

const int N = 150005;

vector <int> adj[N];
int deg[N], n, m, k;
set <int> can[2];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (!deg[i]) can[0].insert(i);
    vector <pair <int, int>> edge;
    for (int i = 0, pre, u; i < n; i++) {
        auto it = can[0].begin();
        for (int i = 0; i < k && i < can[0].size(); i++)
            it = next(it);
        if (it != can[0].end()) u = *it;
        else {
            if (can[0].empty()) {
                u = *can[1].rbegin();
                edge.emplace_back(pre, u);
            }
            else {
                u = *prev(it);
                if (can[1].size()) {
                    int v = *can[1].rbegin();
                    if (v > u)
                        edge.emplace_back(pre, u = v);
                }
            }
        }
        can[0].erase(u); can[1].erase(u);
        while (can[0].size() && *can[0].begin() < u) {
            int v = *can[0].begin(); k--;
            can[0].erase(v); can[1].insert(v);
        }
        for (int v : adj[u])
            if (!(--deg[v])) can[0].insert(v);
        adj[u].clear();
        cout << (pre = u) << ' ';
    }
    cout << '\n' << edge.size() << '\n';
    for (auto e : edge)
        cout << e.fi << ' ' << e.se << '\n';
}

int main() {
    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int subID, nTest;
    cin >> subID >> nTest;
    while (nTest--) solve();
}