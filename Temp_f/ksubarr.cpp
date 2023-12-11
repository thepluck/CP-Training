#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
ll dp[N], s[N]; int cn[N], n, k;

bool cmp(int i, int j){
    return dp[i] + s[j] - s[i] < dp[j]
    || (dp[i] + s[j] - s[i] == dp[j] && cn[i] > cn[j]);
}

bool cal(ll aux){
    int id = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1]; cn[i] = cn[i - 1];
        ll ndp = dp[id] + s[i] - s[id] - aux;
        int ncn = cn[id] + 1;
        if (ndp > dp[i] || (ndp == dp[i] && ncn < cn[i])){
            dp[i] = ndp; cn[i] = ncn;
        }
        if (cmp(id, i)) id = i;
    }
    return cn[n] <= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> s[i]; s[i] += s[i - 1];
    }
    ll l = 0, r = 1e18, m, aux;
    while (l <= r){
        m = l + r >> 1;
        if (cal(m)) aux = m, r = m - 1; else l = m + 1;
    }
    cal(aux); cout << dp[n] + aux * cn[n] << '\n';
}