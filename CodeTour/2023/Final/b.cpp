#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <class X, class Y> bool cmin(X& a, const Y& b) {
  return a > b ? a = b, 1 : 0;
}

template <class X, class Y> bool cmax(X& a, const Y& b) {
  return a < b ? a = b, 1 : 0;
}

using ll = long long;

int dp[35][35];

int calc(const string &s, const string &t) {
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  int n = s.size(), m = t.size();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (i < n && j < m)
        cmin(dp[i + 1][j + 1], dp[i][j] + (s[i] != t[j] && s[i] != '?'));
      if (i < n) cmin(dp[i + 1][j], dp[i][j] + 1);
      if (j < m) cmin(dp[i][j + 1], dp[i][j] + 1);
    }
  return dp[n][m];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> dict(n);
  for (auto &s : dict) cin >> s;
  int m; cin >> m;
  vector<string> word(m);
  for (auto &s : word) cin >> s;
  int res = 0;
  for (auto s : word) {
    int best = 1e9;
    for (auto t : dict) cmin(best, calc(s, t));
    res += best;
  }
  cout << res << '\n';
  return 0;
}