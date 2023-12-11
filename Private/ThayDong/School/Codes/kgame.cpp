#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

bool f[N + 1][105], g[N + 1];
int kmp[N + 1];

int main() {
    //freopen("kgame.inp", "r", stdin);
    //freopen("kgame.out", "w", stdout);
    int n, k; cin >> n >> k;
    if ((k + 1) & 1) {
        cout << (n % (k + 1) ? 1 : 0) << '\n'; return 0;
    }
    vector <int> cc;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            f[i][j] = 1;
            if (i != j) {
                for (int l = 1; l <= min(i - j, k); l++)
                    if (l != j) f[i][j] &= !f[i - j][l];
            }
            g[i] |= f[i][j];    
        }
    }
    int cyc;
    for (int i = 2, j = 0; i <= N; i++) {
        while (j && g[i] != g[j + 1]) j = kmp[j];
        if (g[i] == g[j + 1]) j++; kmp[i] = j;
        if(kmp[i] >= k && i % (i - kmp[i]) == 0)
            cyc = i - kmp[i];
    }
    n %= cyc; if (n == 0) n = cyc;
    cout << g[n] << '\n';
    //cerr << cyc << '\n';
}
