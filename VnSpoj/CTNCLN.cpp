#include <bits/stdc++.h>
using namespace std;

int dp[40005], last[40005], a[40005], id[205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m; 
    int bl_sz = int(sqrt(n));
    for (int i = 1; i <= m; i++) last[i] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int k = last[a[i]], j = 0;
        for (; id[j] - 1 != k && j <= bl_sz; j++);
        for (j--; ~j; j--) id[j + 1] = id[j];
        id[0] = i + 1; dp[i] = i; last[a[i]] = i;
        for (j = 1; j <= bl_sz; j++)
            dp[i] = min(dp[i], dp[id[j] - 1] + j * j);
    }
    cout << dp[n] << '\n'; 
}