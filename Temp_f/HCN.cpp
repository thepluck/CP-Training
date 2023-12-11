#include <bits/stdc++.h>
using namespace std;
#define int long long

struct rec{
    int x1, y1, x2, y2;
};

long long intersect(rec a, rec b){
    int w = min(a.x2, b.x2) - max(a.x1, b.x1);
    int h = min(a.y2, b.y2) - max(a.y1, b.y1);
    if (w <= 0 || h <= 0) return 0;
    return 1ll * w * h;
}

rec a[10000];

signed main(){
    freopen("HCN.inp", "r", stdin);
    freopen("HCN.out", "w", stdout);
    int n; cin >> n; int res = 0, id1, id2;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        for (int j = i - 1; j > 0; j--){
            int temp = intersect(a[j], a[i]);
            if (temp > res){
                res = temp; id1 = j; id2 = i;
            }
        }
    }
    cout << res << '\n';
    cout << id1 << ' ' << id2;
}