#include "inversion.h"
#include <bits/stdc++.h>

using namespace std;

int N, count_ask = 0, init;
vector<int> A;

void wa() {
  cout << "WA\n"; exit(0);
}

void ok() {
  cout << "OK\n"; exit(0);
}

int count_inv() {
  int inv = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      inv += A[i] > A[j];
  return inv;
}

int count_inv(int i, int j) {
  count_ask++;
  if (count_ask > 10000) wa();
  if (i < 0 || i >= N) wa();
  if (j < 0 || j >= N) wa();
  if (i > j) swap(i, j);
  if (i == j) return init;
  for (int k = i + 1; k < j; k++) {
    if (A[k] < A[i] && A[k] > A[j]) init -= 2;
    if (A[k] > A[i] && A[k] < A[j]) init += 2;
  }
  if (A[i] > A[j]) init--;
  else init++;
  swap(A[i], A[j]);
  return init;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  vector<int> C = A;
  init = count_inv();
  vector<int> B = guess_perm(N, init);
  if (C != B) wa();
  ok();
}