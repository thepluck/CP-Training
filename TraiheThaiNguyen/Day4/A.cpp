#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 3005;
int a[N]; ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; cin >> a[i++]);
    memset(dp, 0x3f, sizeof dp); dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++){
            chkmin(dp[i + 1][j + 1], dp[i][j]);
            if ((i + 1 - j) % k == 0)
                chkmin(dp[i + 1][j], dp[i][j]);
            else chkmin(dp[i + 1][j], dp[i][j] + a[i + 1]);
        }
    cout << *min_element(dp[n], dp[n] + m + 1) << '\n';
}