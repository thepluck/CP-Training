#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;
const int N = 1005;
ii dp[N][N]; int x, y, a, b, n;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

bool check(int lim){
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            dp[i][j] = {0, 0};
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++){
            ii tmp = dp[i][j];
            if (tmp.fi == n) return 1;
            tmp.se += a;
            if (tmp.se >= lim){
                tmp.fi++; tmp.se = 0;
            }
            chkmax(dp[i + 1][j], tmp);
            tmp = dp[i][j];
            tmp.se += b;
            if (tmp.se >= lim){
                tmp.fi++; tmp.se = 0;
            }
            chkmax(dp[i][j + 1], tmp);
        }
    return false;
}

int solve(){
    cin >> x >> a >> y >> b >> n;
    int l = 0, r = 1e9, m, ans = 0;
    while (l <= r){
        m = (l + r) >> 1;
        if (check(m)){
            ans = m; l = m + 1;
        }
        else r = m - 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << solve() << '\n';
    cout << solve() << '\n';
}