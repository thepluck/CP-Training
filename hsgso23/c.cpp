#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int lp[N], cnt[N];

int main() {
  iota(lp, lp + N, 0);
  for (int i = 2; i < N; i++)
    if (lp[i] == i)
      for (int j = i * i; j < N; j += i)
        lp[j] = i;
  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    while (x > 1) {
      int p = lp[x], pw = 1;
      while (x % p == 0) {
        pw *= p; x /= p;
      }
      cnt[pw]++;
    }
  }
  
}