
// Problem : Partition into Permutations
// Contest : CodeChef - March Lunchtime 2019 Division 1
// URL : https://www.codechef.com/LTIME70A/problems/PERMPART
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0; cin >> n;
    vector <int> cnt(2 * n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= 2 * n) cnt[x]++;
        else ans++;
    }
    vector <vector <int>> lev(n);
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 0; j < cnt[i]; j++)
            lev[j].push_back(i);
    for (const vector <int> &v : lev) {
        int m = v.size(), mn = m;
        for (int i = 0; i < m; i++)
            mn = min(mn, v[i] - 2 * i - 2 + m);
        ans += mn;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}