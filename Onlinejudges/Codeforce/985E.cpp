#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

const int N = 5e5 + 5;
int a[N], dp[N], pre[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, d; cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1); dp[0] = 1; pre[0] = 1;
    for (int i = 1, j = 0; i <= n; i++){
        while (j < i && a[i] - a[j] > d) j++;
        if (i - k + 1 < j || i < k) dp[i] = 0;
        else if (j >= 2) dp[i] = ((pre[i - k] - pre[j - 2]) > 0);
        else dp[i] = (pre[i - k] > 0);
        pre[i] = pre[i - 1] + dp[i];
    } 
    cout << (dp[n] > 0 ? "YES\n" : "NO\n");
}