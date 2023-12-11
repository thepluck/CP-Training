#include <bits/stdc++.h>
#include "permutation.h"

using namespace std;

const int MAXN = 300;

int val[MAXN], N;
bool mark[MAXN];

void rotate1(vector <int> mis,
vector <int> &per) {
    int ptr = 0, K = mis.size();
    for (int i = 0; i < N; i++)
        if (!val[i])
            per[i] = mis[++ptr % K];
        else per[i] = val[i];
}

void rotate2(vector <int> mis,
vector <int> &per, int cnt) {
    per[0] = mis[0];
    int ptr = 0, K = mis.size();
    for (int i = 1; i < N; i++)
        if (!val[i]) {
            if (ptr < cnt) {
                if (++ptr == cnt)
                    per[i] = val[0];
                else per[i] = mis[ptr % K];
            } else per[i] = mis[ptr++];
        } else per[i] = val[i];
}

void lock(vector <int> tmp,
vector <int> &mis, vector <int> &per) {
    rotate1(mis, per);
    for (int i : tmp)
        mark[mis[i]] = true;
    for (int i = 0; i < N; i++)
        if (!val[i] && mark[per[i]])
            val[i] = per[i];
    for (int i : tmp)
        mark[mis[i]] = false;
    mis.clear();
    for (int i = 0; i < N; i++) {
        if (!val[i])
            mis.push_back(per[i]);
    }
}

void solve(int N) {
    vector <int> per(::N = N);
    iota(per.begin(), per.end(), 1);
    int idx[] = {-1, -1};
    for (int i = 0; i < N; i++) {
        swap(per[i], per[0]);
        val[i] = query(per);
        if (val[i] == N) return;
        swap(per[i], per[0]);
        if (abs(val[i] - val[0]) == 2)
            break;
    }
    bool two = false;
    for (int i = 1; i < N; i++)
        if (val[i] - val[0] == 2) {
            swap(per[i], per[0]);
            two = true;
        } else if (val[0] - val[i] == -2)
            two = true;
    if (!two) {
        for (int i = 1; i < N; i++)
            if (val[i] - val[0] == 1)
                idx[idx[0] >= 0] = i;
        if (idx[1] >= 0) {
            vector <int> tmp, ans;
            tmp.push_back(1);
            tmp.push_back(idx[0] + 1);
            tmp.push_back(idx[1] + 1);
            sort(tmp.begin(), tmp.end());
            int cur = -1;
            do {
                per[0] = tmp[0];
                per[idx[0]] = tmp[1];
                per[idx[1]] = tmp[2];
                int nxt = query(per);
                if (nxt == N) return;
                if (nxt > cur) {
                    cur = nxt; ans = tmp;
                }
            } while (next_permutation
            (tmp.begin(), tmp.end()));
            per[0] = ans[0];
            per[idx[0]] = ans[1];
            per[idx[1]] = ans[2];
        } else if (idx[0] >= 0)
            swap(per[idx[0]], per[0]);
    }
    memset(val, 0, sizeof val);
    int cur = query(per);
    if (cur == N) return;
    val[0] = per[0];
    vector <int> mis;
    for (int i = 1; i < N; i++) {
        swap(per[i], per[0]);
        int nxt = query(per);
        if (nxt == N) return;
        if (cur - nxt == 2)
            val[i] = per[0];
        else mis.push_back(per[0]);
        swap(per[i], per[0]);
    }
    while (mis.size()) {
        rotate1(mis, per);
        int dif = query(per) - cur, ptr = 1;
        if (cur + dif == N) return;
        vector <int> tmp;
        for (int t = 0; t < dif; t++) {
            int lo = ptr + 1, hi = mis.size();
            ptr = 1;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                rotate2(mis, per, mi);
                int nxt = query(per);
                if (nxt == N) return;
                if (nxt >= cur + t) {
                    ptr = mi; hi = mi - 1;
                } else lo = mi + 1;
            }
            tmp.push_back(ptr - 1);
        }
        cur += dif; lock(tmp, mis, per);
    }
}