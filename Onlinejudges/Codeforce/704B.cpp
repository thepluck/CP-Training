
// Problem : B. Ant Man
// Contest : Codeforces - Codeforces Round #366 (Div. 1)
// URL : https://codeforces.com/contest/704/problem/B
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 5005;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dp[2][N]; int n, s, t;
int x[N], a[N], b[N], c[N], d[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> t;
    auto input = [](int &x) {cin >> x;};
    for_each(x + 1, x + n + 1, input);
    for_each(a + 1, a + n + 1, input);
    for_each(b + 1, b + n + 1, input);
    for_each(c + 1, c + n + 1, input);
    for_each(d + 1, d + n + 1, input);
    memset(dp[0], 0x3f, sizeof dp[0]);
    dp[0][0] = 0; ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        memset(dp[i & 1], 0x3f, sizeof dp[i & 1]);
        for (int j = 0; j < i; j++) {
            ll val = dp[~i & 1][j];
            if (val == inf) continue;
            if (i == s) {
                cmin(dp[i & 1][j], val - x[i] + d[i]);
                if (j)
                    cmin(dp[i & 1][j - 1], val + x[i] + c[i]);
                else if (i == n)
                    cmin(ans, val + x[i] + c[i]);
            }
            else if (i == t) {
                cmin(dp[i & 1][j], val - x[i] + b[i]);
                if (j)
                    cmin(dp[i & 1][j - 1], val + x[i] + a[i]);
                else if (i == n)
                    cmin(ans, val + x[i] + a[i]);
            }
            else {
                if (i > s || j)
                    cmin(dp[i & 1][j], val + a[i] + d[i]);
                if (i > t || j)
                    cmin(dp[i & 1][j], val + b[i] + c[i]);
                if (j + (i > s) + (i > t) > 1) {
                    if (j)
                        cmin(dp[i & 1][j - 1], val + x[i] * 2 + a[i] + c[i]);
                    else if (i == n)
                        cmin(ans, val + x[i] * 2 + a[i] + c[i]);
                }
                cmin(dp[i & 1][j + 1], val - x[i] * 2 + b[i] + d[i]); 
            }
        }
    }
    cout << ans << '\n';
}