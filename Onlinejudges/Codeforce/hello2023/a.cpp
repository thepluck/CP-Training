#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; string s;
    cin >> n >> s;
    bool flag = false;
    for (int i = 0; i + 1 < n; i++)
      if (s[i] != s[i + 1]) {
        if (s[i] == 'L') cout << i + 1 << '\n';
        else cout << 0 << '\n';
        flag = true; break;
      }
    if (!flag) cout << -1 << '\n';
  }
}