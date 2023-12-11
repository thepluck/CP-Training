#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sqr(a) (a) * (a)
using ll = long long;
using pll = pair <ll, ll>;

const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dp[1005][1005][2];
pll a[1005], b[1005];

ll dis(pll p, pll q){
    return sqr(p.fi - q.fi) + sqr(p.se - q.se);
}

int main(){
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 1; i <= m; i++) cin >> b[i].fi >> b[i].se;
    memset(dp, 0x3f, sizeof(ll) * 1005 * 1005 * 2);
    dp[1][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++){
            dp[i + 1][j][0] = min(dp[i][j][0] + dis(a[i + 1], a[i]),
                                    dp[i][j][1] + dis(b[j], a[i + 1]));
            dp[i][j + 1][1] = min(dp[i][j][1] + dis(b[j], b[j + 1]),
                                    dp[i][j][0] + dis(a[i], b[j + 1]));
        }
    cout << min(dp[n - 1][m][0] + dis(a[n], a[n - 1]),
                    dp[n - 1][m][1] + dis(a[n], b[m]));
}