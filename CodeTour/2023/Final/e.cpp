#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector<pair<int, int>> rows[N];
bool good[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> farms(n);
  vector<int> rar;
  for (auto &p : farms) {
    cin >> p.first >> p.second;
    rar.push_back(p.first);
  }
  sort(rar.begin(), rar.end());
  rar.erase(unique(rar.begin(), rar.end()), rar.end());
  for (int i = 0; i < n; i++) {
    int x = lower_bound(rar.begin(), rar.end(), farms[i].first) - rar.begin();
    rows[x].emplace_back(farms[i].second, i);
  }
  for (int i = 0; i < rar.size(); i++) {
    sort(rows[i].begin(), rows[i].end());
  }
  int m; cin >> m;
  while (m--) {
    int r, x, y; cin >>  r >> x >> y;
    for (int u = x - r; u <= x + r; u++) {
      auto it = lower_bound(rar.begin(), rar.end(), u);
      if (it == rar.end()) continue;
      int i = it - rar.begin();
      auto it2 = prev(upper_bound(rows[i].begin(), rows[i].end(), make_pair(y - r, n)));
      while (it2 != rows[i].end() && it2->first <= y + r) {
        good[it2->second] = 1; it2++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans += good[i];
  cout << ans << '\n';
}