#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<tuple<int, int, int, string>> v(n);
  for (auto &[a, b, c, s] : v) {
    cin >> a >> b >> c;
    cin.ignore();
    getline(cin, s);
  }
  sort(v.begin(), v.end());
  cout << get<3>(v[n - 1]) << '\n';
}