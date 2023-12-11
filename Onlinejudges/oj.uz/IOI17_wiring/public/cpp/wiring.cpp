#include "wiring.h"
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

long long min_total_length
(vector <int> R, vector<int> B) {
    vector <pair <int, int>> P;
    int N = R.size(), M = B.size();
    for (int i = 0, j = 0; i < N || j < M; ) {
        if (i < N && j < M) {
            if (R[i] < B[j])
                P.emplace_back(R[i++], 0);
            else P.emplace_back(B[j++], 1);
        } else if (i < N) {
            P.emplace_back(R[i++], 0);
        } else {
            P.emplace_back(B[j++], 1);
        }
    }
    vector <long long> S(N + M + 1), cur, nxt;
    for (int i = 0; i + 1 < N + M; i++)
        if (P[i].se != P[i + 1].se) {
            cur.assign(i + 2, 1e18); break;
        }
    cur.back() = 0;
    for (int i = 0; i < N + M; i++)
        S[i + 1] = S[i] + P[i].fi;

    /// Sort and split the set of points into disjoint groups
    /// cur[l]: current group has l right-most unpaired points
    /// nxt[l]: next group ... and all points of current group were paired
    /// transtion:
    /// 1. pair the left-most unpaired point of current group with left-most point of next group
    /// 2. pair l unpaired point of current groups with l left-most points of next group
    /// 3. Here all points of current groups were paired:
    /// pair the left-most unpaired point of next group with right-most point of current group
    /// complexity: O(N + M)
    for (int i = 0; i + 1 < N + M; i++)
        if (P[i].se != P[i + 1].se) {
            int j = i + 1;
            while (j < N + M && P[j].se != P[i].se) j++;
            nxt.assign(j - i, 1e18);
            for (int l = cur.size() - 1; l > 0; l--)
                cmin(cur[l - 1], cur[l] + P[i + 1].fi - P[i - l + 1].fi);
            for (int l = min(int(cur.size()), j - i) - 1; l >= 0; l--)
                cmin(nxt[j - i - 1 - l], cur[l] + S[i + l + 1] + S[i - l + 1] - S[i + 1] * 2);
            for (int l = j - i - 1; l > 0; l--)
                cmin(nxt[l - 1], nxt[l] + P[j - l].fi - P[i].fi);
            cur.swap(nxt);
        }
    return cur[0];
}
