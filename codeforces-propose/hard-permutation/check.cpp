#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int pre = -1, x;
  int cnt = 0;
  while (cin >> x) {
    if (x != pre) cnt++; pre = x;
  }
  cout << cnt;
}