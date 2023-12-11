#include <bits/stdc++.h>

using namespace std;

map<long long, vector<int>> ans;

vector<int> cur;

void rec(long long prod, int sum, int x) {
  if (sum == 0) {
    auto &v = ans[prod];
    if (v.empty() || v.size() > cur.size()) v = cur;
    return;
  }
  if (x > sum) return;
  cur.push_back(x);
  rec(prod * x, sum - x, x);
  cur.pop_back();
  rec(prod, sum, x + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  /// meta hacker cup
  rec(1, 41, 1);
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    int x; cin >> x;
    auto it = ans.find(x);
    if (it == ans.end()) cout << "-1\n";
    else {
      auto &v = it->second;
      cout << v.size();
      for (int i : v) cout << ' ' << i;
      cout << '\n';
    }
  }
}