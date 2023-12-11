#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int a[1 << N];

int main() {
    freopen("qn.inp", "r", stdin);
    freopen("qn.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, x, p; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 1 << i; j < (1 << i + 1); j++)
            a[j] = a[j - (1 << i)] + (1 << i);
        reverse(a + (1 << i), a + (1 << i + 1));
    }
    for (int i = 0; i < (1 << n); i++)
        if (a[i] == x) p = i;
    rotate(a, a + p, a + (1 << n));
    for (int i = 1; i < (1 << n); i++)
        cout << a[i] << '\n';
}