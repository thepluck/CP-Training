#include <bits/stdc++.h>

using namespace std;

const int N = 605;

long long dis[N][N], pre[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    vector <tuple <int, int, int>> edge;
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
        edge.emplace_back(u, v, w);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j],
                dis[i][k] + dis[k][j]);
    memset(pre, 0xc0, sizeof pre);
    int q; cin >> q;
    while (q--) {
        int u, v; long long l;
        cin >> u >> v >> l;
        for (int x = 1; x <= n; x++) {
            pre[u][x] = max(pre[u][x], l - dis[x][v]);
            pre[v][x] = max(pre[v][x], l - dis[x][u]);
        }
    }
    int res = 0;
    for (auto e : edge) {
        int u, v, w; tie(u, v, w) = e;
        bool flag = 0;
        for (int x = 1; x <= n; x++)
            if (dis[x][u] + w <= pre[x][v]) flag = 1;
        res += flag;
    }
    cout << res << '\n';
}