#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 200005;
const int inf = 0x3f3f3f3f;
int a[N], dp[21][1 << 20];

int cmn(int m, int x, int y) {
    for (int i = m; i > 0; i--)
        if ((x & ((1 << i) - 1)) == (y >> m - i))
            return m - i;
    return m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, sum; cin >> n; string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s)
            a[i] = a[i] * 2 + c - '0';
    }
    m = s.size(); sum = m; int add = inf;
    if (n == 1) {
        cout << m << '\n'; return 0;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < (1 << i); j++)
            dp[i][j] = m;
    for (int i = 1; i < n; i++) {
        int tmp = cmn(m, a[i - 1], a[i]);
        int mn = inf; sum += tmp;
        for (int j = 0; j <= m; j++)
            chkmin(mn, dp[j][a[i] >> m - j] + m - j - tmp);
        for (int j = 0; j <= m; j++)
            chkmin(dp[j][a[i - 1] & ((1 << j) - 1)], mn);
    }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < (1 << i); j++)
            chkmin(add, dp[i][j]);
    cout << sum + add << '\n';
}