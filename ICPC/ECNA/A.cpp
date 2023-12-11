#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100005;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
  return a > b ? a = b, 1 : 0;
}

struct sol {
  int dp[N];

  constexpr sol(): dp() {
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
      dp[i] = i;
      for (int j = 1; j < i; j++) {
        cmin(dp[i], dp[i - j] + dp[j]);
      }
      for (int j = 1; j * j <= i; j++)
        if (i % j == 0)
          cmin(dp[i], dp[j] + dp[i / j]);
      int x = i, y = 0, pw = 1;
      while (x > 10) {
        y += (x % 10) * pw;
        if (x % 10)
          cmin(dp[i], dp[y] + dp[x / 10]);
        x /= 10;
        pw *= 10;
      }
    }
  }
} s;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n; cout << s.dp[n] << '\n';
}