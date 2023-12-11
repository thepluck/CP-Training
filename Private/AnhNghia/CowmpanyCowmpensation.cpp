//https://codeforces.com/group/sd4r2IvEfL/contest/248118/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int MOD = 1e9 + 7;

int inv[N], f[N][N];
int n, m, C[N][N], g[N];
vector <int> adj[N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mmul(int x, int y) {
    return (long long)x * y % MOD;
}

int mdiv(int x, int y) {
    return mmul(x, inv[y]);
}

void DFS(int u) {
    for (int i = 1; i <= n; i++)
        f[u][i] = 1;
    for (int v : adj[u]) {
        DFS(v); int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = madd(sum, f[v][i]);
            f[u][i] = mmul(f[u][i], sum);
        }
    }
}

int getC(int n, int k) {
    if (n < k) return 0;
    int res = 1;
    for (int i = 1; i <= k; i++)
        res = mdiv(mmul(res, n - k + i), i);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m; inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - mmul(MOD / i, inv[MOD % i]);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p; adj[p].push_back(i);
    }
    DFS(1); int res = 0;
    for (int i = 0; i <= n; i++) C[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = madd(C[i - 1][j - 1], C[i - 1][j]);
    for (int i = 1; i <= n; i++)
        g[i] = madd(g[i - 1], f[1][i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            g[i] = msub(g[i], mmul(g[i - j], C[i][j]));
        res = madd(res, mmul(g[i], getC(m, i)));
    }
    cout << res << '\n';
}