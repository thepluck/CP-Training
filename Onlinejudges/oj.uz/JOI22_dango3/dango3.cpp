#include "dango3.h"
#include <vector>
#include <iostream>

namespace {
    using namespace std;
}

void Solve(int n, int m) {
    vector<vector<int>> a(m);
    vector<char> v(n * m + 1);
    for (int i = 1; i <= n * m; i++) {
        int lo = 0, hi = m - 1;
        while (a[lo].size() == n) lo++;
        while (hi && a[hi - 1].empty()) hi--;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            fill(v.begin(), v.end(), 0);
            for (int j : a[mi])
                v[j] = true;
            v[i] = true;
            vector<int> b;
            for (int j = 1; j <= n * m; j++)
                if (!v[j]) b.push_back(j);
            if (m == Query(b) + 1) hi = mi;
            else lo = mi + 1;
        }
        a[hi].push_back(i);
    }
    for (int i = 0; i < m; i++)
        Answer(a[i]);
}
