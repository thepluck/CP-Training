#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N], p[N];

void add(int i, int x) {
  for (; i > 0; i -= i & -i)
    bit[i] += x;
}

int get(int i) {
  int ret = 0;
  for (; i < N; i += i & -i)
    ret += bit[i];
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x; p[x] = i;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res += get(p[i]);
    add(p[i], 1);  
  }
  cout << res << '\n';
}