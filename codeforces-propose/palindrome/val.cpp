#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int t = inf.readInt(1, 10'000, "t");
  inf.readEoln();
  int total = 500'000;
  for (int test_case = 1; test_case <= t; test_case++) {
    setTestCase(test_case);
    int n = inf.readInt(1, total, "n");
    inf.readEoln();
    total -= n;
    string s = inf.readToken("[a-z]{1, 500'000}", "s");
    ensuref(int(s.size()) == n, "length of s should equal to n");
    inf.readEoln();
  }
  inf.readEof();
}