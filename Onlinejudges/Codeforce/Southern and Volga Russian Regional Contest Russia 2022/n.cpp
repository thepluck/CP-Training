#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int nxt[N][10];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    for (char &c : s) c -= '0';
    int n = s.size();
    for (int c = 0; c < 10; c++)
      nxt[n][c] = n;
    for (int i = n - 1; i >= 0; i--) {
      for (int c = 0; c < 10; c++)
        nxt[i][c] = nxt[i + 1][c];
      nxt[i][s[i]] = i;
    }
    int k; cin >> k;
    int i = 0;
    while (k < s.size() - i) {
      for (int c = (i == 0); c < 10; c++)
        if (nxt[i][c] <= i + k) {
          cout << c;
          k -= nxt[i][c] - i;
          i = nxt[i][c] + 1;
          break;
        }
    }
    cout << '\n';
  }
}