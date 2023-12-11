#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int add(int x, int y, int m) {
    return (x += y) >= m ? x - m : x;
}

int mul(int x, int y, int m) {
    return (long long)x * y % m;
}

int pow(int x, int k, int m) {
    int res = 1;
    for (; k; k >>= 1, x = mul(x, x, m))
        if (k & 1) res = mul(res, x, m);
    return res;
}

void do_add(int &x, int y, int m) {
    x = add(x, y, m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string s; int d, e;
        cin >> s >> d; e = d;
        int l1 = 0, l2 = 0;
        while (d % 2 == 2) {
            d /= 2; l1++;
        }
        while (d % 5 == 0) {
            d /= 5; l2++;
        }
        int tmp = 1, l = max({l1, l2, 1});
        if (l1 < l2) {
            for (int i = 0; i + l1 < l2; i++)
                tmp *= 5;
        } else if (l2 < l1) {
            for (int i = 0; i + l2 < l1; i++)
                tmp *= 2;
        }
        int phi = 0;
        for (int i = 2; i <= d; i++)
            if (__gcd(i, d) == 1) phi++;
        int n = s.size();
        vector<int> cnt(d), dp(l);
        vector<int> pw1(l), pw2(l);
        vector<int> val1(l), val2(l);
        pw2[l - 1] = dp[l - 1] = 1;
        pw1[0] = 10 % d;
        for (int i = 1; i < l; i++)
            pw1[i] = mul(pw1[i - 1], 10, e);
        for (int i = 0; i < n; i++) {
            val1.push_back(add(mul(val1.back(), 10, e), s[i] - '0', e));
            val2.push_back(add(mul(val2.back(), 10, d), s[i] - '0', d));
            pw2.push_back(mul(pw2.back(), 10, d));
            dp.push_back(dp.back());
            for (int j = 1; j <= l; j++) {
                if (mul(val1[l - j], pw1[j - 1], e) == val1[l])
                    do_add(dp[l], dp[l - j], MOD);
            }
            if (i >= l && val2[l] % (e / d) == 0)
                do_add(dp[l], cnt[mul(val2[l] / (e / d), pow(pw2[0], phi, d), d)], MOD);
            do_add(cnt[mul(mul(val2[0], pow(pw2[0], phi, d), d), tmp, d)], dp[0], MOD);
            rotate(dp.begin(), dp.begin() + 1, dp.end());
            rotate(val1.begin(), val1.begin() + 1, val1.end());
            rotate(val2.begin(), val2.begin() + 1, val2.end());
            rotate(pw2.begin(), pw2.begin() + 1, pw2.end());
            dp.pop_back(); val1.pop_back();
            val2.pop_back(); pw2.pop_back();
        }
        cout << "Case #" << tc << ": " << dp.back() << '\n';
    }
}