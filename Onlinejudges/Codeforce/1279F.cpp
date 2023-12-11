#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

#define fi first
#define se second

using ii = pair <int, int>;

const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int a[N], n, k, l, res = inf; ii dp[N];

int cal(int aux) {
    for (int i = 1; i <= n; i++)
        dp[i] = ii(inf, inf);
    dp[0] = ii(0, 0);
    for (int i = 0; i < n; i++) {
        chkmin(dp[i + 1], ii(
        dp[i].fi + a[i], dp[i].se));
        chkmin(dp[min(i + l, n)], ii(
        dp[i].fi + aux, dp[i].se + 1));
    }
    return dp[n].se;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        a[i] = islower(x) > 0;
    }
    int lo = 0, hi = n, aux = 0;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (cal(mi) > k) {
            lo = mi + 1; aux = mi;
        }
        else hi = mi - 1;
    }
    if (cal(aux) <= k) res = 0;
    else {
        cal(aux + 1);
        chkmin(res, dp[n].fi - k * (aux + 1));
    }
    for (int i = 0; i < n; i++) {
        a[i] ^= 1;
    }
    lo = 0, hi = n, aux = 0;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (cal(mi) > k) {
            lo = mi + 1; aux = mi;
        }
        else hi = mi - 1;
    }
    if (cal(aux) <= k) res = 0;
    else {
        cal(aux + 1);
        chkmin(res, dp[n].fi - k * (aux + 1));
    }
    cout << res << '\n';
}