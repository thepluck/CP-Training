#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int sum_digit(int x) {
    int y = 0;
    while (x > 0) {
        y += x % 10; x /= 10;
    }
    return y;
}

using ll = long long;

const int S = 135;

bool good[S];
ll dp[15][3][S][S];
vector<int> digit;

ll calc(int i, int rem, int s1, int s2) {
    if (i == digit.size())
        return rem == 0 && good[s1] && good[s2];
    ll &res = dp[i][rem][s1][s2];
    if (res >= 0) return res;
    for (int d2 = 0; d2 < 10; d2++) {
        int d1 = digit[i] - 2 * d2 - rem;
        d1 = (d1 % 10 + 10) % 10;
        res += calc(i + 1, (d1 + d2 * 2 + rem) / 10, s1 + d1, s2 + d2);
    }
    return ++res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for (int i = 2; i < S; i++)
        good[i] = is_prime(i);
    memset(dp, -1, sizeof dp);
    while (n > 0) {
        digit.push_back(n % 10); n /= 10;
    }
    cout << calc(0, 0, 0, 0) << '\n';
}