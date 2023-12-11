// Problem: B. XOR-gun
// Contest: Codeforces - Codeforces Round #687 (Div. 1, based on Technocup 2021 Elimination Round 2)
// URL: https://codeforces.com/contest/1456/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n > 60) return cout << 1, 0;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    int res = n + 1;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = i; j < n; j++) {
            x ^= a[j]; int y = 0;
            for (int k = j + 1; k < n; k++) {
                y ^= a[k];
                if (x > y) {
                    res = min(res, k - i - 1);
                    break;
                }
            }
        }
    }
    if (res == n + 1) cout << -1;
    else cout << res;
}