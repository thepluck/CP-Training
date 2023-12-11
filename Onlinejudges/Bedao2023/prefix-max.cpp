#include <bits/stdc++.h>
 
using namespace std;
 
template <class X, class Y>
bool cmax(X &a, const Y &b) {
  return a < b ? a = b, 1 : 0;
}
 
using ii = pair<int, int>;
 
const int N = 1000005;
 
ii bit[2][N], dp[N][2];
char ans[N]; int a[N];
 
void update(int id, int i, ii v) {
  for (; i < N; i += i & -i)
    cmax(bit[id][i], v);
}
 
ii get(int id, int i) {
  ii res(-1e9, 0);
  for (; i > 0; i -= i & -i)
    cmax(res, bit[id][i]);
  return res;
}
 
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    bit[0][i] = {0, 0};
    bit[1][i] = {-1e9, 0};
    ans[i] = 0;
  }
  vector<int> rar;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; rar.push_back(a[i]);
  }
  sort(rar.begin(), rar.end());
  rar.erase(unique(rar.begin(), rar.end()), rar.end());
  int pmax = 0, cntp = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = upper_bound(rar.begin(), rar.end(), a[i]) - rar.begin();
    for (int j = 0; j < 2; j++) {
      dp[i][j] = get(j ^ 1 ^ (a[i] > pmax), a[i]);
      dp[i][j].first += 1 + (a[i] > pmax);
    }
    for (int j = 0; j < 2; j++)
      update(j, a[i], make_pair(dp[i][j].first, i));
    if (a[i] > pmax) {
      pmax = a[i]; cntp++; ans[i] = 'M';
    }
  }
  for (int i = 1; i <= n; i++)
    if (dp[i][cntp & 1].first >= cntp) {
      cout << "YES\n";
      vector<int> one, two;
      int need = dp[i][cntp & 1].first - cntp;
      while (i > 0) {
        if (ans[i]) {
          if (cntp > 1) {
            ans[i] = 'D'; cntp -= 2;
          }
          i = dp[i][cntp & 1].second;
        } else {
          if (cntp > 0) {
            ans[i] = 'D';
          }
          i = dp[i][cntp & 1].second;
          cntp--;
        }
      }
      pmax = 0;
      for (i = 1; i <= n; i++) {
        if (!ans[i]) {
          if (pmax > a[i])
            ans[i] = 'M';
          else ans[i] = 'D';
        } else if (ans[i] == 'M')
          pmax = a[i];
        cout << ans[i];
      }
      cout << '\n'; return;
    }
  cout << "NO\n";
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
