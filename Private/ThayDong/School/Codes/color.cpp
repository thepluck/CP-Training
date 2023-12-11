#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 35;  

int a[N][N], row[N], col[N];
vector <int> adj[N * 2]; bool vs[N];

int main() {
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    bool fix = 0; long long res = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int st = 0; st < n * m; st++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 || a[i][j] == 2) {
                    if (row[i] && row[i] != a[i][j]) {
                        cout << "0\n"; return 0;
                    }
                    if (col[j] && col[j] != a[i][j]) {
                        cout << "0\n"; return 0;
                    }
                    row[i] = col[j] = a[i][j]; fix = 1;
                }
                if (a[i][j] == 3) {
                    if ((row[i] || col[j])
                    && row[i] == col[j]) {
                        cout << "0\n"; return 0;
                    }
                    if (row[i]) col[j] = 3 - row[i];
                    if (col[j]) row[i] = 3 - col[j];
                }
                if (a[i][j] == 0 && row[i] && col[j]) {
                    if (row[i] == col[j])
                        a[i][j] = row[i];
                    else a[i][j] = 3;
                }
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 3 && !row[i]) {
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    queue <int> q; int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vs[i] || row[i]) continue;
        q.push(i); vs[i] = 1; cnt++;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : adj[u])
                if (!vs[v]) {
                    vs[v] = 1; q.push(v);
                }
        }
    }
    for (int j = 0; j < m; j++) {
        if (vs[n + j] || col[j]) continue;
        q.push(n + j); vs[n + j] = 1; cnt++;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : adj[u])
                if (!vs[v]) {
                    vs[v] = 1; q.push(v);
                }
        }
    }
    for (int i = 0; i < cnt; i++) res *= 2;
    if (!fix) res--; cout << res << '\n';
}