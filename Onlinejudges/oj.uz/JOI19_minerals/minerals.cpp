#include "minerals.h"
#include <bits/stdc++.h>


namespace {
    using namespace std;

    const int N = 43005;

    int cost[N], best[N], cur = 0;

    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    void Prepare() {
        cost[1] = 0; best[1] = 1;
        for (int i = 2; i < N; i++) {
            int j = best[i - 1];
            if (cost[i - j - 1] + cost[j + 1] +
            j + 1 < cost[i - j] + cost[j] + j) j++;
            cost[i] = cost[i - j] + cost[j] + j + i - 1;
            best[i] = j;
        }
    }

    void Split(vector<int> x, vector<int> y, bool f) {
        if (x.size() == 1)
            return Answer(x[0], y[0]);
        int n = x.size(), len = best[n];
        vector<int> nx[2], ny[2];
        for (int i = 0; i < len; i++) {
            nx[f ^ 1].push_back(x[i]);
            cur = Query(x[i]);
        }
        for (int i = len; i < n; i++)
            nx[f].push_back(x[i]);
        for (int i = 0; i < n; i++) {
            if (nx[0].size() == ny[0].size())
                ny[1].push_back(y[i]);
            else if (nx[1].size() == ny[1].size())
                ny[0].push_back(y[i]);
            else {
                int nxt = Query(y[i]);
                if (cur != nxt)
                    ny[1].push_back(y[i]);
                else ny[0].push_back(y[i]);
                cur = nxt;
            }
        }
        Split(nx[0], ny[0], 0);
        Split(nx[1], ny[1], 1);
    }
}

void Solve(int n) {
    Prepare(); vector<int> x, y;
    for (int i = 1; i <= 2 * n; i++) {
        
        int nxt = Query(i);
        if (nxt != cur) x.push_back(i);
        else y.push_back(i);
        cur = nxt;
    }
    Split(x, y, 0);
}
