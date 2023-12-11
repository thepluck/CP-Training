//https://atcoder.jp/contests/arc100/tasks/arc100_c
#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 18;
int dp[1 << N], res[1 << N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < (1 << n); i++)
        cin >> dp[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (j >> i & 1) {
                chkmax(res[j], dp[j] + dp[j ^ (1 << i)]);
                chkmax(dp[j], dp[j ^ (1 << i)]);
            }
    for (int i = 1; i < (1 << n); i++) {
        chkmax(res[i], res[i - 1]);
        cout << res[i] << '\n';
    }
}