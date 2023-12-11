#include <bits/stdc++.h>
using namespace std;

#define ctz __builtin_ctz
#define clz __builtin_clz

const int N = 3005;
int sq[12][N][N], tr[12][N][N];

int querysq(int x, int y, int l){
    if (l == 0) return -1e9;
    int k = 31 - clz(l), p = 1 << k;
    return max({sq[k][x][y], sq[k][x - l + p][y],
                sq[k][x - l + p][y + l - p],
                sq[k][x][y + l - p]});
}

int querytr(int x, int y, int l){
    int k = 31 - clz(l), p = 1 << k;
    return max({tr[k][x - l + p][y],
                tr[k][x][y + l - p],
                querysq(x, y, l - p)});
}

int main(){
    freopen("hextri.inp", "r", stdin);
    freopen("hextri.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, l; cin >> n >> l;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> sq[0][i][j];
            tr[0][i][j] = sq[0][i][j];
        }
    }
    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                if (i - (1 << k) >= 0
                && j + (1 << k) <= i + 1){
                    int p = 1 << (k - 1);
                    sq[k][i][j] = max({
                    sq[k - 1][i][j],
                    sq[k - 1][i - p][j],
                    sq[k - 1][i - p][j + p],
                    sq[k - 1][i][j + p]});
                    tr[k][i][j] = max({
                    sq[k - 1][i][j],
                    tr[k - 1][i - p][j],
                    tr[k - 1][i][j + p]});
                }
    long long res = 0;
    int t1 = 31 - clz(l), t2 = 31 - clz(l / 2);
    int t3 = 1 << t1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (i - l >= 0 && j + l <= i + 1)
                res += querytr(i, j, l);
    cout << res << '\n';
}