#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7, N = 105;

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

vector <int> adj[N];
vector <int> que[N];
int f[N][N], g[N]; bool vs[N];

int main() {
    //freopen("partitions2.inp", "r", stdin);
    //freopen("partitions2.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int c, x; cin >> c;
        while (c--) {
            cin >> x; que[i].push_back(x);
        }
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            f[i + 1][j] = madd(f[i + 1][j], mmul(f[i][j], j));
            f[i + 1][j + 1] = madd(f[i + 1][j + 1], f[i][j]);
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            g[i] = madd(g[i], f[i][j]);
    int res = 0;
    for (int msk = 0; msk < (1 << q); msk++) {
        int bit = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            adj[i].clear(); vs[i] = 0;
        }
        for (int i = 0; i < q; i++) {
            if (!(msk >> i & 1)) continue; bit++;
            for (int j = 1; j < int(que[i].size()); j++) {
                adj[que[i][j - 1]].push_back(que[i][j]);
                adj[que[i][j]].push_back(que[i][j - 1]);
            }
        }
        queue <int> q;
        for (int i = 1; i <= n; i++) {
            if (vs[i]) continue;
            vs[i] = 1; q.push(i); cnt++;
            while (q.size()) {
                int u = q.front(); q.pop();
                for (int v : adj[u])
                    if (!vs[v]) {
                        vs[v] = 1; q.push(v);
                    }
            }
        }
        if (bit & 1) res = msub(res, g[cnt]);
        else res = madd(res, g[cnt]);
    }
    cout << res << '\n';
}