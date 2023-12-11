#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int inf = 1e9;
using ii = pair <int, int>;
vector <vector <int>> f, a;
vector <vector <ii>> oper;
int n, m, k, r, c, x, y;

int solve(int val){
    int res = 0;
    f = vector <vector <int>> (n + 2, vector <int> (m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            f[i][j] %= 3; if (f[i][j] < 0) f[i][j] += 3;
            int cur = (f[i][j] + a[i][j]) % 3; 
            if (cur < 0) cur += 3; if (cur == val) continue; 
            if (oper[i][j].fi == 0) return inf;
            int cnt = abs(cur - val) % 3; res += cnt;
            x = oper[i][j].fi; y = oper[i][j].se;
            f[i][j] += cnt; f[i][y + 1] -= cnt;
            f[x + 1][j] -= cnt; f[x + 1][y + 1] += cnt;
        }
    return res;
}

int main(){
    freopen("LIGHT.inp", "r", stdin);
    freopen("LIGHT.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    a.resize(n + 2, vector <int> (m + 2));
    oper.resize(n + 2, vector <ii> (m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    while (k--){
        cin >> r >> c >> x >> y; oper[r][c] = {x, y};
    }
    int res = min(solve(1), solve(2));
    if (res > 1e8) return cout << "-1", 0;
    cout << res; return 0;
}