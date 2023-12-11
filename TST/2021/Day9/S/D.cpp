#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

const ll K = 3e18 + 5;

ll dp[4505][4505];

ll calc(int cnt, int len) {
    if (cnt <= 0) return cnt == 0;
    ll &res = dp[cnt][len];
    if (res != ULLONG_MAX) return res;
    res = 0;
    for (int i = 0; i < 25; i++) {
        res += calc(cnt - 1, 1);
        if (res >= K) res = K;
    }
    res += calc(cnt - len - 1, len + 1);
    if (res >= K) res = K;
    return res;
}

int main() {
    freopen("conststr.inp", "r", stdin);
    freopen("conststr.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    for (int tc = 0; tc < 3; tc++) {
        int n; ll k; cin >> n >> k;
        string s; int cur = 0, len = 1;
        while (len * (len + 1) / 2 + 14 <= n) len++;
        n -= len * (len - 1) / 2; len--;
        for (int i = 1; i <= len; i++) s += 'a';
        while (n > 0) {
            for (int c = 0; c < 26; c++)
                if (c != cur) {
                    ll tmp = calc(n - 1, 1);
                    if (tmp >= k) {
                        s += char(c + 'a');
                        n--; cur = c; len = 1; break;
                    }
                    else k -= tmp;
                }
                else {
                    ll tmp = calc(n - len - 1, len + 1);
                    if (tmp >= k) {
                        s += char(c + 'a');
                        n -= ++len; break;
                    }
                    else k -= tmp;
                }
        }
        cout << s << '\n';
    }
}