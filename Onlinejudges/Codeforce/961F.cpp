#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int B = 31;

int f[N]; char s[N];
ll pw[N], hs[N];

int get_hs(int i, int j) {
    return ((hs[j] - hs[i - 1] * pw[j - i + 1] % MOD) + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    /// observation: f[i] <= f[i + 1] + 2
    int n; cin >> n >> (s + 1);
    pw[0] = 1; hs[0] = 0;
    for (int i = 1; i <= n; i++) {
        hs[i] = (hs[i - 1] * B + s[i] - 'a' + 1) % MOD;
        pw[i] = pw[i - 1] * B % MOD;
    }
    for (int i = (n + 1) / 2; i > 0; i--) {
        f[i] = min(n + 2 - 2 * i - 1, f[i + 1] + 2);
        if (!(f[i] & 1)) f[i]--;
        while (~f[i] && get_hs(i, i + f[i] - 1) !=
        get_hs(n - i - f[i] + 2, n - i + 1)) f[i] -= 2;
    }
    for (int i = 1; i <= (n + 1) / 2; i++)
        cout << f[i] << ' ';
}