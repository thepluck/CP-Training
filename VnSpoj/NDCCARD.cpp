#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, res = 0; cin >> n >> m;
    vector <int> a(n); for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 2; i < n; i++){
        int l = 0, r = i - 1;
        while (l < r)
            if (a[l] + a[r] <= m - a[i])
                res = max(res, a[l++] + a[r] + a[i]);
            else r--;
    }
    cout << res << '\n';
}