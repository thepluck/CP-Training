#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using ii = pair <int, int>;
const int N = 300005;
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;

struct node{
    int l, r, minw, maxw, minb, maxb;
    int minwp, maxwp, val, valwp;

    void update(const node &p, const node &q){
        if (p.minw <= q.minw){
            minw = p.minw; minwp = p.minwp;
        }
        else {
            minw = q.minw; minwp = q.minwp;
        }
        if (p.maxw >= q.maxw){
            maxw = p.maxw; maxwp = p.maxwp;
        }
        else {
            maxw = q.maxw; maxwp = q.maxwp;
        }
        minb = min(p.minb, q.minb);
        maxb = max(p.maxb, q.maxb);
        if (p.val <= q.val){
            val = p.val; valwp = p.valwp;
        }
        else {
            val = q.val; valwp = q.valwp;
        }
        if (q.minb - p.maxw < val){
            val = q.minb - p.maxw;
            valwp = p.maxwp;
        }
        if (q.minw - p.maxb < val){
            val = q.minw - p.maxb;
            valwp = q.minwp;
        }
    }
};

node s[N << 2]; int a[N];

void build(int i, int l, int r){
    s[i].l = l; s[i].r = r;
    if (l == r){
        s[i].maxw = s[i].minw = a[l];
        s[i].maxwp = s[i].minwp = l;
        s[i].minb = inf; s[i].maxb = ninf;
        s[i].val = inf; return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    s[i].update(s[i << 1], s[i << 1 | 1]);
}

void update(int i, int p){
    if (s[i].l > p || s[i].r < p) return;
    if (s[i].l == s[i].r){
        s[i].minw = inf; s[i].maxw = ninf;
        s[i].minb = s[i].maxb = a[p];
        return;
    }
    update(i << 1, p); update(i << 1 | 1, p);
    s[i].update(s[i << 1], s[i << 1 | 1]);
}

void solve(){
    int n; cin >> n; ll res = 0;
    for (int i = 1; i <= n; cin >> a[i++]);
    build(1, 1, n); update(1, 1);
    for (int i = 1; i < n; i++){
        res += s[1].val;
        update(1, s[1].valwp);
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}