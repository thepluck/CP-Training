#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  priority_queue<int> pq;
  while (t--) {
    int n, m, res = 0;
    cin >> n >> m; m--;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long long sum = 0;
    for (int i = m + 1; i < n; i++) {
      sum += a[i]; pq.push(-2 * a[i]);
      if (sum < 0) {
        sum += pq.top(); res++; pq.pop();
      }
    }
    while (pq.size()) pq.pop();
    sum = 0;
    for (int i = m; i > 0; i--) {
      sum += a[i]; pq.push(2 * a[i]);
      if (sum > 0) {
        sum -= pq.top(); res++; pq.pop();
      }
    }
    while (pq.size()) pq.pop();
    cout << res << '\n';
  }
}