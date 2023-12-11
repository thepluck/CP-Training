#include <bits/stdc++.h>
using namespace std;
 
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
const int N = 3e5 + 5;
const int C = 1e5 + 5;
int seg[N << 2], a[N];
int lo[N << 2], hi[N << 2];
vector <int> pos[C];
 
int cnt_occ(int l, int r, int c){
    if (c == 0) return 0;
    return ub(all(pos[c]), r) - lb(all(pos[c]), l);
}
 
void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        seg[i] = a[l]; return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    if (cnt_occ(l, r, seg[i << 1]) > r - m)
        seg[i] = seg[i << 1];
    if (cnt_occ(l, r, seg[i << 1 | 1]) > r - m)
        seg[i] = seg[i << 1 | 1];
}
 
int query(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return seg[i];
    int cl = query(i << 1, l, r);
    int cr = query(i << 1 | 1, l, r);
    if (cnt_occ(l, r, cl) > (r - l + 1) / 2) return cl;
    if (cnt_occ(l, r, cr) > (r - l + 1) / 2) return cr;
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; pos[a[i]].push_back(i);
    }
    build(1, 1, n); int q, l, r; cin >> q;
    while (q--){
        cin >> l >> r;
        int color = query(1, l, r);
        if (color > 0) cout << "yes " << color << '\n';
        else cout << "no\n";
    }
}