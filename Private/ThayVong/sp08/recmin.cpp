#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 1005;

int a[N][M], t[M], n, m, s;

int main(){
    freopen("recmin.inp", "r", stdin);
    freopen("recmin.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s; 
    int ans = (m + 1) * (n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        memset(t, 0, sizeof t);
        for (int j = i; j <= n; j++){
            for (int x = 1; x <= m; x++) t[x] += a[j][x];
            for (int x = 1, y = 0, cur = 0; x <= m; x++){
                cur -= t[x - 1];
                while (y < m && cur < s) cur += t[++y];
                if (cur == s) ans = min(ans, (j - i + 1) * (y - x + 1));
            }
        }
    }
    if (ans == (n + 1) * (m + 1)) cout << "-1\n";
    else cout << ans << '\n';
}