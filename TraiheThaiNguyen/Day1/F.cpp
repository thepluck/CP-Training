#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fi  first
#define se  second
#define LL  unsigned long long
#define uint unsigned int
#define pb  push_back
#define eb  emplace_back
#define bit(s,i) ((s >> i) & 1)
#define off(s,i) (s & (~ (1 << i)))
#define ii pair <LL , LL>
#define iii1 pair <ii , int>
#define iii2 pair <int , ii>
#define TASK "Walter White and Retangle"
using   namespace   std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f;
const int maxn = 3005;
int t , a[maxn][maxn] , h[maxn] , l[maxn] , r[maxn] , d[maxn];
///--------------------------
void readf() {
    cin >> t;
}
///--------------------------
void solve() {
    for (int lz = 1 ; lz <= t ; ++lz) {
        memset(h,0,sizeof(h));
        int m , n;
        cin >> m >> n;
        for (int i = 1 ; i <= m ; ++i)
        for (int j = 1 ; j <= n ; ++j) cin >> a[i][j];
        int ans = 0;
        for (int i = 1 ; i <= m ; ++i) {
            if (i == 1) {
                for (int j = 1 ; j <= n ; ++j) {
                    h[j] = 1;
                    d[j] = 0;
                }
            } else {
                for (int j = 1 ; j <= n ; ++j)
                if (a[i][j] - a[i-1][j] == d[j]) h[j]++;
                else {
                    h[j] = 2;
                    d[j] = a[i][j] - a[i-1][j];
                }
            }
            for (int j = 1 ; j <= n ; ++j) {
                ans = max(ans , h[j]);
                int sai = a[i][j+1] - a[i][j];
                int saa = d[j+1] - d[j];
                int pos = 0;
                if (j == n) {
                    ans = max(ans , h[j]);
                    continue;
                }
                for (int k = j + 1 ; k <= n ; ++k) {
                    if (a[i][k] - a[i][k-1] != sai || d[k] - d[k-1] != saa) {
                        pos = k;
                        break;
                    }
                    if (k == n) pos = n + 1;
                }
                for (int k = j ; k < pos ; ++k) {
                    l[k] = k - 1;
                    while (l[k] >= j && h[l[k]] >= h[k]) l[k] = l[l[k]];
                }
                for (int k = pos - 1 ; k >= j ; --k) {
                    r[k] = k + 1;
                    while (r[k] < pos && h[r[k]] >= h[k]) r[k] = r[r[k]];
                }
                for (int k = j ; k < pos ; ++k) {
                    ans = max(ans , h[k] * (r[k] - l[k] - 1));
                    ans = max(ans , h[k]);
                    ans = max(ans , k - j + 1);
                    r[k] = l[k] = 0;
                }
                ans = max(ans , pos - j);
                j = pos - 2;
            }
            for (int j = 1 ; j <= n ; ++j) {
                int sai = a[i][j+1] - a[i][j];
                int pos = 0;
                if (j == n) break;
                for (int k = j + 1 ; k <= n ; ++k) {
                    if (a[i][k] - a[i][k-1] != sai) {
                        pos = k;
                        break;
                    }
                    if (k == n) pos = n + 1;
                }
                ans = max(ans , pos - j);
                j = pos - 2;
            }
        }
        cout << ans << '\n';
    }
}
///--------------------------
int main() {
   #ifdef BDP0509
       freopen(TASK".inp", "r", stdin);
       freopen(TASK".out", "w", stdout);
   #endif // ONLINE_JUDGE
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   readf();
   solve();
}
