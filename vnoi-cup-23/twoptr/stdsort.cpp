#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> p(n), a(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int t; cin >> t; return t;
  });
  for (int i = 0; i < n; i++)
    a[p[i]] = i;
  cout << "!";
  for (int i = 0; i < n; i++)
    cout << " " << a[i];
  cout << endl;
}

int main() {
  cout << "\n";
  int t; cin >> t;
  while (t--) solve();
}