#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b, string c, string ope) {
  if (ope == "+") return stoll(a) + stoll(b) == stoll(c);
  if (ope == "*") return stoll(a) * stoll(b) == stoll(c);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, ope, b, eq, c;
  cin >> a >> ope >> b >> eq >> c;
  for (int i = 1; i < a.size(); i++)
    for (int j = 1; j < b.size(); j++) {
      string x = b.substr(0, j) + a.substr(i);
      string y = a.substr(0, i) + b.substr(j);
      if (check(x, y, c, ope)) {
        cout << x << ' ' << ope << ' ' << y << " = " << c << '\n';
      }
    }
  for (int i = 1; i < a.size(); i++)
    for (int j = 1; j < c.size(); j++) {
      string x = c.substr(0, j) + a.substr(i);
      string y = a.substr(0, i) + c.substr(j);
      if (check(x, b, y, ope)) {
        cout << x << ' ' << ope << ' ' << b << " = " << y << '\n';
      }
    }
  for (int i = 1; i < b.size(); i++)
    for (int j = 1; j < c.size(); j++) {
      string x = c.substr(0, j) + b.substr(i);
      string y = b.substr(0, i) + c.substr(j);
      if (check(a, x, y, ope)) {
        cout << a << ' ' << ope << ' ' << x << " = " << y << '\n';
      }
    }
}