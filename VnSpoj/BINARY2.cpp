#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;

int main(){
    int n, k; cin >> n >> k;
    vector <int> dp(n + 1);
    dp[0] = 2; dp[1] = 2;
    for (int i = 2; i <= k; i++)
        dp[i] = 2 * dp[i - 1] % mod;
    for (int i = k + 1; i <= n; i++){
        dp[i] = (2 * dp[i - 1] - dp[i - k - 1]) % mod;
        if (dp[i] < 0) dp[i] += mod;
    }
    cout << dp[n]; 
    /**
     * |> |> ->> || ++ <<->> ^= @ -| _|_ && #{}
     * <|> :> <||| [| <> => => <== != <$>
     * */
}