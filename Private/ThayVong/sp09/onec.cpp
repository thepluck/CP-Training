#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("onec.inp", "r", stdin);
    freopen("onec.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n / 2; i++)
        ans += a[n / 2] - a[i];
    for (int i = n / 2 + 1; i < n; i++)
        ans += a[i] - a[n / 2];
    cout << ans << '\n';
}