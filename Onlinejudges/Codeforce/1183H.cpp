#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3 + 5;
ll f[N], g[N], sum[N], dp[N], res;
char s[N]; int n; ll k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> s + 1; f[0] = 1; dp[0] = 1;
    for (int j = 1; j <= n; j++){
        for (char c = 'a'; c <= 'z'; c++) sum[c] = 0;
        ll pre_sum = 0;
        for (int i = 0; i <= n; i++){
            g[i] = pre_sum - sum[s[i]];
            pre_sum += f[i]; sum[s[i]] += g[i];
            g[i] = min(k, g[i]);
            dp[j] = min(k, dp[j] + g[i]);
        }
        swap(f, g);
    }
    for (int i = n; i >= 0; i--){
        res += min(dp[i], k) * (n - i);
        k -= min(dp[i], k);
    }
    if (k > 0) cout << "-1\n";
    else cout << res << '\n';
}