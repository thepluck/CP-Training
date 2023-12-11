#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int ax[N * 2][N * 2], a[1000005];
int dx[] = {0, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 0, -1, -1, 0};
bitset <N> ans, cc[N], lmao[2 * N][2 * N][6];

int main(){
    freopen("hexa.inp", "r", stdin);
    freopen("hexa.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    while (q--){
        int x; cin >> x; a[x]++;
    }
    int x = 1, y = 1; long long res = 0;
    for (int i = n; i > 0; i--){
        int run = 3 * i * i - 3 * i + 1;
        for (int k = 0; k < 6; k++){
            for (int j = 0; j < i; j++){
                ax[x][y] = a[run++] ^ 1;
                x += dx[k]; y += dy[k];
            }
        }
        x++; y++;
    }
    ax[n + 1][n + 1] = a[0] ^ 1;
    for (int i = 1; i <= n + 1; i++){
        cc[i] = cc[i - 1] << 1;
        cc[i][0] = 1;
    }
    x = 1; y = 1;
    for (int i = n; i > 0; i--){
        for (int k = 0; k < 6; k++){
            for (int j = 0; j < i; j++){
                for (int g = 0; g < 6; g++){
                    int p = x, q = y;
                    for (int l = 0; l < n; l++){
                        if (!p || !q || p > 2 * n + 1
                        || q > 2 * n + 1) break;
                        lmao[x][y][g][l] = ax[p][q];
                        p += dx[g]; q += dy[g];
                    }
                }
                x += dx[k]; y += dy[k];
            }
        }
        x++; y++;
    }
    x = n + 1; y = n + 1;
    for (int g = 0; g < 6; g++){
        int p = x, q = y;
        for (int l = 0; l < n; l++){
            if (!p || !q || p > 2 * n + 1
            || q > 2 * n + 1) break;
            lmao[x][y][g][l] = ax[p][q];
            p += dx[g]; q += dy[g];
        }
    }
    x = 1; y = 1;
    for (int i = n; i > 0; i--){
        for (int k = 0; k < 6; k++){
            for (int j = 0; j < i; j++){
                for (int l = 1; l <= n; l++){
                    int p = x, q = y; ans = cc[l];
                    for (int g = 0; g < 6; g++){
                        if (!p || !q || p > 2 * n + 1
                        || q > 2 * n + 1){
                            ans.reset(); break;
                        }
                        ans &= lmao[p][q][g];
                        p += l * dx[g]; q += l * dy[g];
                    }
                    res += ans.count();
                }
                x += dx[k]; y += dy[k];
            }
        }
        x++; y++;
    }
    x = n + 1; y = n + 1;
    for (int l = 1; l <= n; l++){
        int p = x, q = y; ans = cc[l];
        for (int g = 0; g < 6; g++){
            if (!p || !q || p > 2 * n + 1
            || q > 2 * n + 1){
                ans.reset(); break;
            }
            ans &= lmao[p][q][g];
            p += l * dx[g]; q += l * dy[g];
        }
        res += ans.count();
    }
    cout << res << '\n';
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
}