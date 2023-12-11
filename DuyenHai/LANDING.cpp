#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int N = 1e5 + 5;
using ii = pair <int, int>;
ii pl[N]; int tim[N], n, k, cnt[N];

int cal(int x){
    for (int i = 0; i < k; i++){
        cnt[i] = 1; tim[i] = pl[i].fi;
    }
    for (int i = k, j = 0; i < n; i++){
        while (i < n && pl[i].se - tim[j] < x) i++;
        if (i < n){
            tim[j] = max(tim[j] + x, pl[i].fi);
            cnt[j]++; j = (j + 1) % k;
        }
    }
    return accumulate(cnt, cnt + k, 0);
}

int main(){
    freopen("LANDING.inp", "r", stdin);
    freopen("LANDING.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x; cin >> n >> k >> x;
    if (n <= k) return cout << n << " -1\n", 0;
    for (int i = 0; i < n; i++)
        cin >> pl[i].fi >> pl[i].se;
    sort(pl, pl + n); int res = cal(x);
    bool ok = false; cout << res << ' ';
    for (int i = 0; i <= k; i++) ok |= cnt[i] > 1;
    if (!ok) cout << "-1\n";
    int lo = x, hi = 1e9, mi, ans;
    while (lo <= hi){
        mi = (lo + hi) >> 1;
        if (cal(mi) == res){
            ans = mi; lo = mi + 1;
        }
        else hi = mi - 1;
    }
    cout << ans << '\n';
}