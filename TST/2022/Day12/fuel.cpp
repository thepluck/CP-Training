#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int N = 3e5 + 5;
 
struct station {
    int x, a, b;
};
 
struct segtree {
    static const ll INF = LLONG_MAX;
 
    vector <ll> val, tag;
    int lo, hi, n; ll v;
 
    segtree(int n): n(n) {
        val.resize(n * 4 + 10);
        tag.resize(n * 4 + 10);
    }
 
    void push_tag(int i, ll tg) {
        val[i] += tg; tag[i] += tg;
    }
 
    void push_down(int i) {
        push_tag(i * 2, tag[i]);
        push_tag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }
 
    void update(int i, int l, int r) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi)
            return push_tag(i, v);
        push_down(i);
        int m = (l + r) / 2;
        update(i * 2, l, m);
        update(i * 2 + 1, m + 1, r);
        val[i] = min(val[i * 2],
        val[i * 2 + 1]);
    }
 
    void query(int i, int l, int r) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi) {
            v = min(v, val[i]); return;
        }
        push_down(i);
        int m = (l + r) / 2;
        query(i * 2, l, m);
        query(i * 2 + 1, m + 1, r);
    }
 
    void update(int lo, int hi, ll v) {
        if (lo > hi) return;
        this->lo = lo; this->hi = hi;
        this->v = v; update(1, 0, n);
    }
 
    ll query(int lo, int hi) {
        if (lo > hi) return INF;
        this->lo = lo; this->hi = hi;
        v = INF; query(1, 0, n);
        return v;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    vector <station> ff(n);
    vector <int> nxt(n + 1);
    segtree st(n);
    for (station &s : ff)
        cin >> s.x >> s.a >> s.b;
    ff.push_back({d, 0, d});
    sort(ff.begin(), ff.end(),
    [](station p, station q) {
        return p.x < q.x;
    });
    int j = 0;
    for (int i = 0; i <= n; i++) {
        while (j < n &&
        ff[j].x == ff[i].x) j++;
        nxt[i] = j;
    }
    vector <int> od(n + 1);
    iota(od.begin(), od.end(), 0);
    sort(od.begin(), od.end(),
    [&](int i, int j) {
        return ff[i].b < ff[j].b;
    });
    j = 0;
    for (int i = 0; i <= n; i++) {
        st.update(i, i, -ll(ff[i].x));
        st.update(nxt[i], n, ll(ff[i].a));
    }
    for (int i = 0; i <= n; i++) {
        st.update(0, n, ll(ff[od[i]].b)
        - (i ? ff[od[i - 1]].b : 0));
        while (j < i &&
        ff[od[j]].b < ff[od[i]].b) {
            st.update(nxt[od[j]], n,
            -ll(ff[od[j]].a)); j++;
        }
        if (st.val[1] >= 0) {
            cout << ff[od[i]].b
            - st.val[1]; return 0;
        }
    }
}