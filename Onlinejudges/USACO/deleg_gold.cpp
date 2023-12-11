
// Problem : Problem 3. Delegation
// Contest : USACO - USACO 2020 February Contest, Gold
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=1019
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;

int cur[N], sz[N];
vector <int> g[N], f[N];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : g[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            f[u].eb(sz[v]);
        }
}

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++)
        f[i].eb(n - sz[i]);
    for (int k = 1; k < n; k++) {
        if ((n - 1) % k) {
            cout << 0; continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int x : f[i]) {
                if (x % k == 0)
                    continue;
                if (cur[k - x % k])
                    cur[k - x % k]--;
                else cur[x % k]++;
            }
        }
        bool flag = 0;
        for (int i = 0; i < k; i++) {
            flag |= cur[i] > 0;
            cur[i] = 0;
        }
        cout << !flag;
    }
}