//https://csacademy.com/contest/archive/task/dogs/statement/
#include <bits/stdc++.h>
using namespace std;

template <class T, class f>
struct sparse_table {
    vector <vector <int>> spt;

    sparse_table() {}

    sparse_table(const vector <int> &a) {
        int n = a.size(), lg = __lg(n);
        spt.resize(lg + 1, vector <T> (n));
        for (int i = 0; i < n; i++)
            spt[0][i] = a[i];
        for (int k = 1; k <= lg; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                spt[k][i] = f()(spt[k - 1][i],
                spt[k - 1][i + (1 << (k - 1))]);
    }

    T query(int l, int r) {
        int k = __lg(r - l);
        return f()(spt[k][l], spt[k][r - (1 << k)]);
    }
};

template <class T>
struct maximum {
    T operator () (const T &x, const T &y) const {
        return x > y ? x : y;
    }
};

using ii = pair <int, int>;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; vector <int> a(n);
    for (int &x : a) cin >> x;
    sparse_table<int, maximum <int>> rmq(a);
    int q; cin >> q; vector <ii> d(q);
    for (ii &p : d)
        cin >> p.first >> p.second;
    vector <int> o(q);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(),
    [&](const int &x, const int &y) {
        int l, r, u, v;
        tie(l, r) = d[x]; tie(u, v) = d[y];
        l--; u--;
        if (l == u && r == v) return false;
        if (l <= u && r >= v) return false;
        if (l >= u && r <= v) return true;
        if (l <= u) {
            if (r >= u) swap(r, u);
            return rmq.query(l, r) < rmq.query(u, v);
        }
        else {
            if (l <= v) swap(l, v);
            return rmq.query(l, r) < rmq.query(u, v);
        }
    });
    for (int x : o) cout << x + 1 << ' ';
}