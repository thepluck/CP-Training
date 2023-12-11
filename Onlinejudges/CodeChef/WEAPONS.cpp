
// Problem : Fusing Weapons 
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/WEAPONS
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 200005;

int a[N * 2];
vector <int> r[N * 2];

int reduce(int i, int v) {
    int d = v - a[i];
    if (d < 0 || d >= r[i].size()) return -1;
    return r[i][d];
}

void solve() {
    int n, res = 0; cin >> n;
    for (int i = 0; i++ < n; ) {
        cin >> a[i]; int v = a[i];
        r[i].eb(i - 1); a[i + n] = a[i];
        while (true) {
            int j = reduce(r[i].back(), v);
            if (j < 0 || j < i - n) break;
            r[i].eb(j); v++;
        }
        res = max(res, v);
    }
    for (int i = n; i++ < 2 * n; ) {
        int v = a[i]; r[i].eb(i - 1);
        while (true) {
            int j = reduce(r[i].back(), v);
            if (j < 0 || j < i - n) break;
            r[i].eb(j); v++;
        }
        res = max(res, v);
    }
    for (int i = 0; i++ < 2 * n; )
        r[i].clear();
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}