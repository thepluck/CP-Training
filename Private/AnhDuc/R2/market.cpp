#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

#define fi first
#define se second

using ii = pair <int, int>;
using ll = long long;

vector <int> B;

struct wavelet {
    vector <int> cnt; vector <ll> sum;
    int low, high; wavelet *lef, *rig;

    wavelet(vector <int> arr, int low, int high):
    low(low), high(high), lef(NULL), rig(NULL) {
        if (arr.empty() || low == high) return;
        int mid = (low + high) / 2;
        cnt.resize(arr.size() + 1);
        sum.resize(arr.size() + 1);
        vector <int> arrLef, arrRig;
        for (int i = 0; i < arr.size(); i++) {
            cnt[i + 1] = cnt[i];
            sum[i + 1] = sum[i];
            if (arr[i] <= mid) {
                cnt[i + 1]++;
                sum[i + 1] += B[arr[i]];
                arrLef.push_back(arr[i]);
            }
            else arrRig.push_back(arr[i]);
        }
        lef = new wavelet(arrLef, low, mid);
        rig = new wavelet(arrRig, mid + 1, high);
    }

    ll sumKth(int l, int r, int k) {
        if (low == high) return ll(B[low]) * k;
        int lb = cnt[l - 1], rb = cnt[r];
        if (k <= rb - lb)
            return lef->sumKth(lb + 1, rb, k);
        return rig->sumKth(l - lb, r - rb,
        k - rb + lb) + sum[r] - sum[l - 1];
    }
};

const int MAXN = 100005;
const int MAXK = 20;

int W, H, N, K, M, P[MAXN * 2];
ii A[MAXN]; ll DP[MAXK][MAXN], S[MAXN * 2];

void rec(int p, int l, int r,
int optl, int optr, wavelet &WT) {
    int m = (l + r) / 2, optm;
    for (int i = optl; i <= min(m, optr); i++)
        if (cmin(DP[p][m], DP[p - 1][i - 1] +
        S[2 * m] - S[2 * i - 2] - WT.sumKth
        (2 * i - 1, 2 * m, m - i + 1) * 2))
            optm = i;
    if (l < m) rec(p, l, m - 1, optl, optm, WT);
    if (m < r) rec(p, m + 1, r, optm, optr, WT);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, 0x3f, sizeof DP);
    cin >> W >> H >> N >> K; K = min(N, K);
    for (int i = 1; i <= N; i++)
        cin >> P[i] >> A[i].first;
    for (int i = 1; i <= N; i++)
        cin >> P[i + N] >> A[i].second;
    sort(P + 1, P + N * 2 + 1);
    ll ver = DP[0][0] = 0;
    for (int i = 1; i <= N; i++)
        ver += P[i + N] - P[i];
    sort(A + 1, A + N + 1, [](ii a, ii b) {
        return a.fi + a.se < b.fi + b.se;
    });
    for (int i = 1; i <= N; i++) {
        B.push_back(A[i].fi);
        B.push_back(A[i].se);
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (int i = 1; i <= N; i++) {
        P[2 * i - 2] = lower_bound(B.begin(),
        B.end(), A[i].fi) - B.begin();
        P[2 * i - 1] = lower_bound(B.begin(),
        B.end(), A[i].se) - B.begin();
    }
    for (int i = 1; i <= 2 * N; i++)
        S[i] = S[i - 1] + B[P[i - 1]];
    wavelet WT(vector <int>
    (P, P + N * 2), 0, B.size() - 1);
    for (int i = 1; i <= K; i++)
        rec(i, i, N, i, N, WT);
    cout << ver + DP[K][N] << '\n';
}