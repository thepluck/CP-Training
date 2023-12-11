#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater <int> ());
    long long maxv = 0; int res;
    for (int i = 1; i <= min(m, n); i++)
        if (1ll * i * a[i] > maxv){
            maxv = 1ll * i * a[i]; res = a[i];
        }
        else if (1ll * i * a[i] == maxv) res = a[i];
    cout << res << ' ' << maxv << '\n';
}