
// Problem : E. DIVSEQQ - Chia đoạn
// Contest : Codeforces - OI set 6
// URL : https://codeforces.com/group/FLVn1Sc504/contest/274813/problem/E
// Memory Limit : 256 MB
// Time Limit : 400 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LG = 18;

int p[LG][N], a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(p, -1, sizeof p);
    int s = 0, j = 0, m, n, q;
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; s += a[i];
        while (s > m) s -= a[++j];
        p[0][i] = j;
    }
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++)
            p[k][i] = p[k - 1][p[k - 1][i]];
    while (q--) {
        int i; cin >> i >> j;
        for (int k = LG - 1; ~k; k--)
            if (j >= (1 << k) && ~p[k][i]) {
                j -= 1 << k; i = p[k][i];
            }
        cout << i + 1 << '\n';
    }
}