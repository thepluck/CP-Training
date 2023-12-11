#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int LG = 19;

int a[N], b[N], rmq[LG][N], lg[N], ID[N];
long long ans[N], sum[2][N];

int getMin(int l, int r) {
    int k = lg[r - l + 1];
    return a[rmq[k][l]] <
    a[rmq[k][r + 1 - (1 << k)]] ?
    rmq[k][l] : rmq[k][r + 1 - (1 << k)];
}

long long getSum(int prt, int l, int r) {
    return sum[prt][r] - sum[prt][l - 1];
}

void solve(int lef, int rig, long long cur) {
    int mid = getMin(lef, rig);
    ans[ID[mid]] += cur + a[mid];
    for (int l = lef, r = rig;
    l < mid || r > mid; ) {
        int minP = 0;

        if (l < mid) {
            int p = getMin(l, mid - 1);
            if (a[minP] > a[p]) minP = p;
        }
        if (r > mid) {
            int p = getMin(mid + 1, r);
            if (a[minP] > a[p]) minP = p;
        }
        if (minP < mid) {
            ans[ID[mid]] += getSum
            ((minP ^ (r - minP)) & 1, l, minP);
            l = minP + 1;
        }
        else {
            ans[ID[mid]] += getSum
            ((minP ^ (minP - l)) & 1, minP, r);
            r = minP - 1;
        }
    }
    if (lef < mid) solve(lef, mid - 1, cur +
    getSum((mid ^ (mid - lef)) & 1, mid, rig));
    if (mid < rig) solve(mid + 1, rig, cur +
    getSum((mid ^ (rig - mid)) & 1, lef, mid));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, minP = 1; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[minP]) minP = i;
    }
    /// remove minimum
    {
        int m = 0;
        for (int i = minP % n + 1;
        i != minP; i = i % n + 1) {
            b[++m] = a[i]; ID[m] = i;
        }
        ans[minP] = a[minP];
        if (n & 1)
            for (int i = 1; i <= n; i++)
                if (i != minP) ans[i] = a[minP];
        n = m; swap(a, b);
        int l = 1, r = n;
        for (int i = 0; i < n; i++) {
            if (a[l] > a[r]) {
                if (i & 1) ans[minP] += a[l];
                l++;
            }
            else {
                if (i & 1) ans[minP] += a[r];
                r--;
            }
        }
    }
    // prepare
    {
        rmq[0][1] = 1; a[0] = INT_MAX;
        for (int i = 2; i <= n; i++) {
            rmq[0][i] = i; lg[i] = lg[i / 2] + 1;
        }
        for (int k = 1; k < LG; k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                rmq[k][i] = a[rmq[k - 1][i]] <
                a[rmq[k - 1][i + (1 << k - 1)]] ?
                rmq[k - 1][i] : rmq[k - 1][i + (1 << k - 1)];
        for (int i = 1; i <= n; i++) {
            sum[0][i] = sum[0][i - 1];
            sum[1][i] = sum[1][i - 1];
            sum[i & 1][i] += a[i];
        }
    }
    solve(1, n, 0);
    for (int i = 1; i <= n + 1; i++)
        cout << ans[i] << '\n';
}