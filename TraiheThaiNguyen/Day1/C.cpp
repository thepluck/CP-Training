#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int N = 3e3 + 5;

ll f[N][N], g[N][N], x[N];
char s[N]; int n;

int main(){
    cin >> (s + 1); n = strlen(s + 1); ll res = 0;
    for (int l = 0; l < n; l++)
        for (int i = 1; i + l <= n; i++){
            f[i][i + l] = f[i][i + l - 1] + f[i + 1][i + l];
            if (s[i] == s[i + l]) f[i][i + l]++;
            else f[i][i + l] -= f[i + 1][i + l - 1];
            f[i][i + l] %= mod;
            if (f[i][i + l] < 0) f[i][i + l] += mod;
        }
    for (int l = n - 1; ~l; l--)
        for (int i = 1; i + l <= n; i++){
            g[i][i + l] = g[i][i + l + 1] + g[i - 1][i + l];
            if (s[i] == s[i + l]) g[i][i + l]++;
            else g[i][i + l] -= g[i - 1][i + l + 1];
            g[i][i + l] %= mod;
            if (g[i][i + l] < 0) g[i][i + l] += mod;
        }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (s[i] == s[j]){
                ll tmp = f[i + 1][j - 1] + 1;
                tmp *= (g[i - 1][j + 1] + 1); tmp %= mod;
                x[i] = (x[i] + tmp) % mod;
                if (i != j) x[j] = (x[j] + tmp) % mod;
            }
    for (int i = 1; i <= n; i++) res ^= (x[i] * i % mod);
    cout << res << '\n';
}
