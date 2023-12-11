#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> p(n);
    for (int &x : p) cin >> x;
    vector<vector<int>> adj(n);
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    vector<char> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> cmp(1, i), val;
        vis[i] = 1;
        for (int j = 0; j < cmp.size(); j++) {
            val.push_back(p[cmp[j]]);
            for (int v : adj[cmp[j]])
                if (!vis[v]) {
                    vis[v] = 1; cmp.push_back(v);
                }
        }
        sort(val.rbegin(), val.rend());
        sort(cmp.begin(), cmp.end());
        for (int j = 0; j < cmp.size(); j++)
            p[cmp[j]] = val[j];
    }
    for (int x : p) cout << x << ' ';
}