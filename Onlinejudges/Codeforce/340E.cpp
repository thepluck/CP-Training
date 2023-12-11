#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2005;
const int MOD = 1e9 + 7;

bool occ[N];
int arr[N], fac[N], inv[N], dp[N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD; return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD; return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int C(int n, int k) {
    return mmul(fac[n], mmul(inv[k], inv[n - k]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - mmul(MOD / i, inv[MOD % i]);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] >= 0) occ[arr[i]] = 1;
        fac[i] = mmul(fac[i - 1], i);
        inv[i] = mmul(inv[i - 1], inv[i]);
    }
    int fix = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] < 0 && !occ[i]) fix++;
        if (arr[i] < 0) tot++;
    }
    for (int i = fix; i >= 0; i--) {
        dp[i] = mmul(C(fix, i), fac[tot - i]);
        for (int j = i + 1; j <= fix; j++)
            dp[i] = msub(dp[i], mmul(dp[j], C(j, i)));
    }
    cout << dp[0] << '\n';
}