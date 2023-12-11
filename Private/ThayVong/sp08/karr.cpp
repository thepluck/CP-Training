#include <bits/stdc++.h>
using namespace std;

int cnt[11], a[305][305];
int total[11][305][305];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("karr.inp", "r", stdin);
    freopen("karr.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            total[a[i][j]][i][j] = 1;
        }
    for (int dgt = 0; dgt <= 9; dgt++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                total[dgt][i][j] += total[dgt][i - 1][j];
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            memset(cnt, 0, sizeof cnt);
            for (int x = 1, y = 0; x <= m; x++){
                bool flag = 0;
                for (int dgt = 0; dgt <= 9; dgt++){
                    cnt[dgt] -= total[dgt][j][x - 1] - total[dgt][i - 1][x - 1];
                    if (cnt[dgt] >= k) flag = true;
                }
                while (y < m && !flag){
                    for (int dgt = 0; dgt <= 9; dgt++){
                        cnt[dgt] += total[dgt][j][y + 1] - total[dgt][i - 1][y + 1];
                        if (cnt[dgt] >= k) flag = true;
                    }
                    y++;
                }
                if (flag) ans += m - y + 1;
            }
        }
    }
    cout << ans << '\n';
}