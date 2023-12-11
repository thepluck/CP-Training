// Problem: A. Cancel the Trains
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int mark[105], timer;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        timer++; int cnt = 0;
        while (n--) {
            int x; cin >> x;
            mark[x] = timer;
        }
        while (m--) {
            int x; cin >> x;
            if (mark[x] == timer) cnt++;
        }
        cout << cnt << '\n';
    }
}