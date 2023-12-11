#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    if (a > b) cout << "1\n";
    else cout << (n - 1) / a + 1 << '\n';
  }
}