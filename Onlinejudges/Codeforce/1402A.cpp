
// Problem : A. Fancy Fence
// Contest : Codeforces - Central-European Olympiad in Informatics, CEOI 2020, Day 1 (IOI, Unofficial Mirror Contest, Unrated)
// URL : https://codeforces.com/problemset/problem/1402/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ll = long long;
using pll = pair <ll, ll>;

const int N = 1e5 + 5;
const int MOD = 1000000007;
const int DIV = 250000002;

pll rec[N];

ll cal(ll n, ll m) {
    return n * (n + 1) % MOD * m % MOD
            * (m + 1) % MOD * DIV % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rec[i].fi;
    for (int i = 0; i < n; i++)
        cin >> rec[i].se;
    stack <pll> st; ll res = 0;
    for (int i = 0; i <= n; i++) {
        ll add = 0;
        while (!st.empty() && st.top().fi >= rec[i].fi) {
            (res -= cal(st.top().fi, add)) %= MOD;
            (add += st.top().se) %= MOD;
            (res += cal(st.top().fi, add)) %= MOD;
            st.pop();
        }
        (res -= cal(rec[i].fi, add)) %= MOD;
        (rec[i].se += add) %= MOD;
        st.push(rec[i]);
    }
    if (res < 0) res += MOD;
    cout << res << '\n';
}