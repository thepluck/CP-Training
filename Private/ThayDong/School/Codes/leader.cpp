#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 0x3f3f3f3f;

ll dp[55][1 << 15], s[20];
int a[55], g[55], n, m;
int k[20], mx[1 << 15];

ll rec(int i, int t) {
    if (~dp[i][t]) return dp[i][t];
    if (t == (1 << m) - 1) return 0;
    dp[i][t] = 1e18;
    for (int j = 0; j < n; j++)
        if (!(t >> g[j] & 1) &&
        a[i] >= s[g[j]] - a[j]
        && a[j] == a[mx[t]])
            dp[i][t] = min(dp[i][t],
            rec(mx[t + (1 << g[j])],
            t + (1 << g[j])) + a[i]);
    for (int j = 0; j < n; j++)
        if (!(t >> g[j] & 1) &&
        a[i] >= s[g[j]] - a[j] &&
        a[mx[t]] == a[mx[t + (1 << g[j])]])
            dp[i][t] = min(dp[i][t],
            rec(j, t + (1 << g[j])) + a[i]);
    return dp[i][t];
}

int main() {
    freopen("leader.inp", "r", stdin);
    freopen("leader.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n; n = 0;
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> a[n]; s[i] += a[n];
            g[n] = i; n++;
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        mx[i] = n;
        for (int j = 0; j < n; j++)
            if (!(i >> g[j] & 1) &&
            a[j] > a[mx[i]]) mx[i] = j;
    }
    a[n] = 0;
    memset(dp, -1, sizeof dp);
    if (rec(mx[0], 0) == 1e18)
        cout << "-1\n";
    else cout << dp[mx[0]][0] << '\n';
}