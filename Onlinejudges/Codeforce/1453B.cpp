// Problem: B. Suffix Operations
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

long long s[200005], a[200005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n >> a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + abs(a[i] - a[i - 1]);
        }
        long long res = min(s[n - 1], s[n] - s[2]);
        for (int i = 2; i < n; i++)
            res = min(res, s[i - 1] + s[n] -
            s[i + 1] + abs(a[i - 1] - a[i + 1]));
        cout << res << '\n';
    }
}