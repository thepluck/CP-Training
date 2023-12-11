#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;
ll lim;
pll l[(1 << 21) + 1], r[(1 << 21) + 1];
ll w[50], v[50], maxv[(1 << 21) + 1];
int cntl, cntr, n;

void res1(int i, ll weight, ll val){
    l[++cntl] = {weight, val};
    while (++i <= n / 2)
        if (weight + w[i] <= lim)
            res1(i, weight + w[i], val + v[i]);
}

void res2(int i, ll weight, ll val){
    r[++cntr] = {weight, val};
    while (++i <= n)
        if (weight + w[i] <= lim)
            res2(i, weight + w[i], val + v[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> lim;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    res1(0, 0, 0); res2(n / 2, 0, 0);
    sort(r + 1, r + cntr + 1);
    for (int i = 1; i <= cntr; i++)
        maxv[i] = max(maxv[i - 1], r[i].se);
    ll ans = 0;
    for (int i = 1; i <= cntl; i++){
        int lo = 1, hi = cntr, mi;
        while (lo <= hi){
            mi = (lo + hi) / 2;
            if (r[mi].fi + l[i].fi <= lim){
                ans = max(ans, l[i].se + maxv[mi]);
                lo = mi + 1;
            }
            else hi = mi - 1;
        }
    }
    cout << ans << '\n';
}
