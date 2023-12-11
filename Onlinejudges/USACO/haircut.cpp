
// Problem : Problem 1. Haircut
// Contest : USACO - USACO 2020 US Open Contest, Gold
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=1041
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

int f[N]; ll b[N];

void update(int i) {
    for (; i > 0; i -= i & -i)
        f[i]++;
}

int query(int i) {
    int res = 0;
    for (; i < N; i += i & -i)
        res += f[i];
    return res;
}

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x + 1] += query(x + 1);
        update(x);
    }
    for (int i = 1; i < n; i++)
        b[i] += b[i - 1];
    for (int i = 0; i < n; i++)
        cout << b[i] << '\n';
}