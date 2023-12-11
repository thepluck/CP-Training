#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int seg[N << 2], index[N << 2];
int lo[N << 2], hi[N << 2], a[N], cnt[N << 2];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        seg[i] = a[l]; index[i] = l; cnt[i] = 1; return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    if (seg[i << 1] <= seg[i << 1 | 1]){
        seg[i] = seg[i << 1]; index[i] = index[i << 1];
    }
    else {
        seg[i] = seg[i << 1 | 1]; index[i] = index[i << 1 | 1];
    }
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
}

void update(int i, int pos){
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i]){
        seg[i] = INT_MAX; cnt[i] = 0; return;
    }
    update(i << 1, pos); update(i << 1 | 1, pos);
    if (seg[i << 1] <= seg[i << 1 | 1]){
        seg[i] = seg[i << 1]; index[i] = index[i << 1];
    }
    else {
        seg[i] = seg[i << 1 | 1]; index[i] = index[i << 1 | 1];
    }
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
}

pair <int, int> get_id(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return {INT_MAX, -1};
    if (lo[i] >= l && hi[i] <= r) return {seg[i], index[i]};
    auto lval = get_id(i << 1, l, r);
    auto rval = get_id(i << 1 | 1, l, r);
    if (lval <= rval) return lval;
    else return rval;
}

int get_cnt(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return cnt[i];
    return get_cnt(i << 1, l, r) + get_cnt(i << 1 | 1, l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n); long long ans = 0; 
    int t = n, prev = 1;
    while (t--){
        auto val = get_id(1, prev, n);
        if (val.first == seg[1]){
            ans += get_cnt(1, prev, val.second);
            prev = val.second;
            update(1, val.second);
        }
        else {
            val = get_id(1, 1, n);
            ans += get_cnt(1, prev, n) + get_cnt(1, 1, val.second);
            update(1, val.second); prev = val.second;
        }
    }
}