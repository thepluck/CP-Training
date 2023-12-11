#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
  return a < b ? a = b, 1 : 0; 
}

const int N = 205;

long long dp[N][N][N];
int a[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
  memset(dp, 0xc0, sizeof dp);
  dp[1][1][1] = a[1][1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) {
        if (j <= k) {
          if (k < n)
            cmax(dp[i][j][k + 1],
            dp[i][j][k] + a[i][k + 1]);
          else if (j > 1)
            cmax(dp[i][j][1],
            dp[i][j][k] + a[i][1]);
        } else if (k + 1 < j)
          cmax(dp[i][j][k + 1],
          dp[i][j][k] + a[i][k + 1]);
        if (i < n)
          cmax(dp[i + 1][k][k],
          dp[i][j][k] + a[i + 1][k]);
      }
  long long res = 0;
  for (int j = 1; j <= n; j++)
    res = max(res, dp[n][j][n]);
  cout << res;
}