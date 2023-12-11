#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll row = 0;
    for (int k = 32; k >= 0; k--) {
      ll cur = row + (1ll << k);
      if (cur <= (2 * n - 1) / (cur + 1)) row = cur;
    }
    n -= row * (row + 1) / 2;
    row++;
    ll l = n, r = n, res = 0;
    while (row > 0) {
      ll ql = (row - 1) * row + l;
      ll qr = (row - 1) * row + r;
      res += (qr + ql) * (qr - ql + 1) / 2;
      row--;
      l = max(l - 1, 1ll);
      r = min(r + 1, row);
    }
    cout << res << '\n';
  }
}