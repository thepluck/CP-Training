#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using ii = pair <int, int>;

const int N = 1e6 + 5;
int x[N], z[N], t[4 * N]; ii que[N];

void update(int i, int l, int r, int p, int v){
    if (p < l || p > r) return;
    if (l == r) return void(t[i] = v);
    int m = l + r >> 1;
    update(i << 1, l, m, p, v);
    update(i << 1 | 1, m + 1, r, p, v);
    t[i] = t[i << 1] + t[i << 1 | 1];
}

int get_sum(int i, int l, int r, int lo, int hi){
    if (l > hi || r < lo || lo > hi) return 0;
    if (l >= lo && r <= hi) return t[i];
    int m = l + r >> 1;
    return get_sum(i << 1, l, m, lo, hi)
        + get_sum(i << 1 | 1, m + 1, r, lo, hi);
}

int get_pos(int k){
    if (k < 1 || t[1] < k) return -1;
    int l = 1, r = N, m, i = 1;
    while (l != r){
        m = l + r >> 1;
        if (k <= t[i * 2]){
            r = m, i *= 2;
        }
        else {
            l = m + 1; k -= t[i * 2];
            i *= 2; i++;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, q, l; vector <int> cmp;
    cin >> n >> m >> q >> l;
    for (int i = 2; i <= n; cin >> x[i++]);
    cmp.push_back(0xc0c0c0c0);
    for (int i = 1; i <= m; i++){
        cin >> z[i]; cmp.push_back(z[i]);
    }
    for (int i = 1; i <= q; i++){
        cin >> que[i].fi >> que[i].se;
        cmp.push_back(que[i].se);
    }
    sort(cmp.begin(), cmp.end());
    cmp.resize(distance(cmp.begin(),
    unique(cmp.begin(), cmp.end())));
    int cur = 0;
    for (int i = 1; i <= m; i++){
        int p = lb(cmp.begin(), cmp.end(), z[i]) - cmp.begin();
        update(1, 1, N, p, 1);
        int sum = get_sum(1, 1, N, 1, p);
        int pre = get_pos(sum - 1);
        int suf = get_pos(sum + 1);
        int st = z[i] - l;
        if (~pre) st = max(st, cmp[pre] + l + 1);
        int en = z[i] + l;
        if (~suf) en = min(en, cmp[suf] - l - 1);
        int ll = lb(x + 1, x + n + 1, st) - x;
        int rr = ub(x + 1, x + n + 1, en) - x;
        cur += max(rr - ll, 0);
    }
    cout << cur << '\n';
    for (int i = 1; i <= q; i++){
        int p = lb(cmp.begin(), cmp.end(), que[i].fi) - cmp.begin();
        int sum = get_sum(1, 1, N, 1, p);
        int pre = get_pos(sum - 1);
        int suf = get_pos(sum + 1);
        int st = que[i].fi - l;
        if (~pre) st = max(st, cmp[pre] + l + 1);
        int en = que[i].fi + l;
        if (~suf) en = min(en, cmp[suf] - l - 1);
        update(1, 1, N, p, 0);
        int ll = lb(x + 1, x + n + 1, st) - x;
        int rr = ub(x + 1, x + n + 1, en) - x;
        cur -= max(rr - ll, 0);
        p = lb(cmp.begin(), cmp.end(), que[i].se) - cmp.begin();
        update(1, 1, N, p, 1);
        sum = get_sum(1, 1, N, 1, p);
        pre = get_pos(sum - 1);
        suf = get_pos(sum + 1);
        st = que[i].se - l;
        if (~pre) st = max(st, cmp[pre] + l + 1);
        en = que[i].se + l;
        if (~suf) en = min(en, cmp[suf] - l - 1);
        ll = lb(x + 1, x + n + 1, st) - x;
        rr = ub(x + 1, x + n + 1, en) - x;
        cur += max(rr - ll, 0);
        cout << cur << '\n';
    }
}