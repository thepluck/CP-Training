#include <bits/stdc++.h>

using namespace std;

void output_div2(long long x) {
  cout << x / 2;
  if (x % 2) cout << ".5";
  cout << '\n';
}

void solve() {
  int n; cin >> n;
  vector<long long> a(n);
  for (long long &i : a) cin >> i;
  sort(a.begin(), a.end());
  if (n == 5) output_div2(a[4] - a[0] + max(a[3] - a[2], a[2] - a[1]));
  else output_div2(a.end()[-1] + a.end()[-2] - a[0] - a[1]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  /// meta hacker cup
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
}