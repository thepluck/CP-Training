#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 1000005;

int mn[N][2], mx[N][2], a[N][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i][0];
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i][1];
    mn[1][1] = mx[1][1] = 1;
    for (int i = 2; i <= n * 2; i++) {
        mn[i][0] = mn[i][1] = 2 * n + 1;
        for (int c1 = 0; c1 < 2; c1++)
            for (int c2 = 0; c2 < 2; c2++)
                if (a[i - 1][c1] <= a[i][c2]) {
                    cmin(mn[i][c2], mn[i - 1][c1] + c2);
                    cmax(mx[i][c2], mx[i - 1][c1] + c2);
                }
    }
    int c, cnt = n;
    if (mn[2 * n][0] <= n && n <= mx[2 * n][0]) c = 0;
    else if (mn[2 * n][1] <= n && n <= mx[2 * n][1]) c = 1;
    else return cout << "-1\n", 0;
    n *= 2; string ans(n, 'A');
    while (true) {
        cnt -= c; ans[n - 1] = 'A' + c;
        if (n == 1) break;
        if (a[n][c] >= a[n - 1][1] && mn[n - 1][1] <= cnt
        && cnt <= mx[n - 1][1]) c = 1;
        else c = 0;
        n--;
    }
    cout << ans << '\n';
}