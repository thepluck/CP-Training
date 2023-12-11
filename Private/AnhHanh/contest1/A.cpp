#include <bits/stdc++.h>

using namespace std;

int cnt[1000];

int main() {
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p; cnt[p]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {  
        int p; cin >> p;
        if (!cnt[i]) res = max(res, p);
        if (i == 1 && cnt[i] == 1)
            res = max(res, p);
    }
    cout << res << '\n';
}