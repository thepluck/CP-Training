#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int t = inf.readInt(1, 1000000);
  inf.readEoln();
  int total = 0;
  while (t--) {
    int n = inf.readInt(1, 1000000 - total);
    inf.readEoln();
    total += n;
    string s = inf.readToken("[a-z]{1-1000000}");
    ensuref(int(s.size()) == n, "length of s should equal to n");
    inf.readEoln();
  }
  inf.readEof();
}