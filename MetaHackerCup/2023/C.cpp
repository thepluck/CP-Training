#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  int cur = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') {
      for (int j = 2 * i; j <= n; j += i)
        s[j] ^= 1;
      cur++;
    }
  long long res = 0;
  int q;
  cin >> q;
  while (q--) {
    int i;
    cin >> i;
    if (s[i] == '1')
      cur--;
    else
      cur++;
    s[i] ^= 1;
    res += cur;
  }
  cout << cur << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  /// meta hacker cup
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
}