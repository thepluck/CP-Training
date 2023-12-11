#include "felltrees.h"
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> d;
    BIT(int _n) {
        n = _n;
        d.assign(n + 1, 0);
    }
    void update(int x, int val) {
        assert(0 < x && x <= n);
        for (; x <= n; x += x & -x)
            d[x] += val;
    }
    int get(int x) {
        assert(0 <= x && x <= n);
        int res = 0;
        for (; x > 0; x -= x & -x)
            res += d[x];
        return res;
    }
    int get(int l, int r) {
        assert(0 < l && l <= r && r <= n);
        return get(r) - get(l - 1);
    }
};

void CalcF(int lo, int hi, const vector<int> &a, const vector<int> &x, const vector<int> &h, vector<int> &f) {
    if (a.empty())
        return;
    if (lo == hi) {
        for (int x : a)
            f[x] = lo;
        return;
    }
    vector<int> l, r;
    stack<int> st;
    int mid = lo + (hi - lo + 1) / 2;
    int bound = (mid == 0? 0 : mid - 1);
    st.push(bound);
    for (int ind : a) {
        if (ind < mid) {
            l.push_back(ind);
            continue;
        }
        while (st.size() > 1 && x[st.top()] + h[st.top()] <= x[ind])
            st.pop();
        if (x[ind] - h[ind] >= x[st.top()]) {
            r.push_back(ind);
        } else {
            l.push_back(ind);
            st.push(ind);
        }
    }
    CalcF(lo, mid - 1, l, x, h, f);
    CalcF(mid, hi, r, x, h, f);
}

vector<int> CalcA(const vector<int> &x, const vector<int> &h) {
    vector<int> l(x.size());
    for (int i = 0; i < (int) x.size(); i++)
        l[i] = upper_bound(x.begin(), x.end(), x[i] - h[i]) - x.begin();
    vector<int> f(x.size()), a(x.size());
    iota(a.begin(), a.end(), 0);
    CalcF(-1, x.size() - 1, a, x, h, f);
    return f;
}

vector<int> fell_trees(int n, int q, vector<int> x, vector<int> h, vector<int> l, vector<int> r) {
    vector<int> tmpX = x, tmpH = h;
    vector<int> a = CalcA(x, h);
    for (int i = 0; i < n; i++)
        x[i] = x[n - 1] - x[i];
    reverse(h.begin(), h.end());
    reverse(x.begin(), x.end());
    vector<int> b = CalcA(x, h);
    for (int i = 0; i < n; i++)
        b[i] = n - 1 - b[i];
    reverse(b.begin(), b.end());

    vector<int> res(q, 0);
    vector<vector<int>> rToQueryInd(n), bToPos(n);
    for (int i = 0; i < n; i++)
        if (b[i] < n)
            bToPos[b[i]].push_back(i);
    for (int i = 0; i < q; i++)
        rToQueryInd[r[i]].push_back(i);
    BIT bitA(n), bitB(n);
    for (int i = 0; i < n; i++) {
        if (a[i] > -1)
            bitA.update(a[i] + 1, 1);
        for (int pos : bToPos[i]) {
            if (a[pos] > -1)
                bitA.update(a[pos] + 1, -1);
            bitB.update(pos + 1, 1);
        }
        for (int ind : rToQueryInd[i])
            res[ind] = bitA.get(l[ind] + 1, r[ind] + 1) + bitB.get(l[ind] + 1, r[ind] + 1);
    }
    return res;
}