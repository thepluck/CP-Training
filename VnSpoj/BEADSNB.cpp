#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
const int N = 1e5 + 5;
int a[N], t[N], f[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, len = 0; cin >> n;
    t[0] = 0xc0c0c0c0;
    for (int i = 1; i <= n; i++)
        cin >> a[n - i + 1];
    for (int i = 1; i <= n; i++){
        int k = lb(t, t + len + 1, a[i]) - t;
        len = max(k, len); t[k] = a[i]; f[i] = k;
    }
    len = 0; int ans = 0;
    for (int i = 1; i <= n; i++){
        int k = lb(t, t + len + 1, -a[i]) - t;
        len = max(k, len); t[k] = -a[i];
        ans = max(ans, f[i] + k - 1);
    }
    cout << ans << '\n';
}