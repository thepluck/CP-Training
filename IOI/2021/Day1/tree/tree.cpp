#include "tree.h"
#include <bits/stdc++.h>

using namespace std;

double sum[2005][2005];
double cnt[2005][2005];

double count_average_height(int n,
vector <int> dfs, vector <int> bfs) {
    vector <int> num(n), dep(n);
    for (int i = 0; i < n; i++)
        num[--dfs[i]] = i;
    for (int i = 0; i < n; i++)
        dep[num[--bfs[i]]] = i;
    for (int i = 0; i < n; i++)
        num[dep[i]] = i;
    vector <int> cnt(n + 1);
    cnt[0] = 1; cnt[1] = -1;
    int ans = 4;
    for (int i = 0; i + 1 < n; i++) {
        if (num[i] > num[i + 1]) {
            ans += 2;
            cnt[i]++; cnt[i + 1]--;
        }
        if (dep[i] + 1 < dep[i + 1]) {
            cnt[dep[i]]++;
            cnt[dep[i + 1]]--;
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        cnt[i + 1] += cnt[i];
        if (!cnt[i]) ans++;
    }
    return double(ans) / 2;
}