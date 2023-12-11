#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
struct seg{
    int l, r, cnt, len;
} node[N << 2];
struct inp{
    int x, l, r, type;
} a[20005];
long long ans = 0;

bool cmp(const inp &ls, const inp &rs){
    return ls.x < rs.x || (ls.x == rs.x && ls.type < rs.type);
}

void build(int i, int l, int r){
    node[i] = {l, r, 0, 0}; if (l == r) return;
    int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
}

void update(int i, int l, int r, int type){
    if (node[i].r < l || node[i].l > r) return;
    if (node[i].l >= l && node[i].r <= r){
        node[i].cnt += type;
        if (type > 0) node[i].len = node[i].r - node[i].l + 1;
        else if (node[i].cnt == 0){
            if (node[i].l < node[i].r) 
                node[i].len = node[i << 1].len + node[i << 1 | 1].len;
            else node[i].len = 0;
        }
        return;
    }
    update(i << 1, l, r, type); update(i << 1 | 1, l, r, type);
    if (node[i].cnt == 0 && node[i].l < node[i].r)
        node[i].len = node[i << 1].len + node[i << 1 | 1].len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x1, x2, y1, y2, k = 0; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1 + 1, y2, 1};
        a[n + i] = {x2, y1 + 1, y2, -1};
        k = max(k, y2);
    }
    build(1, 1, k); sort(a + 1, a + (n << 1 | 1), cmp);
    for (int i = 1; i <= (n << 1); i++){
        ans += 1ll * node[1].len * (a[i].x - a[i - 1].x);
        update(1, a[i].l, a[i].r, a[i].type);   
    }
    cout << ans << '\n';
}