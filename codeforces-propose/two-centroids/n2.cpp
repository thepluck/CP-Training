#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int par[N], siz[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    siz[i] = 0;
  siz[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    int u = i;
    while (u) {
      siz[u]++; u = par[u];
    }
    int res = n;
    for (int u = 1; u <= i; u++)
      res = min(res, abs(i - 2 * siz[u]));
    cout << res << " \n"[i == n];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}