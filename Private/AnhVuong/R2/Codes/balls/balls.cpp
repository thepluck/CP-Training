#include "balls.h"
#include <bits/stdc++.h>

using namespace std;

int count_distinct2(vector <int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}

void play(int n) {
    vector <int> c(n); int cnt = 0;
    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j <= i; j++)
            v.push_back(j);
        if (count_distinct(v) == cnt + 1) {
            c[i] = ++cnt; continue;
        }
        int lo = 0, hi = i - 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            vector <int> x, y;
            for (int j = 0; j <= mi; j++) {
                x.push_back(j);
                y.push_back(c[j]);
            }
            x.push_back(i);
            if (count_distinct(x) ==
            count_distinct2(y)) hi = mi;
            else lo = mi + 1;
        }
        v.clear();
        for (int j = 0; j <= hi; j++)
            v.push_back(j);
        c[i] = count_distinct(v);
    }   
    answer(c);
}