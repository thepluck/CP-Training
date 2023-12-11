#include <bits/stdc++.h>
using namespace std;

int g[10005], cnt[10005];

int main(){
    freopen("nim.inp", "r", stdin);
    freopen("nim.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n; cin >> n;
    long long tmp = 2, x = 2;
    while (tmp + x * x * 3 - x < n){
        tmp += x * x * 3 - x; x *= 2;
    }
    long long l = 0, r = 1e7, m, ans = 0;
    while (l <= r){
        m = (l + r) / 2;
        if (tmp + (x + 1 + m) * (m - x) <= n){
            ans = m; l = m + 1;
        }
        else r = m - 1;
    }
    tmp += (ans + 1 + x) * (ans - x);
    if (tmp == n || tmp + ans + 1 == n)
        cout << "LOSE\n";
    else cout << "WIN\n";
}