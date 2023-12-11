#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int per[N], BIT[N], pos[N];
long long tmp[N], sum[N];

void update(int i) {
    for (; i > 0; i -= i & -i) BIT[i]++;
}

int query(int i) {
    int res = 0;
    for (; i < N; i += i & -i) res += BIT[i];
    return res;
}

void solve() {
    int n; cin >> n;
    long long initInv = 0;
    vector <int> mNum, mPos;
    for (int i = 1; i <= n; i++) {
        cin >> per[i];
        if (!per[i]) mPos.push_back(i);
        else {
            pos[per[i]] = i;
            initInv += query(per[i]);
            update(per[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!pos[i]) mNum.push_back(i);
    int mCnt = mPos.size();
    for (int i = 0; i < mCnt; i++)
        tmp[i + 1] = tmp[i] + mPos[i];
    for (int i = 1; i <= n; i++) {
        if (!per[i]) continue;
        int p = lower_bound(mNum.begin(),
        mNum.end(), per[i]) - mNum.begin();
        int q = lower_bound(mPos.begin(),
        mPos.end(), i) - mPos.begin();
        initInv += abs(p - q);
        if (p <= q) {
            sum[1] += 2; sum[p + 1] -= 2;
            sum[mCnt - q + 1] -= 2;
            sum[mCnt - q + p + 1] += 2;
        }
        else {
            sum[p - q + 1] += 2;
            sum[mCnt - q + 1] -= 2;
            sum[p + 1] -= 2;
            sum[mCnt + 1] += 2;
        }
    }
    int rCnt = 0; long long totDif = 0;
    long long res = 1e18;
    for (int i = 1; i <= n; i++) {
        long long cur = initInv + totDif;
        cur += 1ll * rCnt * (mCnt - rCnt);
        int p = lower_bound(mNum.begin(),
        mNum.end(), i) - mNum.begin();
        cur += 1ll * p * (n + 1);
        if (p >= rCnt) {
            cur -= (tmp[p - rCnt]) * 2;
            cur -= (tmp[mCnt] - tmp[mCnt - rCnt]) * 2;
        }
        else {
            int np = (p - rCnt + mCnt) % mCnt;
            cur -= (tmp[np] - tmp[np - p]) * 2;
        }
        res = min(res, cur);
        if (rCnt < mCnt && mNum[rCnt] == i) {
            rCnt++; sum[rCnt] += sum[rCnt - 1];
            initInv += sum[rCnt];
        }
        if (pos[i]) totDif += n + 1 - pos[i] * 2;
    }
    cout << res << '\n';
    for (int i = 0; i <= n + 1; i++)
        BIT[i] = pos[i] = sum[i] = tmp[i] = 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nTest; cin >> nTest;
    while (nTest--) solve();
}