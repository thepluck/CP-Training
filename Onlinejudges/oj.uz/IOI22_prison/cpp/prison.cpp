#include "prison.h"
#include <bits/stdc++.h>

namespace {
    using namespace std;

    vector<int> base = {3, 3, 3, 3, 3, 2, 2, 1};

    vector<vector<int>> s;

    void gen(int pos, int cur, int l, int r) {
        s[cur][0] = pos & 1;
        s[cur][l] = -1 - (pos & 1);
        s[cur][r] = -2 + (pos & 1);
        if (l + 1 == r) return;
        int nxt = 1;
        for (int i = 0; i < pos; i++)
            nxt += base[i];
        for (int i = 0; i < base[pos]; i++) {
            s[nxt + i][l] = -2 + (pos & 1);
            s[nxt + i][r] = -1 - (pos & 1);
        }
        l++; r--;
        int len = (r - l + 1) / base[pos];
        for (int i = 0; i < base[pos]; i++) {
            for (int k = 0; k < len; k++)
                s[cur][l + k + len * i] = nxt + i;
            for (int j = 0; j < base[pos]; j++)
                if (i == j) gen(pos + 1, nxt + i,
                    l + len * i, l + len * (i + 1) - 1);
                else if (i < j) {
                    for (int k = 0; k < len; k++)
                        s[nxt + i][l + k + len * j] = -1 - (pos & 1);
                } else {
                    for (int k = 0; k < len; k++)
                        s[nxt + i][l + k + len * j] = -2 + (pos & 1);
                }
        }
    }
}

vector<vector<int>> devise_strategy(int n) {
    int m = 2;
    for (int i = 7; i >= 0; i--)
        m = m * base[i] + 2;
    s.resize(21);
    for (int i = 0; i <= 20; i++)
        s[i].resize(m + 1);
    gen(0, 0, 1, m);
    for (int i = 0; i <= 20; i++)
        s[i].resize(n + 1);
    return s;
}
