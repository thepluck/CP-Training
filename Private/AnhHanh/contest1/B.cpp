#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("tree-edge-color-queries.inp", "r", stdin);
    freopen("tree-edge-color-queries.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t, n; cin >> t >> n;
    map <pair <int, int>, int> cnt;
    vector <pair <int, int>> edge(n - 1);
    vector <int> col(n - 1);
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> edge[i].first >> edge[i].second >> col[i];
        bool x1 = cnt[make_pair(edge[i].first, col[i])] > 0;
        bool x2 = cnt[make_pair(edge[i].second, col[i])] > 0;
        if (x1 && x2) res--; if (!x1 && !x2) res++;
        cnt[make_pair(edge[i].first, col[i])]++;
        cnt[make_pair(edge[i].second, col[i])]++;
    }
    cout << res << ' ';
    int q; cin >> q;
    while (q--) {
        int i, c; cin >> i >> c; i--;
        bool x1 = cnt[make_pair(edge[i].first, col[i])] > 1;
        bool x2 = cnt[make_pair(edge[i].second, col[i])] > 1;
        if (x1 && x2) res++; if (!x1 && !x2) res--;
        cnt[make_pair(edge[i].first, col[i])]--;
        cnt[make_pair(edge[i].second, col[i])]--;
        col[i] = c;
        x1 = cnt[make_pair(edge[i].first, col[i])] > 0;
        x2 = cnt[make_pair(edge[i].second, col[i])] > 0;
        if (x1 && x2) res--; if (!x1 && !x2) res++;
        cnt[make_pair(edge[i].first, col[i])]++;
        cnt[make_pair(edge[i].second, col[i])]++;
        cout << res << ' ';
    }
}