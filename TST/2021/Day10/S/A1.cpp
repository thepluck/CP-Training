#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class kinetic_tournament {
private:
    static const ll INF = LLONG_MAX;

    struct line {
        ll k, m;

        line(ll k = 0, ll m = 0): k(k), m(m) {}

        ll operator () (const ll &x) const {
            return k * x + m;
        }
    };

    int n; ll temp;
    vector <line> tree;
    vector <ll> melt;

    bool compare(const line &l1, const line &l2) {
        ll y1 = l1(temp), y2 = l2(temp);
        return y1 != y2 ? y1 < y2 : l1.k < l2.k;
    }

    ll intersect(const line &l1, const line &l2) {
        if (l1.k > l2.k) {
            ll delta = l2(temp) - l1(temp);
            ll slope = l1.k - l2.k;
            ll mint = temp + (delta - 1) / slope + 1;
            return mint > temp ? mint : INF;
        }
        return INF;
    }

    void recompute(int i, int lo, int hi) {
        if (lo == hi || melt[i] > temp) return;
        int mi = (lo + hi) / 2;
        recompute(i * 2, lo, mi);
        recompute(i * 2 + 1, mi + 1, hi);
        if (compare(tree[i * 2], tree[i * 2 + 1]))
            tree[i] = tree[i * 2];
        else tree[i] = tree[i * 2 + 1];
        melt[i] = min({melt[i * 2], melt[i * 2 + 1],
        intersect(tree[i * 2], tree[i * 2 + 1])});
    }

    void update(int i, int lo, int hi, int p, ll k, ll m) {
        if (lo > p || hi < p) return;
        if (lo == hi) return void(tree[i] = {k, m});
        int mi = (lo + hi) / 2;
        update(i * 2, lo, mi, p, k, m);
        update(i * 2 + 1, mi + 1, hi, p, k, m);
        melt[i] = 0; recompute(i, lo, hi);
    }

    ll query(int i, int lo, int hi, int l, int r) {
        if (lo > r || hi < l) return INF;
        if (lo >= l && hi <= r) return tree[i](temp);
        int mi = (lo + hi) / 2;
        return min(query(i * 2, lo, mi, l, r),
        query(i * 2 + 1, mi + 1, hi, l, r));
    }

public:
    kinetic_tournament(int n): n(n), temp(0) {
        tree.resize(4 * n);
        melt.resize(4 * n);
    }

    void update(int p, ll k, ll m) {
        update(1, 1, n, p, k, m);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void heaten(ll temp) {
        this->temp = temp;
        recompute(1, 1, n);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    kinetic_tournament kt(n);
    for (int i = 1; i <= n; i++) {
        ll k, m; cin >> k >> m;
        kt.update(i, -k, -m);
    }
    int q; cin >> q;
    while (q--) {
        char cmd; cin >> cmd;
        if (cmd == '+') {
            int i; ll k, m, temp;
            cin >> temp >> i >> k >> m;
            kt.heaten(temp);
            kt.update(i, -k, -m);
        }
        else {
            ll temp; int l, r;
            cin >> temp >> l >> r;
            kt.heaten(temp);
            cout << -kt.query(l, r) << '\n';
        }
    }
}