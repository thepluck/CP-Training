#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  for (char c : s)
    if (!isdigit(c))
      return cout << "NaN\n", 0;
  for (char c : t)
    if (!isdigit(c))
      return cout << "NaN\n", 0;
  cout << stoll(s) - stoll(t) << '\n';
}

