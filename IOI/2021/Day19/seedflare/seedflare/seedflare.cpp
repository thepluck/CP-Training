#include "seedflare.h"
#include <bits/stdc++.h>

using namespace std;

/// A B C A B C B A C B A

void three(vector<int> &que, int A, int B, int C) {
    que.push_back(A); que.push_back(B);
    que.push_back(C); que.push_back(A);
    que.push_back(B); que.push_back(C);
    que.push_back(B); que.push_back(A);
    que.push_back(C); que.push_back(B);
    que.push_back(A);
}

vector<int> SortFlowers(int N) {
    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 1);
    if (N == 1) return ans;
    while (N >= 3) {
        vector<int> que;
        if (N % 3 == 1) {
            que.push_back(ans[0]);
            for (int i = 1; i + 3 <= N; i += 3)
                three(que, ans[i], ans[i + 1], ans[i + 2]); 
        } else if (N % 3 == 2) {
            three(que, ans[0], ans[1], ans[2]);
            for (int i = 2; i + 3 <= N; i += 3)
                three(que, ans[i], ans[i + 1], ans[i + 2]); 
        } else {
            for (int i = 0; i + 3 <= N; i += 3)
                three(que, ans[i], ans[i + 1], ans[i + 2]); 
        }
        int pos = SeedFlare(que);
        auto it = find(ans.begin(), ans.begin() + N, pos);
        if (next(it) != ans.end())
            rotate(ans.begin(), next(it), ans.begin() + N);
        N--;
    }
    vector<int> que({ans[0], ans[1]});
    if (SeedFlare(que)) swap(ans[0], ans[1]);
    return ans;
}
