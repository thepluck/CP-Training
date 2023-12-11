#include "bracket.h"
#include <bits/stdc++.h>

using namespace std;

  const int maxn = 1e6 + 10;
  typedef long long ll;

  char str[maxn];
  ll val[maxn];

  vector<int> e[maxn];

  void init(int n) {
    int top = 0;
    int now = 0;
    for (int i = 1; i <= n * 2; i++) {
      if (str[i] == '(')
        top++, ++now, e[top].push_back(now);
      else
        top--;
    }
  }

  long long minimum_cost(int n, int X, int Y, string S, vector<int> W) {
    for (int i = 0; i < 2 * n; i++)
      str[i + 1] = S[i];
    for (int i = 1; i <= n; i++)
      val[i] = W[i - 1];
    init(n);
    if (!X && !Y) return 0;
    else if (!X && Y) {
      multiset < ll, greater < ll >> now;
      ll sum = 0, res = 0;
      for (int i = 1; i <= n; i++) {
        for (int x: e[i])
          sum += val[x], now.insert(val[x]);
        if (now.size())
          sum -= * now.begin(), now.erase(now.begin());
        res += sum;
      }
      return res;
    } else if (X && Y) {
      ll res = 0;
      multiset < ll, greater < ll >> now;
      ll sum = 0;
      for (int i = 1; i <= n; i++) {
        for (int x: e[i])
          sum += val[x], now.insert(val[x]);
        if (now.size() > 1)
          res += sum + (now.size() - 2) * * now.rbegin();
        if (now.size())
          sum -= * now.begin(), now.erase(now.begin());
      }
      return res;
    } else {
      ll ans = 8e18;
      {
        ll res = 0, sum = 0;
        multiset < ll, greater < ll >> now;
        for (int i = 1; i <= n; i++) {
          for (int x: e[i])
            sum += val[x], now.insert(val[x]);
          if (now.size() > 2) {
            auto pos = next(now.begin());
            res += (now.size() - 2) * * now.rbegin() + * pos;
            now.erase(pos);
            continue;
          }
          if (now.size() > 1)
            res += (now.size() - 2) * * now.rbegin() + * now.rbegin();
          if (now.size())
            now.erase(--now.end());
        }
        ans = min(ans, res);
      } 
      {
        ll res = 0, sum = 0;
        multiset < ll, greater < ll >> now;
        for (int i = 1; i <= n; i++) {
          for (int x: e[i])
            sum += val[x], now.insert(val[x]);
          if (now.size() > 2) {
            auto pos = next(now.begin());
            res += (now.size() - 2) * * now.rbegin() + * pos;
            now.erase(pos);
            continue;
          }
          if (now.size() > 1 && e[i + 1].empty()) {
            res += (now.size() - 2) * * now.rbegin() + * now.rbegin();
            now.erase(--now.end());
            continue;
          }
          if (now.size() > 1)
            res += (now.size() - 2) * * now.rbegin() + * now.begin();
          if (now.size())
            now.erase(now.begin());
        }
        ans = min(ans, res);
      }
      return ans;
    }
  }