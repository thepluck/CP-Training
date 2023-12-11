#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e3 + 5;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

typedef long long ll;

ll dp[4][N][N];

ll get_oil(ll a[N][N], const int& k, const int& i, const int& j){
    return a[i][j] + a[i - k][j - k] - a[i - k][j] - a[i][j - k];

}

ll get3_oil(ll a[N][N], const int& k, const int& n, const int& m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    for (int cnt = 1; cnt <= 3; cnt++)
        for (int i = k; i <= n; i++)
            for (int j = k; j <= m; j++){
                dp[cnt][i][j] = max(dp[cnt][i - 1][j], dp[cnt][i][j - 1]);
                chkmax(dp[cnt][i][j], dp[cnt - 1][i - k][j] + get_oil(a, k, i, j));
                chkmax(dp[cnt][i][j], dp[cnt - 1][i][j - k] + get_oil(a, k, i, j));
            }
    return dp[3][n][m];
}

ll a[N][N], b[N][N], c[N][N], d[N][N];
int n, m, k;

int main(){
    freopen("oil.inp", "r", stdin);
    freopen("oil.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            b[j][n - i + 1] = a[i][j];
            c[n - i + 1][m - j + 1] = a[i][j];
            d[m - j + 1][i] = a[i][j];
        }
    ll res = max(get3_oil(a, k, n, m), get3_oil(c, k, n, m));
    chkmax(res, get3_oil(b, k, m, n));
    chkmax(res, get3_oil(d, k, m, n));
    cout << res << endl; return 0;
}