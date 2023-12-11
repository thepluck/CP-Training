#include <bits/stdc++.h>

using namespace std;

long long dp[20][4];
vector <int> digit;

long long calc(int pos, int cnt, bool lt) {
    if (cnt > 3) return 0;
    if (pos < 0) return 1;
    if (lt && dp[pos][cnt] >= 0)
        return dp[pos][cnt];
    long long res = 0;
    int lim = lt ? 9 : digit[pos];
    for (int dig = 0; dig <= lim; dig++)
        res += calc(pos - 1, cnt +
        (dig > 0), lt || dig < digit[pos]);
    if (lt) dp[pos][cnt] = res;
    return res;
}

long long calc(long long x) {
    digit.clear();
    while (x > 0) {
        digit.push_back(x % 10); x /= 10;
    }
    return calc(digit.size() - 1, 0, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    int t; cin >> t;
    while (t--) {
        long long l, r; cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
}