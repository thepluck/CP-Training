#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct event {int time, dura;};

const int N = 1e6 + 5;
const ll INF = -1e16;

int lo, hi, dura[N]; event ev[N];
ll val[N * 4], tag[N * 4], res, BIT[N];

void build(int i, int l, int r) {
    val[i] = r;
    if (l < r) {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void pushTag(int i, ll v) {
    val[i] += v; tag[i] += v;
}

void pushDown(int i) {
    pushTag(i * 2, tag[i]);
    pushTag(i * 2 + 1, tag[i]);
    tag[i] = 0;
}

void update(int i, int l, int r, ll v) {
    if (l >= lo && r <= hi)
        return pushTag(i, v);
    pushDown(i); int m = (l + r) / 2;
    if (m >= lo) update(i * 2, l, m, v);
    if (m < hi) update(i * 2 + 1, m + 1, r, v);
    val[i] = max(val[i * 2], val[i * 2 + 1]);
}

void update(int l, int r, ll v) {
    lo = l; hi = r; update(1, 1, N - 1, v);
}

void query(int i, int l, int r) {
    if (l >= lo && r <= hi)
        return void(res = max(res, val[i]));
    pushDown(i); int m = (l + r) / 2;
    if (m >= lo) query(i * 2, l, m);
    if (m < hi) query(i * 2 + 1, m + 1, r);
}

ll query(int l, int r) {
    lo = l; hi = r; res = -1e18;
    query(1, 1, N - 1); return res;
}

pair <int, ll> getGre(ll v, int p) {
    if (query(1, p) < v) return {N, 0};
    int l = 1, r = N - 1, i = 1;
    while (l < r) {
        pushDown(i);
        int m = (l + r) / 2;
        if (val[i * 2] >= v) {
            r = m; i = i * 2;
        }
        else {
            l = m + 1; i = i * 2 + 1;
        }
    }
    return {l, val[i]};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q; build(1, 1, N - 1);
    for (int i = 1; i <= q; i++) {
        char cmd; cin >> cmd;
        if (cmd == '+') {
            cin >> ev[i].time >> ev[i].dura;
            dura[ev[i].time] = ev[i].dura;
            update(ev[i].time + 1, N - 1, -ev[i].dura);
        }
        else if (cmd == '-') {
            int j; cin >> j;
            dura[ev[j].time] = 0;
            update(ev[j].time + 1, N - 1, ev[j].dura);
        }
        else {
            int tim; cin >> tim;
            cout << query(1, tim) -
            query(tim, tim) + dura[tim] << '\n';
        }
    }
}