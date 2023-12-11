#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  vector<string> all;
  for (int len = 1; len <= 12; len++)
    for (int mask = 0; mask < (1 << len); mask++) {
      string s(len, 'a');
      for (int i = 0; i < len; i++)
        s[i] += (mask >> i & 1);
      all.push_back(s);
    }
  while (all.size() < 10000)
    all.push_back(rnd.next("[a-z]{13, 15}"));
  cout << all.size() << '\n';
  for (string s : all)
    cout << s.size() << '\n' << s << '\n';
}