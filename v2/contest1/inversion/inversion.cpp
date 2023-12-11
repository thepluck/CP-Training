#include "inversion.h"

#include <bits/stdc++.h>


using namespace std;

const int N = 5005;

int BIT[N], pos[N];

void update(int i, int v) {
  for (i++; i < N; i += i & -i) BIT[i] += v;
}

int getPos(int k) {
  int p = 0;
  for (int i = 1 << 17; i > 0; i >>= 1)
    if (p + i < N && BIT[p + i] < k) {
      p += i;
      k -= BIT[p];
    }
  return p;
}

int inversion(int i, int j) {
  swap(pos[i], pos[j]);
  return count_inv(i, j);
}

vector<int> guess_perm(int n, int init) {
  for (int i = 0; i < n; i++) {
    pos[i] = i; update(i, 1);
  }
  int minId = 0;
  for (int i = 1; i < n; i++) {
    int curr = inversion(minId, i);
    if (curr > init) minId = i;
    init = curr;
  }
  vector<int> ans(n);
  ans[pos[minId]] = 0;
  update(0, -1);
  if (minId > 0) init = inversion(0, minId);
  bool side = 1;
  int low = 0, high = n - 1;
  while (low < high) {
    int curr = inversion(low, high);
    int dif = abs(curr - init) / 2;
    int val = getPos(dif + 1);
    if (side) {
      ans[pos[low]] = val;
      low++;
    } else {
      ans[pos[high]] = val;
      high--;
    }
    update(val, -1);
    side ^= 1;
    init = curr;
  }
  return ans;
}