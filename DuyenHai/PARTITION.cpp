#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 5;
ll dp[N]; int a[N];

void solve2(){
    int n, k = 0, x; cin >> n;
    while (cin >> x) a[++k] = x;
    ll powt = 1; dp[0] = 1;
    for (int i = 1; i <= 62; i++){
        powt = powt + powt; dp[i] = dp[i - 1] + powt;
    }
    ll res = 1;
    for (int i = 1; i <= k; i++){
        if (n - 2 >= 0){
            if (n - a[i] - 1 >= 0)
                res += dp[n - 2] - dp[n - a[i] - 1];
            else res += dp[n - 2];
        }
        n -= a[i];
    }
    cout << res << '\n';
}

void solve1(){
    int n; ll k; cin >> n >> k;
    while (n > 0) {
        int x = 1;
        while (n >= x + 1 && n - x <= 63 && k > (1ll << (n - x - 1))) {
            k -= (1ll << (n - x - 1)); x++;
        }
        n -= x; cout << x << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    if (t == 2) solve2(); else solve1();
}