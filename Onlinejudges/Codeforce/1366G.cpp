#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 1e4 + 5;
int dp[N][N], nxt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s, t; cin >> s >> t;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] != '.'){
            int cnt = 0;
            for (int j = i; s[j]; j++){
                if (s[j] == '.') cnt++;
                else cnt--;
                if (cnt == 0){
                    nxt[i] = j; break;
                }
            }
        }
    for (int i = 0; s[i]; i++)
        for (int j = 0; j <= t.size(); j++){
            chkmin(dp[i + 1][j], dp[i][j] + 1);
            if (s[i] == t[j])
                chkmin(dp[i + 1][j + 1], dp[i][j]);
            if (nxt[i])
                chkmin(dp[nxt[i] + 1][j], dp[i][j]);
        }
    cout << dp[s.size()][t.size()] << '\n';
}