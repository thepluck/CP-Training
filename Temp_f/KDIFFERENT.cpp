#include <bits/stdc++.h>
using namespace std;

int dp[256];

int main(){
    freopen("KDifferent.INP", "r", stdin);
    freopen("KDifferent.OUT ", "w", stdout);
    int k; string s; cin >> k >> s;
    char mi = *min_element(s.begin(), s.end());
    char ma = *max_element(s.begin(), s.end());
    for (char c : s){
        int res = 1;
        for (char x = mi; x <= ma; x++)
            if (abs(x - c) <= k)
                res = max(res, dp[x] + 1);
        dp[c] = max(dp[c], res);
    }
    cout << *max_element(dp, dp + 256) << '\n';
}