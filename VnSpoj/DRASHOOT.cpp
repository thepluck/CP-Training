#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int ninf = 0xc0c0c0c0;
struct node{
    int l, r, cnt1, cnt2, val;
    node(): cnt1(0), cnt2(0){}
} seg[N << 2];
int a[N], n, q;

void build(int i, int l, int r){
    seg[i].l = l; seg[i].r = r;
    if (l == r){
        seg[i].val = a[l]; seg[i].cnt2 = 1; return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    seg[i].val = max(seg[i << 1].val, seg[i << 1 | 1].val);
    seg[i].cnt2 = seg[i << 1].cnt2 + seg[i << 1 | 1].cnt2;
}

void update(int i, int pos){
    if (seg[i].l > pos || seg[i].r < pos) return;
    if (seg[i].l == seg[i].r){
        seg[i].val = ninf; seg[i].cnt1 = 1; seg[i].cnt2 = 0;
        return;
    }
    update(i << 1, pos); update(i << 1 | 1, pos);
    seg[i].val = max(seg[i << 1].val, seg[i << 1 | 1].val);
    seg[i].cnt1 = seg[i << 1].cnt1 + seg[i << 1 | 1].cnt1;
    seg[i].cnt2 = seg[i << 1].cnt2 + seg[i << 1 | 1].cnt2;
}

int get_pos1(int i, int k){
    if (seg[i].l == seg[i].r) return seg[i].l;
    if (seg[i << 1].cnt1 >= k) return get_pos1(i << 1, k);
    else return get_pos1(i << 1 | 1, k - seg[i << 1].cnt1);
}

int get_pos2(int i, int k){
    if (seg[i].l == seg[i].r) return seg[i].l;
    if (seg[i << 1].cnt2 >= k) return get_pos2(i << 1, k);
    else return get_pos2(i << 1 | 1, k - seg[i << 1].cnt2);
}

int query(int i, int l, int r){
    if (seg[i].l > r || seg[i].r < l || l > r) return ninf;
    if (seg[i].l >= l && seg[i].r <= r) return seg[i].val;
    return max(query(i << 1, l, r), query(i << 1 | 1, l, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int l, r, k; cin >> n; char cmd;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n); cin >> q;
    while (q--){
        cin >> cmd;
        if (cmd == 'S'){
            cin >> k; update(1, get_pos2(1, k));
        }
        else {
            int posl, posr; cin >> l >> r;
            if (l == 0) posl = 0; else posl = get_pos1(1, l);
            posr = get_pos1(1, r + 1);
            int val = query(1, posl + 1, posr);
            if (val == ninf) cout << "NONE\n";
            else cout << val << '\n';
        }
    }
}