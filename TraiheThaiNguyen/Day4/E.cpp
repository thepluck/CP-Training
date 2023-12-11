#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int cnt[N]; ll dp[N], pw[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); pw[0] = 1;
    int n; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; cnt[x]++;
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    for (int i = N - 1; i > 0; i--){
        ll t = 0; int m = 0;
        for (int j = i; j < N; j += i){
            t += dp[j]; m += cnt[j];
        }
        dp[i] = (pw[m] - 1 - t) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }
    cout << dp[1] << '\n';
}