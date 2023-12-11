#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 200005;

int bit[N], oper[N], n, q, st[N * 4];
pair <int, int> card[N], event[N];
vector <int> vals;

void update_st(int i, int l, int r, int p, int v) {
    if (l > p || r < p) return;
    st[i] = max(st[i], v);
    if (l == r) return;
    int m = (l + r) / 2;
    update_st(i * 2, l, m, p, v);
    update_st(i * 2 + 1, m + 1, r, p, v);
}

int query_st(int i, int l, int r, int lo, int hi) {
    if (l > hi || r < lo) return 0;
    if (l >= lo && r <= hi) return st[i];
    int m = (l + r) / 2;
    return max(query_st(i * 2, l, m, lo, hi),
    query_st(i * 2 + 1, m + 1, r, lo, hi));
}

int get_id(int x) {
    return lower_bound(vals.begin(),
    vals.end(), x) - vals.begin() + 1;
}

void update_bit(int i) {
    for (; i > 0; i -= i & -i) bit[i]++;
}

int query_bit(int i) {
    int res = 0;
    for (; i < N; i += i & -i) res += bit[i];
    return res;
}

int main() {
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif*/
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q; long long res = 0;
    for (int i = 1; i <= n; i++)
        cin >> card[i].fi >> card[i].se;
    for (int i = 1; i <= q; i++) {
        cin >> oper[i];
        vals.push_back(oper[i]);
    }
    sort(vals.begin(), vals.end());
    for (int i = 1; i <= q; i++) {
        oper[i] = get_id(oper[i]);
        update_st(1, 1, q, oper[i], i);
    }
    for (int i = 1, l, r; i <= n; i++) {
        tie(l, r) = minmax(card[i].fi, card[i].se);
        l = get_id(l); r = get_id(r) - 1;
        event[i] = {query_st(1, 1, q, l, r), i};
    }
    sort(event + 1, event + n + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= event[i].fi) update_bit(oper[j++]);
        int last = query_bit(get_id(max(
        card[event[i].se].se, card[event[i].se].se)));
        int flip = q - get_id((max(card[event[i].se].se,
        card[event[i].se].se))) + 1 - last;
        if (event[i].fi)
            flip ^= card[event[i].se].fi
            < card[event[i].se].se;
        if (flip & 1) res += card[event[i].se].se;
        else res += card[event[i].se].fi;
    }
    cout << res << '\n';
}