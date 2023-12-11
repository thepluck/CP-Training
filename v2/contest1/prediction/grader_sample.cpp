#include "prediction.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int L, N, M;
  cin >> L >> N >> M;
  vector<int> C(M), T(M), X(M), Y(M);
  for (int i = 0; i < M; i++)
    cin >> C[i] >> T[i] >> X[i] >> Y[i];
  vector<int> alive = count_alive(L, N, M, C, T, X, Y);
  for (int x : alive) cout << x << '\n';
}