#include "guessnum.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int Min[N], Max[N], BIT[N];

struct query {
    int x, y, t;

    bool operator < (const query &o) const {
        return x != o.x ? x < o.x : t < o.t;
    }
};

void update(int i) {
    for (; i < N; i += i & -i) BIT[i]++;
}

int getSum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += BIT[i];
    return res;
}

long long count_pair(int n) {
  if (n == 1) return 1;
  if (n == 2) return 3;
  if (n == 3) return 4;
  if (n == 4) return 6;
  long long res = 0;
  vector <query> que;
  for (int i = 1; i <= n; i++) {
    if (n - i >= i)
      Min[i] = (n - i - 1) / ((n - i) / i) + 1;
    else Min[i] = N;
    Max[i] = (n - i) / ((n - i - 1) / i + 1);
    BIT[i] = 0;
  }
  Min[n] = Max[n] = n; Max[n + 1] = N;
  for (int i = 1; i <= n; i++) {
    que.push_back({i, max(Min[i], Min[i - 1]), 0});
    que.push_back({min(Max[i], Max[i + 1]), i, 1});
  }
  sort(que.begin(), que.end());   
  for (auto q : que) {
    if (q.t == 0) update(q.y);
    else res += getSum(q.y);
  }
  return res;
}