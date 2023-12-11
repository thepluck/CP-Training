#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int cnt[N * 4], lo[N * 4], hi[N * 4], lazy[N * 4];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r; cnt[i] = r - l + 1;
    if (l == r) return; int m = (l + r) >> 1;
    build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
}

void lazy_down(int i){
    if (lazy[i] == 0) return;
    if (lazy[i] == 1) cnt[i] = 0;
    else cnt[i] = hi[i] - lo[i] + 1;
    if (lo[i] != hi[i])
        lazy[i << 1] = lazy[i << 1 | 1] = lazy[i];
    lazy[i] = 0;
}

void update(int i, int l, int r, int t){
    lazy_down(i); if (l > r) return;
    if (lo[i] > r || hi[i] < l) return;
    if (lo[i] >= l && hi[i] <= r){
        if (t == 1) cnt[i] = 0;
        else cnt[i] = hi[i] - lo[i] + 1;
        if (lo[i] != hi[i])
            lazy[i << 1] = lazy[i << 1 | 1] = t;
        return;
    }
    update(i << 1, l, r, t); update(i << 1 | 1, l, r, t);
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
}

int popcnt(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r) return cnt[i];
    return popcnt(i << 1, l, r) + popcnt(i << 1 | 1, l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, l, r; cin >> n >> q; char cmd;
    vector <int> lett(n); int cur = 1, sum = 0;
    for (auto &x : lett){
        cin >> x; sum += x;
    }
    build(1, 1, sum - 1); sum = 0;
    for (auto x : lett){
        sum += x; update(1, cur, sum - 1, 1); cur = sum + 1;
    }
    while (q--){
        cin >> cmd;
        if (cmd == 'J'){
            cin >> l >> r; update(1, l, r - 1, 1);
        }
        if (cmd == 'D'){
            cin >> l >> r; update(1, l, r - 1, 2);
        }
        if (cmd == 'C') cout << cnt[1] + 1 << '\n';
    }
}