#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int inf = 0x3f3f3f3f;
int f[N], g[N][N], cnt[N];
int a[N], cont[N][N], mn[N][N];

template <class X, class Y>
bool chkmax(X &p, const Y &q){
    return p < q ? p = q, 1 : 0;
}

template <class X, class Y>
bool chkmin(X &p, const Y &q){
    return p > q ? p = q, 1 : 0;
}

int cal(int i, int j){
    if (g[i][j] != inf) return g[i][j];
    if (i == j) return g[i][j] = 0;
    for (int k = i; k < j; k++){
        int tmp = cal(i, k) + cal(k + 1, j);
        if (mn[i][k] < mn[k + 1][j])
            tmp -= cont[i][k];
        else tmp -= cont[k + 1][j];
        chkmin(g[i][j], tmp + j - i + 1);
    }
    return g[i][j];
}

int main(){
    freopen("dolls.inp", "r", stdin);
    freopen("dolls.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    memset(g, 0x3f, sizeof g);
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; int maxv = 0, minv = inf, num = 0;
        memset(cnt, 0, sizeof cnt);
        for (int j = i; j > 0; j--){
            cnt[a[j]]++; if (cnt[a[j]] > 1) break;
            chkmin(minv, a[j]); chkmax(maxv, a[j]);
            mn[j][i] = minv; num++;
            for (int k = minv; k <= maxv; k++)
                if (cnt[k] == 1) cont[j][i]++;
                else break;
            if (num == maxv) f[i] = f[j - 1] + cal(j, i);
        }
    }
    if (f[n] == inf) cout << "Impossible\n";
    else cout << f[n] << '\n';
}