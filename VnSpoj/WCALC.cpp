#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll b, n, res = 0; cin >> b >> n;
    for (ll m = 1, tmp = n * n; m <= 2 * n; m++)
        if (m != n && b * m * (2 * n - m) % tmp == 0) res++;
    cout << res << '\n';
}