#include <bits/stdc++.h>
using namespace std;
#define popcnt __builtin_popcountll

typedef unsigned long long ull;
ull dp[35][1024];

bool getbit(int x, int j){
    return (x >> j) & 1;
}

bool ok(int t, int s, int m){
    for (int i = 1; i < m; i++){
        if (getbit(t, i) && getbit(s, i) && getbit(t, i - 1) && getbit(s, i - 1)) return false;
        if (!(getbit(t, i) || getbit(s, i) || getbit(t, i - 1) || getbit(s, i - 1))) return false;
    }
    return true;
}

namespace solve{
    void solu(){
        int n, m; cin >> n >> m;
        if (n < m) swap(n, m);
        for (int mask = 0; mask < (1 << m); mask++)
            dp[n - 1][mask] = 1;
        for (int i = n - 2; i >= 0; i--){
            for (int mask1 = 0; mask1 < (1 << m); mask1++){
                dp[i][mask1] = 0;
                for (int mask2 = 0; mask2 < (1 << m); mask2++)
                    if (ok(mask1, mask2, m)) dp[i][mask1] += dp[i + 1][mask2];
                //cout << dp[i][mask1] << ' ';
            }
            //cout << '\n';
        }
        ull res = 0;
        for (int mask = 0; mask < (1 << m); mask++)
            res += dp[0][mask];
        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve::solu();
}

