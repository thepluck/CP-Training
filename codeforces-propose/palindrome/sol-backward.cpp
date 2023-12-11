#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
const int LOG = 19;

int n, pal[N], rmq[LOG][N], cnt[N];
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 0, l = 0, r = 0; i < n; i++) {
      pal[i] = i >= r ? 0 : min(pal[l + r - i], r - i);
      while (i + pal[i] < n && i - pal[i] - 1 >= 0
      && s[i + pal[i]] == s[i - pal[i] - 1]) pal[i]++;
      if (i + pal[i] > r) {
        l = i - pal[i]; r = i + pal[i];
      }
    }
    for (int i = 0; i < n; i++)
      rmq[0][i] = i - pal[i];
    for (int k = 1; k < LOG; k++)
      for (int i = 0; i + (1 << k) <= n; i++)
        rmq[k][i] = min(rmq[k - 1][i],
        rmq[k - 1][i + (1 << (k - 1))]);
    cnt[n] = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      for (int k = LOG - 1; k >= 0; k--)
        if (j + (1 << k) <= n && rmq[k][j] > i)
          j += 1 << k;
      pal[i] = 2 * j + 2 - i;
    }
    for (int i = n - 1; i >= 0; i--)
      if (pal[i] <= n) cnt[i] = cnt[pal[i]] + 1;
    long long res = 0;
    for (int i = 0; i < n; i++)
      res += cnt[i];
    cout << res << '\n';
  }
}