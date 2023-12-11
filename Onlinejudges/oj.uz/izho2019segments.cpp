#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 5e5 + 5;

ll sum[N]; int dp[N], pos[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cmax(pos[i], pos[i - 1]);
        dp[i] = dp[pos[i]] + 1;
        ll dif = sum[i] - sum[pos[i]];
        int lo = i + 1, hi = n, p = 0;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (sum[mi] - sum[i] >= dif) {
                hi = mi - 1; p = mi;
            }
            else lo = mi + 1;
        }
        pos[p] = i;
    }
    cout << dp[n] << '\n';
}