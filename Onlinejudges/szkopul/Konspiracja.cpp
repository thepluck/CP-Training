#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int deg[N], cnt[N], val[N];

int getC(int n, int k) {
    k = min(k, n - k);
    int res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - k + i) / i;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i]; int u;
        for (int j = 0; j < deg[i]; j++) cin >> u;
        cnt[deg[i]]++;
    }
    for (int i = n - 1; i >= 0; i--)
        cnt[i] += cnt[i + 1];
    for (int i = 1; i <= n; i++)
        val[cnt[deg[i]]--] = deg[i];
    int tot = 0, cur = 0, sum = 0, res = 0;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        cnt[val[i]]++; tot += val[i];
    }
    for (int i = 1; i < n; i++) {
        sum += val[i];
        if (val[i] != val[i - 1]) cur = 1;
        else cur++;
        if (sum * 2 == i * (i - 1) + tot)
            res += getC(cnt[val[i]], cur);
    }
    cout << res << '\n';
}