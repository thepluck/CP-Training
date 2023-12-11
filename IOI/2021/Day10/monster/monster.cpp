#include "monster.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int pos[MAXN], tmp[MAXN];
int memo[MAXN][MAXN];

int MyQuery(int x, int y) {
    if (memo[x][y] < 0) {
        memo[x][y] = Query(x, y);
        memo[y][x] = 1 - memo[x][y];
    }
    return memo[x][y];
}

void Sort(int l, int r) {
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    Sort(l, m); Sort(m, r);
    merge(pos + l, pos + m,
    pos + m, pos + r, tmp,
    [&](int x, int y) {
        return !MyQuery(x, y);
    });
    copy(tmp, tmp + r - l, pos + l);
}


vector <int> Solve(int N) {
    iota(pos, pos + N, 0);
    memset(memo, -1, sizeof memo);
    Sort(0, N); int idx1 = 2, ptr = 0;
    while (idx1 < N && MyQuery
    (pos[0], pos[idx1])) idx1++;
    vector <int> ans(N);
    if (idx1 == N) {
        if (MyQuery(pos[N - 1], pos[N - 3])) {
            for (int i = N - 2; i >= 0; i--)
                ans[pos[i]] = ptr++;
            ans[pos[N - 1]] = ptr;
        } else {
            for (int i = N - 1; i >= 0; i--)
                ans[pos[i]] = ptr++;
        }
        return ans;
    }
    if (idx1 == 3) {
        int idx2 = idx1 + 2, pos3;
        while (idx2 < N && MyQuery
        (pos[idx1], pos[idx2])) idx2++;
        if (N == 4) pos3 = 3;
        else {
            if (idx2 == N) pos3 = N - 1;
            else {
                if (MyQuery(pos[1], pos[idx2 - 1])
                || MyQuery(pos[2], pos[idx2 - 1])
                || MyQuery(pos[0], pos[idx2 - 1]))
                    pos3 = idx2 - 1;
                else pos3 = idx2 - 2;
            }
        }
        if (MyQuery(pos[2], pos[pos3])) {
            ans[pos[0]] = 1;
            ans[pos[1]] = 0;
            ans[pos[2]] = 2;
            idx1 = 2;
        } else if (MyQuery(pos[1], pos[pos3])) {
            ans[pos[0]] = 0;
            ans[pos[1]] = 2;
            ans[pos[2]] = 1;
            idx1 = 1;
        } else {
            ans[pos[0]] = 2;
            ans[pos[1]] = 1;
            ans[pos[2]] = 0;
            idx1 = 0;
        }
        ptr = 3;
    } else if (idx1 == 2) {
        int idx2 = 3;
        while (idx2 < N && MyQuery
        (pos[idx2], pos[0])) idx2++;
        if (MyQuery(pos[idx2], pos[1])) {
            ans[pos[1]] = ptr++;
            ans[pos[0]] = ptr++;
        } else ans[pos[0]] = ptr++;
        idx1 = 0;
    } else {
        if (MyQuery(pos[idx1 - 1], pos[1])) {
            for (int i = idx1 - 2; i >= 0; i--)
                ans[pos[i]] = ptr++;
        } else {
            for (int i = idx1 - 1; i >= 0; i--)
                ans[pos[i]] = ptr++;
        }
        idx1 = 0;
    }
    while (ptr < N) {
        int cur = ptr;
        while (cur < N && MyQuery
        (pos[cur], pos[idx1])) cur++;
        idx1 = ptr;
        for (int i = cur; i >= idx1; i--)
            ans[pos[i]] = ptr++;
    }
    return ans;
}
