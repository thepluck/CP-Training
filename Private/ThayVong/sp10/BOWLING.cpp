#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;
const int N = 2e5 + 5;
const ll ninf = 0xc0c0c0c0c0c0c0c0;
ll dp[N], s[N], maxdp[N], maxv[N]; vector <int> st;

bool comp(const int &i, const int &j){
    return maxdp[i] - s[i] <= maxdp[j] - s[j];
}

void solve(){
    int n, r; cin >> n >> r; ll res = ninf;
    for (int i = 1; i <= n; i++){
        cin >> s[i]; s[i] += s[i - 1];
    }
    fill_n(dp + 1, n, ninf); fill_n(maxdp + 1, n, 0);
    for (int i = r + 1; i < n; i++){
        dp[i] = s[i] + maxv[max(i - 2 * r - 1, 0)];
        maxdp[i] = max(maxdp[i - 1], dp[i]);
        if (i >= 2 * r + 1)
            maxv[i - 2 * r] = max(maxv[i - 2 * r - 1],
            maxdp[i - 2 * r] - s[i - 2 * r]);
        res = max(res, dp[i]);
    }
    for (int i = max(0, n - 2 * r - 1);
    i <= max(n - r - 1, 0); i++)
        dp[n] = max(dp[n], maxdp[i] + s[n] - s[i]);
    cout << max(res, dp[n]) << '\n';
}

int main(){
    //freopen("BOWLING.inp", "r", stdin);
    //freopen("BOWLING.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}