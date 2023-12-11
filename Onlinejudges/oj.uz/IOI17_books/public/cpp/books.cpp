#include "books.h"
#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const  Y &b) {
    return a > b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

long long minimum_walk(vector<int> p, int s) {
    int n = p.size(), cnt = 0;
    long long res = 0;
    vector<int> idx(n, -1), lef(n), rig(n);
    int min_l = s, max_r = s;
    for (int i = 0; i < n; i++) {
        res += abs(p[i] - i);
        if (idx[i] >= 0) continue;
        lef[cnt] = rig[cnt] = i;
        int j = i;
        while (idx[j] < 0) {
            idx[j] = cnt;
            cmin(lef[cnt], j);
            cmax(rig[cnt], j);
            j = p[j];
        }
        cnt++;
        if (i != p[i]) {
            cmin(min_l, i);
            cmax(max_r, i);
        }
    }
    auto extend = [&](int &l, int &r) {
        int tmp_l = min(lef[idx[l]], lef[idx[r]]);
        int tmp_r = max(rig[idx[l]], rig[idx[r]]);
        while (l > tmp_l || r < tmp_r) {
            if (l > tmp_l)
                cmin(tmp_l, lef[idx[l--]]);
            if (r < tmp_r)
                cmax(tmp_r, rig[idx[r++]]);
        }
    };
    int cur_l = s, cur_r = s;
    extend(cur_l, cur_r);
    for (int i = 0; i < n; i++)
        if (i != p[i]) {
            cmin(min_l, i);
            cmax(max_r, i);
        }
    while (cur_l > min_l || cur_r < max_r) {
        bool flag = false;
        int lef_l = cur_l, lef_r = cur_r;
        int cost_l = 0, cost_r = 0;
        while (lef_l > min_l) {
            extend(--lef_l, lef_r);
            cost_l += 2;
            if (lef_r > cur_r) {
                flag = true; break;
            }
        }
        int rig_l= cur_l, rig_r = cur_r;
        while (rig_r < max_r) {
            extend(rig_l, ++rig_r);
            cost_r += 2;
            if (rig_l < cur_l) break;
        }
        if (!flag) res += cost_l + cost_r;
        else res += min(cost_l, cost_r);
        cur_l = min(lef_l, rig_l);
        cur_r = max(lef_r, rig_r);
    }
    return res;
}
