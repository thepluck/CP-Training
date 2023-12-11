#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  priority_queue<int> pq;
  vector<pair<int, int>> v(m);
  for (auto &p : v)
    cin >> p.first >> p.second;
  sort(v.rbegin(), v.rend());
  long long res = 0;
  for (int i = n, j = 0; i > 0; i--) {
    while (j < m && v[j].first == i)
      pq.push(v[j++].second);
    if (pq.size()) {
      res += pq.top(); pq.pop();
    }
  }
  cout << res;
}