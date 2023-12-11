#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 1005;
int dp[M][M], nxt[N][26];
char s[N], t[N];

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

int main(){
    freopen("comst.inp", "r", stdin);
    freopen("comst.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q, n, m; cin >> s + 1 >> q;
    n = strlen(s + 1);
    while (q--){
        cin >> t + 1; m = strlen(t + 1);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = n + 2;
        dp[0][0] = 0; int res = 0;
        for (int i = n - 1; ~i; i--)
            for (int c = 0; c < 26; c++)
                if (s[i + 1] - 'a' == c)
                    nxt[i][c] = i + 1;
                else nxt[i][c] = nxt[i + 1][c];
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= i; j++){
                chkmin(dp[i + 1][j], dp[i][j]);
                int pos = nxt[dp[i][j]][t[i + 1] - 'a'];
                if (pos > 0) chkmin(dp[i + 1][j + 1], pos);
            }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                if (dp[i][j] <= n) res = max(res, j);
        cout << res << '\n';
    }
}