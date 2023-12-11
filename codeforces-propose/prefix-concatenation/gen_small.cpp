#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> all;

void gen(int i, int len, string s) {
  if (i == len) {
    all.push_back(s); return;
  }
  for (int j = 0; j < len; j++)
    gen(i + 1, len, s + char('a' + j));
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  string type = opt<string> ("type");
  if (type == "13") {
    for (char c = 'a'; c <= 'z'; c++)
      all.emplace_back(string(1, c));
    for (char c1 = 'a'; c1 <= 'z'; c1++)
      for (char c2 = 'a'; c2 <= 'z'; c2++)
        all.emplace_back(string(1, c1) + c2);
    for (char c1 = 'a'; c1 <= 'z'; c1++)
      for (char c2 = 'a'; c2 <= 'z'; c2++)
        for (char c3 = 'a'; c3 <= 'z'; c3++)
          all.emplace_back(string(1, c1) + c2 + c3);
    cout << all.size() << '\n';
    for (string s : all)
      cout << s.size() << '\n' << s << '\n';
  } else {
    for (int len = 4; len <= 6; len++)
      gen(0, len, "");
    cout << all.size() << '\n';
    for (string s : all)
      cout << s.size() << '\n' << s << '\n';
  }
}