#include <bits/stdc++.h>
using namespace std;
 
char s[10005], t[1005];
int dp[10005][1005], n, m, kmp[1005], aut[26][1005];
 
void solve(){
    n = strlen(s + 1); m = strlen(t + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;
    for (int i = 2, j = 0; i <= m; i++){
        while (j > 0 && t[i] != t[j + 1]) j = kmp[j - 1];
        if (t[i] == t[j + 1]) j++; kmp[i] = j;
    }
    for (int c = 0; c < 26; c++)
        for (int j = 0; j < m; j++){
            if (j > 0 && c + 'a' != t[j + 1]) aut[c][j] = aut[c][kmp[j]];
            else aut[c][j] = j + (c + 'a' == t[j + 1]);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][aut[s[i + 1] - 'a'][j]] =
                max(dp[i + 1][aut[s[i + 1] - 'a'][j]], dp[i][j] + 1);
        }
    int res = 0;
    for (int i = 0; i < m; i++) res = max(res, dp[n][i]);
    printf("%d\n", n - res);
}
 
int main(){
    while (scanf("%s%s", s + 1, t + 1) == 2) solve();
} 