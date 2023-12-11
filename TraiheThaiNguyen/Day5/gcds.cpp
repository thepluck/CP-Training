#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

map <int, int> cur, nxt, ans;

int main(){
    freopen("gcds.inp", "r", stdin);
    freopen("gcds.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; nxt.clear();
        for (auto pp : cur)
            nxt[__gcd(pp.fi, x)] += pp.se;
        nxt.swap(cur); cur[x]++;
        for (auto pp : cur){
            ans[pp.fi] += pp.se;
        }
    }
    int q, x; cin >> q;
    while (q--){
        cin >> x; cout << ans[x] << '\n';
    }
}