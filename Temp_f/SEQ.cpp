/// find number of range [i, j] such that l <= |a[i] + ... + a[j]| <= r
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
using ll = long long;
ll a[N], l, r; int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l >> r; int ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; a[i] += a[i - 1];
    }
    for (int i = 0, j = 1, k = 1; i < n; i++){
        while (j <= n && a[j] < a[i] - r) j++;
        while (k <= n && a[k] <= a[i] - l) k++;
        ans += k - j;
    }
    cout << ans << '\n';
}