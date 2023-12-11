#include <bits/stdc++.h>
#include "library.h"

namespace {
    using namespace std;
    
    const int N = 1005;

    bool vis[N];
}

void Solve(int n) {
    vector<int> ans;
    int lo = 2, hi = n;
    if (n == 1) {
        Answer(vector<int> (1, 1));
        return;
    }
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        vector<int> bit(n);
        for (int i = 2; i <= mi; i++)
            bit[i - 1] = 1;
        int tmp = Query(bit); bit[0] = 1;
        if (Query(bit) > tmp) lo = mi + 1;
        else hi = mi;
    }
    ans.push_back(hi);
    ans.push_back(1);
    vis[1] = vis[hi] = 1;
    while (true) {
        vector<int> alive;
        for (int i = 1; i <= n; i++)
            if (!vis[i]) alive.push_back(i);
        lo = 0; hi = alive.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            vector<int> bit(n);
            for (int i = 0; i <= mi; i++)
                bit[alive[i] - 1] = 1;
            int tmp = Query(bit);
            bit[ans.back() - 1] = 1;
            if (Query(bit) > tmp) lo = mi + 1;
            else hi = mi;
        } 
        if (hi < alive.size()) {
            ans.push_back(alive[hi]);
            vis[alive[hi]] = 1;
        } else break;
    }
    reverse(ans.begin(), ans.end());
    while (true) {
        vector<int> alive;
        for (int i = 1; i <= n; i++)
            if (!vis[i]) alive.push_back(i);
        lo = 0; hi = alive.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            vector<int> bit(n);
            for (int i = 0; i <= mi; i++)
                bit[alive[i] - 1] = 1;
            int tmp = Query(bit);
            bit[ans.back() - 1] = 1;
            if (Query(bit) > tmp) lo = mi + 1;
            else hi = mi;
        } 
        if (hi < alive.size()) {
            ans.push_back(alive[hi]);
            vis[alive[hi]] = 1;
        } else break;
    }
    Answer(ans);
}
