#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T, class _T>
bool chkmax(T& x, const _T& y){
    return x < y ? x = y, true : false;
}

template <class T, class _T>
bool chkmin(T& x, const _T& y){
    return x > y ? x = y, true : false;
}

int f[105][105];
const int inf = 0x3f3f3f3f;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(f, 0x17, sizeof (int) * 105 * 105);
    if (fopen("input.txt", "r"))
        freopen("input.txt", "r", stdin);
}

int main(){
    init(); int n, s[4];
    /// read data
    cin >> n >> s[0] >> s[1] >> s[2] >> s[3];
    for (int u, v, w; cin >> u >> v >> w; )
        f[u][v] = f[v][u] = w;
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    /// Floyd
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                chkmin(f[i][j], f[i][k] + f[k][j]);
    sort(s, s + 4); int res = inf;
    do {
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++){
                int total = f[u][v];
                total += f[u][s[0]];
                total += f[u][s[1]];
                total += f[v][s[2]];
                total += f[v][s[3]];
                chkmin(res, total);
            }
    }
    while (next_permutation(s, s + 4));
    cout << res;
}
