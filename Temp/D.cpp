#include <bits/stdc++.h>

using namespace std;

const int N = 20;

struct frac {
  long long x, y;

  frac(long long _x = 0, long long _y = 1) {
    long long g = __gcd(_x, _y);
    x = _x / g;
    y = _y / g;
  }

  frac operator+(const frac &o) const {
    return frac(x * o.y + y * o.x, y * o.y);
  }

  frac &operator+=(const frac &o) { return *this = *this + o; }

  frac operator/(const long long &o) const { return frac(x, y * o); }
} dp[1 << N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n; cout << 1.0 * n / (2 * n - 2);
}