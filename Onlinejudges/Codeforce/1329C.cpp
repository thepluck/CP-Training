#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
#define fi first
#define se second
using ll = long long;
using ii = pair <int, int>;
ii a[N]; bool tk[N], gt[N];

void solve(){
    int h, g; ll res = 0; cin >> h >> g;
    for (int i = 1; i < (1 << h); i++)
        tk[i] = gt[i] = 0;
    for (int i = 1; i < (1 << h); i++){
        cin >> a[i].fi; a[i].se = i;
    }
    sort(a + 1, a + (1 << h));
    for (int i = 1; i < (1 << h); i++){
        int p = a[i].se;
        while (p >= (1 << g) || gt[p]) p /= 2;
        if (!p) continue;
        if (gt[p * 2 + 1] == gt[p * 2]){
            gt[p] = 1; res += a[i].fi; tk[a[i].se] = 1;
        }
    }
    cout << res << '\n';
    for (int i = (1 << h) - 1; i > 0; i--)
        if (!tk[i]) cout << i << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}