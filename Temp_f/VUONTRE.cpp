#include <bits/stdc++.h>
using namespace std;

int dp[256][256], trace[256][256];
bitset <256> is_src;

signed main(){
    freopen("vuontre.inp", "r", stdin);
    freopen("vuontre.out", "w", stdout);
    int p; cin >> p; 
    for (int i = 'a'; i <= 'z'; i++)
        for (int j = 'a'; j <= 'z'; j++)
            dp[i][j] = 0x3f3f3f3f;
    for (int i = 'a'; i <= 'z'; i++) dp[i][i] = 0;
    while (p--){
        char x, y; cin >> x >> y;
        if (x >= 'A') is_src[x] = true;
        if (y >= 'A') is_src[y] = true;
        x = tolower(x); y = tolower(y);
        int temp; cin >> temp;
        dp[x][y] = dp[y][x] = min(dp[x][y], temp);
        trace[x][y] = y; trace[y][x] = x;
    }
    for (int k = 'a'; k <= 'z'; k++)
        for (int i = 'a'; i <= 'z'; i++)
            for (int j = 'a'; j <= 'z'; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j]){
                    trace[i][j] = trace[i][k];
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
    char res; int mind = 0x3f3f3f3f;
    for (char i = 'A'; i < 'Z'; i++)
        if (is_src[i] && dp[tolower(i)]['z'] < mind){
            mind = dp[tolower(i)]['z']; res = i;
        }
    res = tolower(res);
    while (res != 'z'){
        cout << res << ' ' << dp[res][trace[res]['z']] << '\n';
        res = trace[res]['z'];
    }
    cout << "z\n";
}