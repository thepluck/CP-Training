#include <bits/stdc++.h>
using namespace std;

#define popcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define FOR(i, j, k) for (int i = (j); i < (k); i++)
#define FORD(i, j, k) for (int i = (j); i >= (k); i--)

int a[17][17], dp[17][1 << 17], n;
const int inf = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];
    memset(dp, 0x3f, sizeof dp);
    FOR(i, 0, n) dp[i][1 << i] = 0;
    int state = 1 << n, ans = inf;
    FOR(mask, 0, state) FOR(i, 0, n) if (mask & (1 << i)) FOR(j, 0, n)
        if (j != i && mask & (1 << j) && a[i][j] > 0){
            dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + a[i][j]);
        }
    FOR(i, 0, n) ans = min(ans, dp[i][state - 1]);
    cout << ans << '\n';
}
