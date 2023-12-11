#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("electric.inp", "r", stdin);
    freopen("electric.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, res = INT_MAX; cin >> n;
    vector <int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++)
        res = min(res, a[i] + b[i]);
    cout << res << '\n';
}