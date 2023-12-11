#include <bits/stdc++.h>
using namespace std;

bitset <300> palin[300];
char s[300]; int dp[300];
int main(){
    scanf("%s", s + 1);int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        palin[i][i] = true, dp[i] = i;
    for (int i = 1; i < n; i++)
        palin[i][i + 1] = s[i] == s[i + 1];
    for (int dif = 2; dif < n; dif++)
        for (int i = 1; i + dif <= n; i++)
            if (s[i] == s[i + dif])
                palin[i][i + dif] = palin[i + 1][i + dif - 1];
            else palin[i][i + dif] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (palin[j + 1][i])
                dp[i] = min(dp[i], dp[j] + 1);
    cout << dp[n] << '\n';
}