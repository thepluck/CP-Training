#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, p; cin >> n >> m >> p;
    long long res = 0;
    for (int w = 1; w <= n; w++)
        for (int h = 1; h <= m; h++)
            if (2 * (w + h) >= p)
                res += 1ll * (n - w + 1) * (m - h + 1);
    cout << res << '\n';
}