#include <bits/stdc++.h>
using namespace std;

const int LG = 22;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <int> f(1 << LG, - 1), a(n);
    for (int &x : a) {
        cin >> x;
        f[(1 << LG) - 1 & ~x] = x;
    }
    for (int i = (1 << LG) - 1; i > 0; i--)
        if (f[i] >= 0)
            for (int j = 0; j < LG; j++)
                if (i >> j & 1)
                    f[i ^ (1 << j)] = f[i];
    for (int x : a)
        cout << f[x] << ' ';
}