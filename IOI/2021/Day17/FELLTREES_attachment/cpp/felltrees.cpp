#include "felltrees.h"
#include <bits/stdc++.h>

using namespace std;

namespace {
    struct fenwick_tree {
        vector <int> val; int N;

        fenwick_tree(int N): N(N), val(N + 1) {}

        void add(int i, int v) {
            for (; i > 0; i -= i & -i)
                val[i] += v;
        }

        int get(int i) {
            int res = 0;
            for (; i <= N; i += i & -i)
                res += val[i];
            return res;
        }
    };

    struct query {
        int l, r, idx;

        query(int l, int r, int idx):
        l(l), r(r), idx(idx) {}

        bool operator < (const query &o) const {
            return r < o.r;
        }
    };
}

vector<int> fell_trees(int N, int Q, vector<int> X,
vector<int> H, vector<int> L, vector<int> R) {
    X.insert(X.begin(), X.front());
    H.insert(H.begin(), H.front());
    X.push_back(X.back());
    H.push_back(H.back());
    vector<tuple <int, int, vector<int>>> cur, nxt;
    cur.emplace_back(0, N, vector<int> ());
    for (int i = 1; i <= N; i++)
        get <2> (cur.back()).push_back(i);
    vector <int> A(N + 2), B(N + 2), lef, rig, stk;
    while (cur.size()) {
        nxt.clear();
        for (auto &[l, r, idx] : cur) {
            if (l == r) {
                for (int i : idx) A[i] = l;
                continue;
            }
            int m = (l + r) / 2;
            lef.clear(); rig.clear(); stk.clear();
            stk.push_back(m);
            for (int i : idx) {
                if (i <= m) {
                    lef.push_back(i); continue;
                }
                while (stk.size() > 1 && X[i]
                >= X[stk.back()] + H[stk.back()])
                    stk.pop_back();
                if (X[i] - H[i] >= X[stk.back()])
                    rig.push_back(i);
                else {
                    lef.push_back(i);
                    stk.push_back(i);
                }
            }
            if (lef.size())
                nxt.emplace_back(l, m, lef);
            if (rig.size())
                nxt.emplace_back(m + 1, r, rig);
        }
        cur.swap(nxt);
    }
    cur.emplace_back(1, N + 1, vector<int> ());
    for (int i = N; i > 0; i--)
        get <2> (cur.back()).push_back(i);
    while (cur.size()) {
        nxt.clear();
        for (auto &[l, r, idx] : cur) {
            if (l == r) {
                for (int i : idx) B[i] = l;
                continue;
            }
            int m = (l + r) / 2;
            vector<int> lef, rig, stk;
            stk.push_back(m + 1);
            for (int i : idx) {
                if (i > m) {
                    rig.push_back(i); continue;
                }
                while (stk.size() > 1 && X[i]
                <= X[stk.back()] - H[stk.back()])
                    stk.pop_back();
                if (X[i] + H[i] <= X[stk.back()])
                    lef.push_back(i);
                else {
                    rig.push_back(i);
                    stk.push_back(i);
                }
            }
            if (lef.size())
                nxt.emplace_back(l, m, lef);
            if (rig.size())
                nxt.emplace_back(m + 1, r, rig);
        }
        cur.swap(nxt);
    }
    vector <int> res(Q);
    vector <int> idx(N);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(),
    [&](int i, int j) {return B[i] < B[j];});
    vector <query> que;
    fenwick_tree fenA(N), fenB(N);
    for (int i = 0; i < Q; i++)
        que.emplace_back(L[i] + 1, R[i] + 1, i);
    sort(que.begin(), que.end());
    for (int i = 0, j = 1, k = 0; i < Q; i++) {
        while (j <= que[i].r)
            fenA.add(A[j++], 1);
        while (k < N && B[idx[k]] <= que[i].r) {
            fenA.add(A[idx[k]], -1);
            fenB.add(idx[k++], 1);
        }
        res[que[i].idx] = fenA.get(que[i].l);
        res[que[i].idx] += fenB.get(que[i].l);
    }
    return res;
}
