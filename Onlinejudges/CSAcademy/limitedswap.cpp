#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;
const int N = 1e5 + 5;
const int ninf = 0xc0c0c0c0;
int maxid[N * 4], maxv[N * 4], cnt[4 * N];
int lo[N * 4], hi[N * 4], val[N];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if (l == r){
        cnt[i] = 1; maxid[i] = l; 
        maxv[i] = val[l]; return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m); 
    build(i * 2 + 1, m + 1, r);
    maxv[i] = max(maxv[i * 2], maxv[i * 2 + 1]);
    if (maxv[i] == maxv[i * 2])
        maxid[i] = maxid[i * 2];
    else maxid[i] = maxid[i * 2 + 1];
    cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
}

void update(int i, int p){
    if (lo[i] > p || hi[i] < p) return;
    if (lo[i] == hi[i]){
        maxv[i] = ninf; cnt[i] = 0; return;
    }
    update(i * 2, p); update(i * 2 + 1, p);
    maxv[i] = max(maxv[i * 2], maxv[i * 2 + 1]);
    if (maxv[i] == maxv[i * 2])
        maxid[i] = maxid[i * 2];
    else maxid[i] = maxid[i * 2 + 1];
    cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
}

int get_pos(int i, int k){
    if (lo[i] == hi[i]) return lo[i];
    if (cnt[i * 2] >= k) return get_pos(i * 2, k);
    return get_pos(i * 2 + 1, k - cnt[i * 2]);
}

ii get_max(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return {ninf, 0};
    if (lo[i] >= l && hi[i] <= r) 
        return {maxv[i], maxid[i]};
    ii l_max = get_max(i * 2, l, r);
    ii r_max = get_max(i * 2 + 1, l, r);
    if (l_max.fi >= r_max.fi) return l_max;
    return r_max;
}

int get_cnt(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return cnt[i];
    return get_cnt(i * 2, l, r) 
            + get_cnt(i * 2 + 1, l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++){
        int pos = get_pos(1, min(k + 1, cnt[1]));
        ii tmp = get_max(1, 1, pos);
        cout << tmp.fi << ' '; update(1, tmp.se);
        k -= get_cnt(1, 1, tmp.se);
    }
}