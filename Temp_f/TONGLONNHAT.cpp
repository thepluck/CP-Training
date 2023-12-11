#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("TONGLONNHAT.inp", "r", stdin);
    freopen("TONGLONNHAT.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    typedef long long ll;
    ll n, x; cin >> n; ll s, mins, res;
    s = mins = 0; res = LLONG_MIN;
    while (n--){
        cin >> x; s += x;
        res = max(res, s - mins);
        mins = min(mins, s);
    }
    cout << res;
}