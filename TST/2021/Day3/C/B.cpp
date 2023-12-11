#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;

const int N = 1e5 + 5;

vector <ii> grp[N];
vector <ii> seg[N * 4]; bool flag;
int rig[N], lo, hi, lb, rb;
multiset <int> sMax;
vector <pair <ii, int>> tmp;

void build(int i, int l, int r) {
    sMax.clear(); tmp.clear();
    for (int j = l; j <= r; j++) {
        sMax.insert(rig[j] = INT_MAX);
        for (auto ss : grp[j]) tmp.eb(ss, j);
    }
    sort(tmp.rbegin(), tmp.rend());
    for (auto ss : tmp) {
        if (rig[ss.se] > ss.fi.se) {
            sMax.erase(sMax.find(rig[ss.se]));
            sMax.insert(rig[ss.se] = ss.fi.se);
        }
        seg[i].eb(ss.fi.fi, *sMax.rbegin());
    }
    reverse(seg[i].begin(), seg[i].end());
    seg[i].eb(INT_MAX, INT_MAX);
    if (l != r) {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void query(int i, int l, int r) {
    if (!flag) return;
    if (l >= lo && r <= hi) {
        auto it = lower_bound(seg[i].begin(),
        seg[i].end(), ii(lb, -1));
        if (it->se > rb) flag = 0; return;
    }
    int m = (l + r) / 2;
    if (m >= lo) query(i * 2, l, m);
    if (m < hi) query(i * 2 + 1, m + 1, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> q >> m;
    while (m--) {
        int l, r, i; cin >> l >> r >> i;
        grp[i].emplace_back(l, r);
    }
    build(1, 1, n);
    while (q--) {
        cin >> lo >> hi >> lb >> rb;
        flag = 1; query(1, 1, n);
        if (flag) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}