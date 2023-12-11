// Problem: D. Recovering BST
// Contest: Codeforces - Codeforces Round #505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)
// URL: https://codeforces.com/problemset/problem/1025/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 705;

bool f[N][N][2], p[N][N];
int a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (__gcd(a[i], a[j]) > 1)
                p[i][j] = 1;
    for (int i = 1; i <= n; i++)
        f[i][i][0] = f[i][i][1] = 1;
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= j; k++)
                if (p[i][k] && f[i + 1][k][1]
                && f[k][j][0]) f[i][j][0] = 1;
            for (int k = i; k < j; k++)
                if (p[k][j] && f[k][j - 1][0]
                && f[i][k][1]) f[i][j][1] = 1;
        }
    string res = "No";
    for (int i = 1; i <= n; i++)
        if (f[1][i][1] && f[i][n][0])
            res = "Yes";
    cout << res << '\n';
}