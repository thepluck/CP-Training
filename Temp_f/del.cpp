#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

#define pop_cnt __builtin_popcount
ll a[20], k; int n;

ll query(ll val){
    ll res = 0;
    for (int mask = 1; mask < (1 << n); mask++){
        int sign = -1; ll bc = 1;
        if (pop_cnt(mask) & 1) sign = 1;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1) bc = lcm(bc, a[i]);
        res += (val / bc) * sign;
    }
    return res;
}

ll solve(){
    cin >> n >> k;
    for (int i = 0; i < n; cin >> a[i++]);
    ll lo = 1, hi = 7e18 + 7, ans = 0;
    while (lo <= hi){
        ll mi = (lo + hi) / 2;
        if (mi - query(mi) >= k)
            ans = mi, hi = mi - 1;
        else lo = mi + 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("del.inp", "r", stdin);
    freopen("del.out", "w", stdout);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}