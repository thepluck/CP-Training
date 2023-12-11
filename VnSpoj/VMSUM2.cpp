
// Problem : P. VMSUM2 - Tính tổng
// Contest : Codeforces - OI set 22
// URL : https://codeforces.com/group/FLVn1Sc504/contest/274857/problem/P
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

double f[N], g[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] + 1.0 / i;
        g[i] = f[i - 1] / i;
    }
    for (int i = 2; i < N; i++)
        for (int j = 2; i * j < N; j++)
            g[i * j] -= g[i] / j / j;
    for (int i = 3; i < N; i++)
        g[i] += g[i - 1] + 0.5;
    int n;
    while (cin >> n)
        cout << g[n] << '\n';
}