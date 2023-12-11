#include <bits/stdc++.h>
using namespace std;

using iii = tuple <int, int, int>;

int dp[105][105][105], kmp[105];
char s[105], t[105], vr[105];
iii trace[105][105][105];

int main(){
    freopen("lucky.inp", "r", stdin);
    freopen("lucky.out", "w", stdout);
    scanf("%s%s%s", s + 1, t + 1, vr + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int k = strlen(vr + 1), ans = 0;
    for (int i = 2, j = 0; i <= k; i++){
        while (j > 0 && vr[j + 1] != vr[i]) j = kmp[j];
        if (vr[i] == vr[j + 1]) j++; kmp[i] = j;
    }
    memset(dp, 0xc0, sizeof dp); dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int x = 0; x < k; x++){
                if (dp[i + 1][j][x] < dp[i][j][x]){
                    dp[i + 1][j][x] = dp[i][j][x];
                    trace[i + 1][j][x] = {i, j, x};
                }
                if (dp[i][j + 1][x] < dp[i][j][x]){
                    dp[i][j + 1][x] = dp[i][j][x];
                    trace[i][j + 1][x] = {i, j, x};
                }
                if (s[i + 1] == t[j + 1]){
                    int tmp = x;
                    while (tmp > 0 && s[i + 1] != vr[tmp + 1])
                        tmp = kmp[tmp];
                    if (s[i + 1] == vr[tmp + 1]) tmp++;
                    if (dp[i + 1][j + 1][tmp] < dp[i][j][x] + 1){
                        dp[i + 1][j + 1][tmp] = dp[i][j][x] + 1;
                        trace[i + 1][j + 1][tmp] = {i, j, x};
                    }
                }
            }
    int tmp = 0; string res;
    for (int x = 0; x < k; x++)
        if (dp[n][m][x] > ans){
            ans = dp[n][m][x]; tmp = x;
        }
    while (n > 0 && m > 0){
        int i, j, x; tie(i, j, x) = trace[n][m][tmp];
        if (i + 1 == n && j + 1 == m) res.push_back(s[n]);
        n = i; m = j; tmp = x;
    }
    reverse(res.begin(), res.end());
    if (res.empty()) cout << "0\n";
    else cout << res << '\n';
}