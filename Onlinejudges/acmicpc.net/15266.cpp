/// cerc 2017 intrinsic interval

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], p[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; p[a[i]] = i;
  }
  vector<pair<int, int>> lef, rig;
  {
    int l = 1, r = 1, lv = a[1], rv = a[1];
    while (true) {
      lef.emplace_back(l, r);
    }
  }
}