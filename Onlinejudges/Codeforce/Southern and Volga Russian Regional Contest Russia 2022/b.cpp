#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = (n % 3 != 2);
    for (int i = 2; i < n; i += 3)
      if (s[i] != s[i - 1]) flag = false;
    cout << (flag ? "YES\n" : "NO\n");
  }
}