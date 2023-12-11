#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 631;

int main() {
  int sub; cin >> sub;
  int n; if (sub == 3) cin >> n;
  char c;
  long long h11 = 0, h12 = 0, p1 = 1;
  long long h21 = 0, h22 = 0, p2 = 1;
  while (cin >> c) {
    if (!isalpha(c)) break;
    h11 = (h11 * BASE + c) % MOD1;
    h12 = (h12 + p1 * c) % MOD1;
    p1 = p1 * BASE % MOD1;

    h21 = (h21 * BASE + c) % MOD2;
    h22 = (h22 + p2 * c) % MOD2;
    p2 = p2 * BASE % MOD2;
  }
  cout << (h11 == h12 && h21 == h22 ? "YES" : "NO");
}