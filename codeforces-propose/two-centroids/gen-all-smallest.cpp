#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

/// 8! / 5
const int TSIZE = 8064;

vector<vector<int>> trees;

void rec(int n, int i, vector<int> tree) {
  if (i == n - 1) {
    trees.push_back(tree); return;
  }
  for (int j = 0; j <= i; j++) {
    vector<int> new_tree = tree;
    new_tree.push_back(j + 1);
    rec(n, i + 1, new_tree);
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int start = opt<int> ("start");
  if (start == 0) {
    for (int n = 2; n <= 8; n++)
      rec(n, 0, vector<int> ());
    int rem = 10000 - trees.size();
    cout << 10000 << '\n';
    for (int i = 0; i < trees.size(); i++) {
      cout << trees[i].size() + 1 << '\n';
      for (int j = 0; j < trees[i].size(); j++)
        cout << trees[i][j] << " \n"[j == trees[i].size() - 1];
    }
    for (int i = 0; i < rem; i++) {
      cout << 10 << '\n';
      for (int j = 0; j < 9; j++)
        cout << rnd.next(1, j + 1) << " \n"[j == 8];
    }
  } else {
    start = (start - 1) * TSIZE;
    rec(9, 0, vector<int> ());
    int rem = 10000 - TSIZE;
    cout << 10000 << '\n';
    for (int i = start; i < start + TSIZE; i++) {
      cout << 9 << '\n';
      for (int j = 0; j < 8; j++)
        cout << trees[i][j] << " \n"[j == 7];
    }
    for (int i = 0; i < rem; i++) {
      cout << 10 << '\n';
      for (int j = 0; j < 9; j++)
        cout << rnd.next(1, j + 1) << " \n"[j == 8];
    }
  }
}