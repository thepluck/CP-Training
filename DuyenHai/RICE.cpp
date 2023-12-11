#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 2e5 + 5;
int a[N], dp[N], nxt[N], mn[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n, k; cin >> m >> n >> k;
    for (int i = 1; i <= n; cin >> a[i++]);
    sort(a + 1, a + n + 1);
    memset(dp, 0x3f, sizeof dp);
    memset(mn, 0x3f, sizeof mn);
    for (int i = 1, j = 1; i <= n; i++){
        while (j <= n && a[j] - a[i] < k) j++;
        nxt[i] = j;
    }
    dp[n + 1] = 0; mn[n + 1] = a[n];
    for (int i = n; i > 0; i--){
        dp[i] = min(dp[nxt[i]] + k, mn[nxt[i] + 1] - a[i] + 1);
        mn[i] = min(mn[i + 1], dp[i] + a[i - 1]);
    }
    cout << dp[1] << '\n';
}