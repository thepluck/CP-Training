#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  int turn = 0;
  string s;
  while (cin >> s) {
    if (s == "P") turn++;
    else if (s == "2P") turn += 2;
    else if (s == "3P") turn += 3;
    else if (s == "T") turn--;
    else if (s == "2T") turn -= 2;
    else turn -= 3;
  }
  turn = (turn % 4 + 4) % 4;
  while (turn--) {
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        b[i][j] = a[n - j - 1][i];
    swap(n, m); a = b;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cout << a[i][j] << " \n"[j == m - 1];
}