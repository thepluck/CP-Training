#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n; ll dp[N], s[N], a, b;

string solve(){
    for (int i = 1; i <= n; i++){
        cin >> s[i]; s[i] += s[i - 1];
    }
    ll minv = s[n];
    for (int i = n - 1; ~i; i--){
        dp[i] = minv - s[i];
        minv = min(minv, max(s[i], a + b - dp[i] + 1));
    }
    if (dp[0] <= a) return "ALICE";
    return "BOB";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> a >> b)
        cout << solve() << '\n';
}