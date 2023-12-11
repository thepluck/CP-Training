#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], n, k;

int main(){
    freopen("shortseq.inp", "r", stdin);
    freopen("shortseq.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k; int ans = n + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, j = 0, cur = 0; i <= n; i++){  
        cur -= a[i - 1];
        while (j < n && cur < k) cur += a[++j];  
        if (cur == k) ans = min(ans, j - i + 1);
    }
    if (ans == n + 1) cout << 0 << '\n';
    else cout << ans << '\n';
}