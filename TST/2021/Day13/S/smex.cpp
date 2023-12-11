#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int MOD = 998244353;

int cnt[N], sum[N], val[N];

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        if (val[i] <= n) cnt[val[i]]++;
    }
    int mex = 0, cur = 0;
    while (cnt[mex]) mex++;
    memset(cnt, 0, sizeof cnt);
    sum[0] = 1; sum[1] = -1;
    for (int i = 1, j = 0; i <= n; i++) {
        add(sum[i], sum[i - 1]);
        if (sum[i] >= MOD) sum[i] -= MOD;
        while (j < n && cur < mex) {
            if (val[++j] < mex &&
            cnt[val[j]]++ == 0) cur++;
        }
        j = max(j, i);
        if (cur == mex)
            add(sum[j], sum[i - 1]);
        if (val[i] < mex &&
        --cnt[val[i]] == 0) cur--;
    }
    cout << sum[n] << '\n';
}