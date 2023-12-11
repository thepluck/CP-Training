#include <bits/stdc++.h>
using namespace std;

const int N = 305;
bitset <N> l[N][N], r[N][N], u[N][N], d[N][N];
int a[N][N]; bitset <N> c[N];

int main(){
    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    while (k--){
        int i, j; cin >> i >> j; a[i][j] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            l[i][j] = l[i][j - 1] << 1;
            u[i][j] = u[i - 1][j] << 1;
            if (!a[i][j]){
                l[i][j][0] = u[i][j][0] = 1;
            }
        }
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--){
            r[i][j] = r[i][j + 1] << 1;
            d[i][j] = d[i + 1][j] << 1;
            if (!a[i][j]){
                r[i][j][0] = d[i][j][0] = 1;
            }
        }
    for (int i = 1; i < min(n, m); i++){
        c[i] = c[i - 1] << 1; c[i][0] = 1;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            for (int h = 1;
            h <= min(n - i, m - j); h++){
                res += (r[i][j] & d[i][j + h] &
                l[i + h][j + h] & u[i + h][j] & c[h]).
                count();
            }
    cout << res << '\n';
}