
// Problem : Problem 2. I Would Walk 500 Miles
// Contest : USACO - USACO 2019 US Open Contest, Gold
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=946
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    cout << 2019201997 - 48 * n - 84 * (k - 1) << '\n';
}