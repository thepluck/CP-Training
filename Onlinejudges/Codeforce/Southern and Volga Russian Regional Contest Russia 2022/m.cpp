#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (~n & 1) {
      cout << n / 2 << ' ' << n / 2 << '\n';
    } else {
      int d = 2;
      while (d * d <= n && n % d != 0) d++;
      if (n % d != 0) d = n;
      cout << n / d << ' ' << n / d * (d - 1) << '\n';
    }
  }
}