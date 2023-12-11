#include <bits/stdc++.h>

using namespace std;

struct wavelet {
    wavelet *lef, *rig;
    vector <int> cnt;
    int low, high;

    wavelet(vector <int> arr, int low, int high):
    low(low), high(high), lef(NULL), rig(NULL) {
        if (arr.empty() || low == high) return;
        cnt.resize(arr.size() + 1);
        int mid = (low + high) / 2;
        vector <int> arrLef, arrRig;
        for (int i = 0; i < arr.size(); i++) {
            cnt[i + 1] = cnt[i];
            if (arr[i] <= mid) {
                cnt[i + 1]++;
                arrLef.push_back(arr[i]);
            }
            else arrRig.push_back(arr[i]);
        }
        lef = new wavelet(arrLef, low, mid);
        rig = new wavelet(arrRig, mid + 1, high);
    }

    int cntLeq(int l, int r, int val) {
        if (l > r || val < low) return 0;
        if (high <= val) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        return lef->cntLeq(lb, rb - 1, val)
        + rig->cntLeq(l - lb, r - rb, val);
    }

    int cntEq(int l, int r, int val) {
        if (l > r) return 0;
        if (low == high) return r - l + 1;
        int lb = cnt[l], rb = cnt[r + 1];
        int mid = (low + high) / 2;
        if (val <= mid)
            return lef->cntEq(lb, rb - 1, val);
        return rig->cntEq(l - lb, r - rb, val);
    }

    int getKth(int l, int r, int k) {
        if (low == high) return low;
        int lb = cnt[l], rb = cnt[r + 1];
        if (k <= rb - lb)
            return lef->getKth(lb, rb - 1, k);
        k -= rb - lb;
        return rig->getKth(l - lb, r - rb, k);
    }
};
