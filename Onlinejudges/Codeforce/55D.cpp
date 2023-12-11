
// Problem : D. Beautiful numbers
// Contest : Codeforces - Codeforces Beta Round #51
// URL : https://codeforces.com/problemset/problem/55/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int P = 2520;

int a[P + 5], dgt[20];
ll dp[20][P + 2][50];

ll rec(int i, int m, int g, bool l) {
    if (!i) return m % g == 0;
    if (!l && ~dp[i][m][a[g]])
        return dp[i][m][a[g]];
    int t = l ? dgt[i] : 9;
    ll res = 0;
    for (int d = 0; d <= t; d++)
        res += rec(i - 1, (m * 10 + d) % P, d ?
        g / __gcd(g, d) * d : g, (l && d == t));
    if (!l) dp[i][m][a[g]] = res;
    return res;
}

ll cal(ll x) {
    int i = 0;
    while (x) {
        dgt[++i] = x % 10; x /= 10;
    }
    return rec(i, 0, 1, 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    int t = 0;
    for (int i = 1; i <= P; i++)
        if (P % i == 0) a[i] = ++t;
    cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        cout << cal(r) - cal(l - 1) << '\n';
    }
}