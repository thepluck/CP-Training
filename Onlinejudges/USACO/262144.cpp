
// Problem : Problem 1. 262144
// Contest : USACO - USACO 2016 US Open Contest, Platinum
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=648
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 300005;

int a[N];
vector <int> r[N];

int reduce(int i, int v) {
    int d = v - a[i];
    if (d < 0 || d >= r[i].size()) return -1;
    return r[i][d];
}

int main() {
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    for (int i = 0; ++i <= n; ) {
        cin >> a[i]; int v = a[i];
        r[i].eb(i - 1);
        while (~reduce(r[i].back(), v))
            r[i].eb(reduce(r[i].back(), v++));
        res = max(res, v);
    }
    cout << res << '\n';
}