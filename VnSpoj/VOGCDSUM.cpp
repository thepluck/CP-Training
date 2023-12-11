
// Problem : Z. VOGCDSUM - Tổng ước chung lớn nhất
// Contest : Codeforces - OI set 23
// URL : https://codeforces.com/group/FLVn1Sc504/contest/274860/problem/Z
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

map <ll, int> cur, nxt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll res = 0; cin >> n;
    while (n--) {
        ll x; cin >> x;
        nxt.clear(); nxt[x]++;
        for (auto p : cur)
            nxt[__gcd(p.first, x)] += p.second;
        for (auto p : nxt) {
            res += p.first % MOD * p.second % MOD;
            if (res >= MOD) res -= MOD;
        }
        swap(cur, nxt);
    }
    cout << res << '\n';
}