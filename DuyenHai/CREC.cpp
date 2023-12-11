#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;

const int inf = 0x3f3f3f3f;
const int N = 105;
int dp[N][N][N];
ii a[N]; int x[N], y[N], s, n;
int mpx[N], mpy[N];

int cal(int i, int j, int k){
    int &res = dp[i][j][k];
    if (~res) return res;
    if (i == j){
        int last = 0; res = 0;
        for (int p = k; p <= n; p++)
            if (y[p] > last){
                res++; last = y[p] + s;
            }
        return res;
    }
    int p = inf, q = 0, r = inf; res = inf;
    for (int l = 1; l <= n; l++)
        if (a[l].fi >= x[i] && a[l].fi <= x[j] &&
        a[l].se >= y[k] && (a[l].se - y[k]) * (x[j] - x[i]) > s){
            p = min(p, a[l].fi); q = max(q, a[l].se);
            r = min(r, a[l].se);
        }
    if (p == inf){
        r = 0;
        for (int l = 1; l <= n; l++)
            if (a[l].fi >= x[i] && a[l].fi <= x[j] && a[l].se >= y[k])
                r = max(r, a[l].se);
        if ((r - y[k]) * (x[j] - x[i]) <= s) res = 1;
    }
    else res = cal(mpx[p], mpx[q], mpy[r]) + 1;
    for (p = i; p < j; p++)
        res = min(res, cal(i, p, k) + cal(p + 1, j, k));
    return res;
}

int main(){
    freopen("CREC.inp", "r", stdin);
    freopen("CREC.out", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        a[i] = ii(x[i], y[i]);
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    memset(dp, -1, sizeof dp);
    x[n + 1] = y[n + 1] = inf;
    for (int i = n; i > 0; i--) mpx[x[i]] = i;
    for (int i = n; i > 0; i--) mpy[y[i]] = i;
    cout << cal(1, n, 1) << '\n';
}