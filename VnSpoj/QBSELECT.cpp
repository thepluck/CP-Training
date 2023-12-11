#include <bits/stdc++.h>
using namespace std;
#define popcnt __builtin_popcountll

typedef long long ll;
const int N = 1e4 + 5;
int a[4][N]; ll dp[N][16];

bool getbit(int x, int j){
    return (x >> j) & 1;
}

bool ok(int t, int s){
    for (int i = 1; i < 4; i++){
        if (getbit(t, i) && getbit(t, i - 1)) return false;
        if (getbit(s, i) && getbit(s, i - 1)) return false;
    }
    for (int i = 0; i < 4; i++)
        if (getbit(s, i) && getbit(t, i)) return false;
    return true;
}

int getsum(int t, int j){
    int tmp = 0;
    for (int i = 0; i < 4; i++)
        tmp += getbit(t, i) * a[i][j];
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll maxv = -1e18;
    int n; cin >> n; bool oke = false;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++){
            cin >> a[i][j]; maxv = max(maxv, 1ll * a[i][j]);
            if (a[i][j] >= 0) oke = true;
        }
    if (!oke){
        cout << maxv; return 0;
    }
    ll res = -1e18;
    for (int i = n - 1; i >= 0; i--){
        for (int mask1 = 0; mask1 < 16; mask1++){
            dp[i][mask1] = -1e18;
            for (int mask2 = 0; mask2 < 16; mask2++)
                if (ok(mask1, mask2))
                    dp[i][mask1] = max(dp[i][mask1], dp[i + 1][mask2] + getsum(mask1, i));
            if (mask1) res = max(res, dp[i][mask1]);
        }
    }
    cout << res;
}
