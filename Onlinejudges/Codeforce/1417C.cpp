
// Problem : C. k-Amazing Numbers
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int a[N], ans[N], lst[N], dis[N];

void solve() {
    vector <int> cmp;
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++) {
        dis[i] = lst[i] = 0; ans[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        cmp.push_back(a[i]);
        dis[a[i]] = max(dis[a[i]], i - lst[a[i]]);
        lst[a[i]] = i;
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(),
    cmp.end()), cmp.end());
    int suf = n;
    for (int x : cmp)
        dis[x] = max(dis[x], n - lst[x] + 1);
    for (int x : cmp) {
        for (int i = dis[x]; i <= suf; i++)
            ans[i] = x;
        suf = min(suf, dis[x] - 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n]; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}