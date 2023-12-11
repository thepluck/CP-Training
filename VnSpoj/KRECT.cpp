#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int total[26][N][N], cnty[26], cntz[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); int ans = 0;
    int n, m, k; char cc; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> cc; total[cc - 'A'][i][j] = 1;
        }
    for (int c = 0; c < 26; c++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                total[c][i][j] += total[c][i - 1][j];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++){
            memset(cnty, 0, sizeof cnty);
            memset(cntz, 0, sizeof cntz);
            for (int x = 1, y = 0, z = 0; x <= m; x++){
                int cury = 0, curz = 0;
                for (int c = 0; c < 26; c++){
                    cnty[c] -= total[c][j][x - 1] - total[c][i - 1][x - 1];
                    cntz[c] -= total[c][j][x - 1] - total[c][i - 1][x - 1];
                    cury += cnty[c] > 0; curz += cntz[c] > 0;
                }
                while (y <= m && cury < k){
                    for (int c = 0; c < 26; c++){
                        bool flag = (cnty[c] == 0);
                        cnty[c] += total[c][j][y + 1] - total[c][i - 1][y + 1];
                        if (flag && cnty[c] > 0) cury++;
                    }
                    y++;
                }
                while (z <= m && curz <= k){
                    for (int c = 0; c < 26; c++){
                        bool flag = (cntz[c] == 0);
                        cntz[c] += total[c][j][z + 1] - total[c][i - 1][z + 1];
                        if (flag && cntz[c] > 0) curz++;
                    }
                    z++;
                }
                ans += z - y;
            }
        }
    cout << ans << '\n';
}