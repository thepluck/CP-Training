#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int a[N], bit[N], dp[N];
vector <int> pos[N];

int add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    if (x < 0) x += MOD; return x;
}

void updateMax(int i, int v) {
    for (; i < N; i += i & -i)
        bit[i] = max(bit[i], v);
}

void updateSum(int i, int v) {
    for (; i < N; i += i & -i)
        bit[i] = add(bit[i], v);
}

int queryMax(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

int querySum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = add(res, bit[i]);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, lis = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector <int> b(a, a + n);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(),
    b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = upper_bound(b.begin(),
        b.end(), a[i]) - b.begin();
        int cur = queryMax(a[i] - 1);
        pos[cur + 1].push_back(i);
        updateMax(a[i], cur + 1);
        lis = max(lis, cur + 1);
    }
    memset(bit, 0, sizeof bit);
    for (int p : pos[1]) dp[p] = 1;
    for (int l = 2; l <= lis; l++) {
        int j = 0;
        for (int p : pos[l]) {
            while (j < pos[l - 1].size()
            && pos[l - 1][j] < p) {
                int q = pos[l - 1][j++];
                updateSum(a[q], dp[q]);
            }
            dp[p] = querySum(a[p] - 1);
        }
        while (j > 0) {
            j--; int q = pos[l - 1][j];
            updateSum(a[q], -dp[q]);
        }
    }
    int res = 0;
    for (int p : pos[lis])
        res = add(res, dp[p]);
    cout << res << '\n';
}