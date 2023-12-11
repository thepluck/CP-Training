#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, lim; cin >> n >> lim;
  long long res = 0;
  vector<int> small, big;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x; res += x;
    if (x <= lim / 2) small.push_back(x);
    else big.push_back(x);
  }
  if (small.empty())
    return cout << res + big.size(), 0;
  sort(small.begin(), small.end());
  sort(big.begin(), big.end());
  int low = 0;
  int high = min(small.size() + 1, big.size());
  while (low < high) {
    int mid = (low + high + 1) / 2;
    bool flag = true;
    for (int i = 0; i < mid; i++) {
      if (mid - 1 - i < small.size() &&
      big[i] + small[mid - 1 - i] > lim) {
        flag = false; break;
      }
      if (mid - 2 - i >= 0 &&
      big[i] + small[mid - 2 - i] > lim) {
        flag = false; break;
      }
    }
    if (flag) low = mid;
    else high = mid - 1;
  }
  cout << res + 1 + big.size() - low;
}