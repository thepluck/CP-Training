#include <bits/stdc++.h>
using namespace std;

struct node{
    int sa, sb, sc, sd;
};

const int N = 1005;
int a[N][N], t[N];
node f[N], g[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("divboard.inp", "r", stdin);
    freopen("divboard.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        int pos, sum = 0, total = 0;
        for (int j = 1; j <= m; j++){
            t[j] += a[i][j]; total += t[j];
        }
        for (int j = 1; j <= m; j++){
            sum += t[j]; 
            if (sum >= total / 2){
                pos = j; break;
            }
        }
        f[i] = {sum, total - sum, sum - t[pos], total - sum + t[pos]};
        //cout << i << ' ' << f[i].sa << ' ' << f[i].sb << ' ' << f[i].sc << ' ' << f[i].sd << '\n';
    }
    memset(t, 0, sizeof t);
    for (int i = n; i >= 1; i--){
        int pos, sum = 0, total = 0;
        for (int j = 1; j <= m; j++){
            t[j] += a[i][j]; total += t[j];
        }
        for (int j = 1; j <= m; j++){
            sum += t[j]; 
            if (sum >= total / 2){
                pos = j; break;
            }
        }
        g[i] = {sum, total - sum, sum - t[pos], total - sum + t[pos]};
        //cout << i << ' ' << g[i].sa << ' ' << g[i].sb << ' ' << g[i].sc << ' ' << g[i].sd << '\n';
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i < n; i++){
        ans = min(ans, max({f[i].sa, f[i].sb, g[i + 1].sa, g[i + 1].sb}) - min({f[i].sa, f[i].sb, g[i + 1].sa, g[i + 1].sb}));
        ans = min(ans, max({f[i].sa, f[i].sb, g[i + 1].sc, g[i + 1].sd}) - min({f[i].sa, f[i].sb, g[i + 1].sc, g[i + 1].sd}));
        ans = min(ans, max({f[i].sc, f[i].sd, g[i + 1].sa, g[i + 1].sb}) - min({f[i].sc, f[i].sd, g[i + 1].sa, g[i + 1].sb}));
        ans = min(ans, max({f[i].sc, f[i].sd, g[i + 1].sc, g[i + 1].sd}) - min({f[i].sc, f[i].sd, g[i + 1].sc, g[i + 1].sd}));
    }
    cout << ans << '\n';
}