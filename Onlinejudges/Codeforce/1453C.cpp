// Problem: C. Triangles
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using namespace std;

const int N = 2005;

char s[N][N];
int ans[10], low[10][2], high[10][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> (s[i] + 1);
        for (int d = 0; d < 10; d++) {
            low[d][0] = low[d][1] = n + 1;
            high[d][0] = high[d][1] = -1;
            ans[d] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int d = s[i][j] - '0';
                low[d][0] = min(low[d][0], i);
                low[d][1] = min(low[d][1], j);
                high[d][0] = max(high[d][0], i);
                high[d][1] = max(high[d][1], j);
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                int d = s[i][j] - '0';
                ans[d] = max(ans[d], max(j - 1, n - j)
                * max(i - low[d][0], high[d][0] - i));
                ans[d] = max(ans[d], max(i - 1, n - i)
                * max(j - low[d][1], high[d][1] - j));
            }
        for (int d = 0; d < 10; d++)
            cout << ans[d] << " \n"[d == 9];
    }
}