#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int dp[N], a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n; fill_n(dp + 1, n, 0);
        for (int i = 1; i <= n; cin >> a[i++]);
        for (int i = 1; i <= n; i++){
            dp[i]++;
            for (int j = 2 * i; j <= n; j += i)
                if (a[j] > a[i]) dp[j] = max(dp[j], dp[i]);
        }
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
    }
}