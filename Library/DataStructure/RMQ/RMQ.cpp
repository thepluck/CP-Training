#include <bits/stdc++.h>

using namespace std;

struct RMQ {
    static const int LG = 17;

    vector <int> mi[LG], ma[LG];
 
    RMQ(const vector <int> &a) {
        int n = a.size();
        mi[0] = ma[0] = a;
        for (int k = 1; k < LG; k++) {
            mi[k].resize(n); ma[k].resize(n);
            for (int i = 0; i + (1 << k) <= n; i++) {
                mi[k][i] = min(mi[k - 1][i],
                mi[k - 1][i + (1 << (k - 1))]);
                ma[k][i] = max(ma[k - 1][i],
                ma[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
 
    int getMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(mi[k][l],
        mi[k][r + 1 - (1 << k)]);
    }
 
    int getMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(ma[k][l],
        ma[k][r + 1 - (1 << k)]);
    }
};