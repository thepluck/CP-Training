#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2005;

char s[N], t[N];
bool cut[N][N];
int dp[N][N];

int query(int i, int j, int d) {
    return dp[i + d - 1][j] - dp[i - 1][j];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k, n; cin >> k;
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1); ll res = 0;
    for (int i = 1; i <= n; i++)
        for (int x = 1, y = i; y <= n; y++) {
            dp[x][y] = dp[x - 1][y - 1];
            if (s[x] == t[y]) dp[x][y]++;
        }
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            
        }
}