#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long sum[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 1; i < N; i++)
    for (int j = i * 2; j < N; j += i)
      sum[j] += i;
  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    if (sum[x] > x)
      cout << "abundant\n";
    else if (sum[x] < x)
      cout << "deficient\n";
    else
      cout << "perfect\n";
  }
}