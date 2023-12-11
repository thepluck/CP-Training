
// Problem : E. Clear the Multiset
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int a[N];

int sol(int i, int j, int pr) {
    if (i >= j) return 0;
    int k = min_element(a + i, a + j) - a;
    return min(j - i, sol(i, k, a[k])
    + a[k] - pr + sol(k + 1, j, a[k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << sol(0, n, 0) << '\n';
}