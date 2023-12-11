#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char open[] = "([{";
const char close[] = ")]}";
const int mod = 1e5;

ll dp[205][205]; char s[205]; int n;

ll calc(int i, int j){
    if (i > j) return 1;
    ll &res = dp[i][j];
    if (res >= 0) return res; res = 0ll;
    for (int k = i + 1; k <= j; k += 2)
        for (int type = 0; type < 3; type++)
            if (s[i] == open[type] || s[i] == '?')
                if (s[k] == close[type] || s[k] == '?'){
                    res += calc(i + 1, k - 1) * calc(k + 1, j);
                    if (res >= mod) res = mod + res % mod;
                }
    return res;
}

int main(){
    scanf("%d%s", &n, s);
    memset(dp, -1, sizeof(ll) * 205 * 205);
    ll res = calc(0, n - 1);
    if (res < mod) printf("%lld\n", res);
    else printf("%05lld\n", res - mod);
}