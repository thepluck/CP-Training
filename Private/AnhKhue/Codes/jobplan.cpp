#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector <int> adj[N * N];
int n, m, x[N * N], y[N];
bool vs[N * N];

bool dfs(int u) {
    if (vs[u]) return false; vs[u] = 1;
    for (int v : adj[u])
        if (!y[v] || dfs(y[v])) {
            x[u] = v; y[v] = u; return true;
        }
    return false;
}

int id(int i, int j) {
    return (i - 1) * m + j;
}

int main() {
    freopen("jobplan.in", "r", stdin);
    freopen("jobplan.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m; int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char x; cin >> x;
            if (x == 'N') continue;
            for (int k = 1; k <= m; k++)
                adj[id(i, k)].push_back(j);
        }
    vector <pair <int, int>> p;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        for (int j = 1; j <= m; j++)
            p.emplace_back(c * (2 * j - 1), id(i, j));
    }
    sort(p.begin(), p.end());
    for (auto x : p) {
        memset(vs, 0, sizeof vs);
        if (dfs(x.second)) res += x.first;
    }
    for (int j = 1; j <= m; j++)
        if (!y[j]) res = -1;
    cout << res << '\n';
}
