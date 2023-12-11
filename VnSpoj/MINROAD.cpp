#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int N = 3e5 + 5;
pair <int, bool> dis[N]; int cnt[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cnt[0] = 1; int a, b, n; 
    cin >> n >> a >> b; int x, ans = INT_MAX;
    for (int i = 1; i <= n; i++){
        cin >> dis[i].fi >> x; 
        dis[i].se = x - 1;
    }
    sort(dis + 1, dis + n + 1);
    for (int i = 1, j = 0; i <= n; i++){
        cnt[dis[i - 1].se]--;
        bool flag = cnt[0] >= a && cnt[1] >= b;
        while (!flag && j < n){
            cnt[dis[++j].se]++;
            flag = cnt[0] >= a && cnt[1] >= b;
        }
        if (flag) ans = min(ans, dis[j].fi - dis[i].fi);
    }
    if (ans == INT_MAX) cout << "-1\n";
    else cout << ans << '\n';
}