#include <bits/stdc++.h>

using namespace std;

int dis[55][55];

void solve() {
    int n, m; cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    vector <tuple <int, int, int>> edge;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(u, v, w);
        dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j],
                dis[i][k] + dis[k][j]);
    for (auto e : edge) {
        int u, v, w; tie(u, v, w) = e;
        if (dis[u][v] != w) {
            cout << "Impossible\n"; return;
        }
    }
    cout << m << '\n';
    for (auto e : edge) {
        int u, v, w; tie(u, v, w) = e;
        cout << u << ' ' << v << ' ' << w << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ':'; solve();
    }
}