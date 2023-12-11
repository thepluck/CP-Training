#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k, a, b, q, u, v;
    cin >> k >> a >> b >> q;
    int t = (b - a) / __gcd(b - a, k);
    int temp = __gcd(k, t);
    while (temp != 1){
        t = t / temp;
        temp = __gcd(k, t);
    }
    while (q--){
        cin >> u >> v;
        if (u >= v || (v - u) % t != 0)
            cout << "NO\n";
        else cout << "YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}