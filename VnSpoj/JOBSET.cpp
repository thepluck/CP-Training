#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;

const int N = 505;
const int inf = 0x3f3f3f3f;

int n, m, s, t;
int c[N][N], p[N];
queue <ii> q;

int bfs() {
    while (!q.empty()) q.pop();
    fill_n(p, n + 2, -1); p[s] = 0;
    q.emplace(s, inf); int u, fl;
    while (!q.empty()) {
        tie(u, fl) = q.front(); q.pop();
        for (int v = 0; v <= n + 1; v++)
            if (p[v] == -1 && c[u][v]) {
                p[v] = u;
                int nfl = min(fl, c[u][v]);
                if (v == t) return nfl;
                q.emplace(v, nfl);
            }
    }
    return 0;
}

int max_flow() {
    int fl = 0, nfl;
    while (nfl = bfs()) {
        fl += nfl; int u = t;
        while (u != s) {
            c[p[u]][u] -= nfl;
            c[u][p[u]] += nfl;
            u = p[u];
        }
    }
    return fl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tot = 0; cin >> n;
    s = 0; t = n + 1;
    for (int i = 1; i <= n; i++) {
        int cap; cin >> cap;
        if (cap < 0) c[i][t] = -cap;
        else {
            c[s][i] = cap; tot += cap;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        c[u][v] = tot + 1;
    }
    cout << tot - max_flow() << '\n';
}