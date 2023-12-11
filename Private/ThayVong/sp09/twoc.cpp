#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;
int a[N]; ll sum[N];

int main(){
    freopen("twoc.inp", "r", stdin);
    freopen("twoc.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i < n; i++){
        int posl = (i + 1) / 2;
        int posr = (n + i + 1) / 2;
        ll cur = 1ll * (posl - 1) * a[posl] - sum[posl - 1];
        cur += sum[i] - sum[posl] - 1ll * (i - posl) * a[posl];
        ll cur2 = sum[n] - sum[posr] - 1ll * (n - posr) * a[posr];
        cur2 += 1ll * (posr - i - 1) * a[posr] - (sum[posr - 1] - sum[i]);
        ans = min(ans, cur + cur2);
    }
    cout << ans << '\n';
}