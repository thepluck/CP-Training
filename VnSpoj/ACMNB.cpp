#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, res = 0; cin >> n; vector <ii> a(2 * n);
    for (auto &pp : a) cin >> pp.fi >> pp.se;
    sort(a.begin(), a.end(), [&](ii p, ii q){
        return p.fi - q.fi < p.se - q.se;
    });
    for (int i = 0; i < n; i++) res += a[i].fi;
    for (int i = n; i < 2 * n; i++) res += a[i].se;
    cout << res << '\n';
}