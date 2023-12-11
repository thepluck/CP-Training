#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
using ll = long long;
ll dp[N][N], s[N], a[N];

int calc(int l, int r){
    ll &res = dp[l][r];
    if (res != -1) return res;
    if (l == r) return res = a[l];
    if (l + 1 == r) return res = max(a[l], a[r]);
    res = a[l] + s[r] - s[l] - calc(l + 1, r);
    res = max(res, a[r] + s[r - 1] - s[l - 1] - calc(l, r - 1));
    return res;
}

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; s[i] = s[i - 1] + a[i];
    }
    memset(dp, -1, sizeof(ll) * N * N);
    if (2 * calc(1, n) > s[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
}