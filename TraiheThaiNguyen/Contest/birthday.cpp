#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll fac[N], invfac[N], dp[N];
vector <int> divi[N];

ll pow_mod(ll x, ll k){
    ll res = 1;
    for (; k; k >>= 1, x = x * x % mod)
        if (k & 1) res = res * x % mod;
    return res;
}

ll inverse(ll x){
    return pow_mod(x, mod - 2);
}

ll C(int k, int n){
    if (k > n) return 0;
    return fac[n] * invfac[k] % mod *
            invfac[n - k] % mod;
}

int main(){
    freopen("birthday.inp", "r", stdin);
    freopen("birthday.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < N; i++){
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = invfac[i - 1] *
                    inverse(i) % mod;
        for (int j = i; j < N; j += i)
            divi[j].emplace_back(i);
    }
    int q, n, m; cin >> q;
    while (q--){
        cin >> m >> n;
        for (int i : divi[m]){
            dp[i] = C(n - 1, i - 1);
            for (int j : divi[i])
                if (j != i)
                    dp[i] -= dp[j];
            dp[i] %= mod;
        }
        if (dp[m] < 0) dp[m] += mod;
        cout << dp[m] << '\n';
    }
}