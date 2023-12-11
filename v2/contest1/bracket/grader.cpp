#include "bracket.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, P, Q; string S;
  cin >> N >> P >> Q >> S;
  vector<int> W(N);
  for (int &x : W) cin >> x;
  cout << minimum_cost(N, P, Q, S, W) << '\n';
}