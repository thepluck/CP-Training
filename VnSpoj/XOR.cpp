#include <bits/stdc++.h>
using namespace std;

int basis[32], sz;

bool insert(int mask){
    for (int i = 0; i < 32; i++){
        if (!(mask >> i & 1)) continue;
        if (!basis[i]){
            basis[i] = mask; return true;
        }
        mask ^= basis[i];
    }
    return false;
}

void solve(){
    memset(basis, 0, sizeof basis);
    int n, x; cin >> n; sz = 0;
    for (int i = 1; i <= n; i++){
        cin >> x; sz += insert(x);
    }
    if (sz == n) cout << "YES\n";
    else cout << "NO " << n - sz << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}