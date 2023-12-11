#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n == 3) {
      cout << "NO\n"; continue;
    }
    cout << "YES\n";
    if (n & 1) {
      for (int i = 1; i <= n; i++)
        if (i & 1) cout << 1 - n / 2 << ' ';
        else cout << n / 2 << ' ';
      cout << '\n';
    } else {
      for (int i = 1; i <= n; i++)
        if (i & 1) cout << "1 ";
        else cout << "-1 ";
      cout << '\n';
    }
  }
}