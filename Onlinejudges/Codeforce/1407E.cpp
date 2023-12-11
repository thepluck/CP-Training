
// Problem : E. Egor in the Republic of Dagestan
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/contest/1407/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int dp[3][N];
vector <int> g[2][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        g[t][v].push_back(u);
    }
    for (int i = 1; i < n; i++)
        dp[0][i] = dp[1][i] = dp[2][i] = n;
    queue <int> q; q.push(n);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int t = 0; t < 2; t++)
            for (int v : g[t][u]) {
                if (dp[t][v] < n) continue;
                dp[t][v] = dp[2][u] + 1;
                if (max(dp[0][v], dp[1][v]) < n) {
                    q.push(v);
                    dp[2][v] = max(dp[0][v], dp[1][v]);
                }
            }
    }
    if (dp[2][1] == n) cout << "-1\n";
    else cout << dp[2][1] << '\n';
    for (int i = 1; i <= n; i++)
        cout << (dp[0][i] > dp[1][i] ? 0 : 1);
}