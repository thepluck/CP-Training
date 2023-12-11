#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

using ll = long long;

ll b[N], a[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);  
    int t; cin >> t;
    while (t--) {
        memset(b, 0, sizeof b);
        int n; cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i]; ll x;
            ll u = min(ll(n), a[i] + i);
            for (int j = u; j > i + 1; j--) b[j]++;
            a[i] -= b[i];
            if (a[i] < 1){
                x = 1 - a[i]; a[i] = 1;
            }
            else x = 0;
            ans += a[i] - 1; b[i + 1] += x;
        }
        cout << ans << '\n';
    }

}