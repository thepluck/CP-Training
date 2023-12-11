#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int a[N], b[N], l[N];
bool used[N];
map<int, int> cnt;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; cnt.clear();
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
      int x; cin >> x; cnt[x]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      used[i] = false;
      if (a[i] < b[i]) {
        flag = false; break;
      }
      l[i] = i - 1;
      while (l[i] && b[l[i]] < b[i])
        l[i] = l[l[i]];
      if (b[i] != b[l[i]] || !used[l[i]]) {
        if (a[i] != b[i]) {
          cnt[b[i]]--; used[i] = true;
        }
        if (cnt[b[i]] < 0) {
          flag = false; break;
        }
      } else used[i] = true;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
}