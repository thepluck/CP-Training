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

const int N = 1e3 + 5;

int dp[N], a[N], sum[N];

int calc(int l, int r) {
  return (r + l) * (r - l + 1) / 2;
}

void solve() {
  int n; cin >> n;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + 2 * i - 1;
    cin >> a[i];
    int j = i;
    while (j > 0 && a[j] == a[i]) j--;
    dp[i] = 1e9;
    if (j > 0) {
      int k = j;
      while (k > 0 && a[k] == a[j]) k--;
      for (int l = k; l < j; l++) {
        int x = i - j, y = j - l;
        if (x > y) swap(x, y);
        cmin(dp[i], dp[l] + sum[x] + calc(x + 1, y));
      }
      cmin(dp[i], dp[j] + calc(1, i - j));
    }
  }
  cout << dp[n] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}