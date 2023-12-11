#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;
int a[N]; ll sum[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, l, ans = 0; ll b; cin >> n >> l >> b;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1, j = 0; i <= n; i++){
        while (j < n){
            int pos = (i + j + 1) / 2;
            if (pos > l) goto gg;
            if ((j - i) & 1){
                if (sum[j + 1] - sum[pos] - sum[pos - 1] + sum[i - 1] <= b) j++;
                else goto gg;
            }
            else {
                if (sum[j + 1] - sum[pos] - sum[pos] + sum[i - 1] <= b) j++;
                else goto gg;
            }
        }
        gg: ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
}