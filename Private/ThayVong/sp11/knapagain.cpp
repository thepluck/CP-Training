#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
using ll = long long;
using ii = pair <int, ll>;
ll dp[100005], maxv[1 << 21];
int n, m, a[100005], c[100005];

void solve1(){
    vector <ii> l, r;
    for (int i = 0; i < n; cin >> a[i++]);
    for (int i = 0; i < n; cin >> c[i++]);
    for (int mask = 0; mask < (1 << (n / 2)); mask++){
        ll weight = 0, cost = 0;
        for (int i = 0; i < n / 2; i++)
            if (mask >> i & 1){
                weight += a[i]; cost += c[i];
            }
        if (weight <= m) l.push_back({weight, cost});
    }
    for (int mask = 0; mask < (1 << (n - n / 2)); mask++){
        ll weight = 0, cost = 0;
        for (int i = n / 2; i < n; i++)
            if (mask >> (i - n / 2) & 1){
                weight += a[i]; cost += c[i];
            }
        if (weight <= m) r.push_back({weight, cost});
    }
    sort(all(r)); ll res = 0;
    for (int i = 1; i < r.size(); i++)
        maxv[i] = max(maxv[i - 1], r[i].se);
    for (auto pp : l){
        auto it = upper_bound(all(r), ii(m - pp.fi, LLONG_MAX));
        if (it != r.begin())
            res = max(res, pp.se + maxv[--it - r.begin()]);
    }
    cout << res << '\n';
}

void solve2(){
    memset(dp, 0xc0, sizeof dp); dp[0] = 0;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; cin >> c[i++]);
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
    }
    cout << *max_element(dp + 1, dp + m + 1) << '\n';
}

void solve3(){
    memset(dp, 0x3f, sizeof dp); dp[0] = 0;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; cin >> c[i++]);
    int maxc = accumulate(c + 1, c + n + 1, 0ll);
    for (int i = 1; i <= n; i++)
        for (int j = maxc; j >= c[i]; j--)
            dp[j] = min(dp[j], dp[j - c[i]] + a[i]);
    for (int j = maxc; ~j; j--)
        if (dp[j] <= m) return void(cout << j << '\n');
}

int main(){
    freopen("knapagain.inp", "r", stdin);
    freopen("knapagain.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n <= 40) return solve1(), 0;
    if (m <= 50000) return solve2(), 0;
    solve3();
}