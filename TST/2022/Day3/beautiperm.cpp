#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int pos[N], need[N], dp[N], used[N];
    
void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    if (n > int(1e6)) return 0;
    int res = 1;
    for (int i = 1; i <= n - m; i++)
        res = 1ll * res * i % MOD;
    while (m--) {
        int u, v; cin >> u >> v;
        pos[v] = u; used[u]++;
        if (used[u] > 1)
            return cout << 0, 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (pos[i]) {
            if (pos[i] < i - 2) continue;
            if (pos[i] == i) {
                dp[i] = dp[i - 1];
                need[i] = i; continue;
            }
            if (pos[i] == i - 1) {
                need[i] = need[i - 1];
                dp[i] = dp[i - 1]; continue;
            }
            if (pos[i] == i - 2) {
                if (need[i - 2] && need[i - 2] != i - 1) continue;
                if (pos[i - 1] && pos[i - 1] < i) continue;
                need[i] = pos[i - 1]; dp[i] = dp[i - 2];
                continue;
            }
            if (need[i - 1] > i - 1) continue;
            need[i] = pos[i]; dp[i] = dp[i - 1];
        } else {
            if (!need[i - 1] || need[i - 1] == i - 1)
                dp[i] = dp[i - 1];
            if (i > 1 && (!need[i - 1] || need[i - 1] >= i))
                add(dp[i], dp[i - 1]);
            if (i > 2) {
                if (need[i - 2] && need[i - 2] != i - 1) continue;
                if (pos[i - 1] && pos[i - 1] < i) continue;
                need[i] = pos[i - 1]; add(dp[i], dp[i - 2]);
            }
        }
    if ((res -= dp[n]) < 0) res += MOD;
    cout << res;
}